// IMPORTANT - FIRMWARE IS NOT TESTED YET (obviously), i'll only be able to do it after getting the components.
// - Must do calibration with ESP32 disconnected with buck converter
//- 0% is placed at 3.3V per cell to stay clear of the packs portection cutoff

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

constexpr uint8_t PIN_SDA    = 21;
constexpr uint8_t PIN_SCL    = 22;
constexpr uint8_t PIN_VSENSE = 34;

constexpr uint8_t OLED_ADDR   = 0x3C;
constexpr uint8_t OLED_WIDTH  = 128;
constexpr uint8_t OLED_HEIGHT = 32;

constexpr float DIVIDER_R1 = 30000.0f;
constexpr float DIVIDER_R2 = 10000.0f;
constexpr float CAL_FACTOR = 1.00f;
constexpr int   CELLS      = 3;

constexpr int      ADC_SAMPLES        = 32;
constexpr uint32_t UPDATE_INTERVAL_MS = 500;
constexpr float    SMOOTHING          = 0.15f;
constexpr int      LOW_BATTERY_PCT    = 10;

struct CurvePoint {
  float cellVolts;
  int percent;
};

constexpr CurvePoint CURVE[] = {
  {4.20f, 100}, {4.10f, 90}, {4.00f, 80}, {3.92f, 70}, {3.86f, 60}, {3.82f, 50},
  {3.78f, 40},  {3.74f, 30}, {3.70f, 20}, {3.60f, 10}, {3.30f, 0},
};
constexpr size_t CURVE_SIZE = sizeof(CURVE) / sizeof(CURVE[0]);

Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, -1);
float packVolts = 0.0f;

float readPackVolts() {
  uint32_t totalMv = 0;
  for (int i = 0; i < ADC_SAMPLES; i++) {
    totalMv += analogReadMilliVolts(PIN_VSENSE);
    delayMicroseconds(200);
  }
  const float pinVolts = totalMv / (float)ADC_SAMPLES / 1000.0f;
  return pinVolts * (DIVIDER_R1 + DIVIDER_R2) / DIVIDER_R2 * CAL_FACTOR;
}

int percentFromVolts(float packV) {
  const float cell = packV / CELLS;
  if (cell >= CURVE[0].cellVolts) return 100;

  for (size_t i = 1; i < CURVE_SIZE; i++) {
    if (cell >= CURVE[i].cellVolts) {
      const CurvePoint& hi = CURVE[i - 1];
      const CurvePoint& lo = CURVE[i];
      const float t = (cell - lo.cellVolts) / (hi.cellVolts - lo.cellVolts);
      return lroundf(lo.percent + t * (hi.percent - lo.percent));
    }
  }
  return 0;
}

void render(int percent) {
  const bool hideFill = percent <= LOW_BATTERY_PCT && (millis() / 500) % 2 == 0;

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(3);
  display.setCursor(0, 4);
  display.print(percent);
  display.print('%');

  display.drawRect(84, 4, 38, 24, SSD1306_WHITE);
  display.fillRect(122, 11, 4, 10, SSD1306_WHITE);
  if (!hideFill) {
    display.fillRect(86, 6, 34 * percent / 100, 20, SSD1306_WHITE);
  }
  display.display();
}

void setup() {
  Serial.begin(115200);

  analogReadResolution(12);
  analogSetPinAttenuation(PIN_VSENSE, ADC_11db);

  Wire.begin(PIN_SDA, PIN_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED not found");
    while (true) delay(1000);
  }

  packVolts = readPackVolts();
}

void loop() {
  static uint32_t lastUpdate = 0;
  if (millis() - lastUpdate < UPDATE_INTERVAL_MS) return;
  lastUpdate = millis();

  packVolts += SMOOTHING * (readPackVolts() - packVolts);

  const int percent = percentFromVolts(packVolts);
  render(percent);

  Serial.printf("%.2f V  %d%%\n", packVolts, percent);
}