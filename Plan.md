## Plan -

> I have designed my project and added this project on my website and saved it as a demo url.

My plan is inspired by [this blog](https://community.element14.com/technologies/open-source-hardware/b/blog/posts/building-a-low-cost-solder-fume-extractor-part-1).

## Filter Structure

` Dust Filter ---> HEPA Filter ---> Activated Carbon Filter ---> Dual Fan sucking air ---> Clean air exit `

## Power Structure

```
TP4056 (Charger)
   ↓
2×18650 (Batteries)
   ↓
On/Off Switch
   ├─→ MT3608 (set to 12V) → Fans (+12V, GND)
   │
   └─→ MT3608 (set to 5V) → ESP32-WROOM (+5V, GND)
```