## Plan -

> I have designed my project and added this project on my website and saved it as a demo url.

My plan is inspired by [this blog](https://community.element14.com/technologies/open-source-hardware/b/blog/posts/building-a-low-cost-solder-fume-extractor-part-1).

## Filter Structure

` Dust Filter ---> HEPA Filter ---> Activated Carbon Filter ---> Dual Fan sucking air ---> Clean air exit `

## Complete System Structure

```
USB-C → TP4056 → 18650 cells (1S2P) → Power Button → MT3608 #1 → Fan circuit (MOSFET + fan)
                                                   → MT3608 #2 → ESP32 → OLED
                                                                │
                                                                └→ Encoder
```