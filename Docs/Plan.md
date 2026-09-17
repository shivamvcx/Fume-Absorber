## Plan -

> I have designed my project and added this project on my website and saved it as a demo url.

My plan is inspired by [this blog](https://community.element14.com/technologies/open-source-hardware/b/blog/posts/building-a-low-cost-solder-fume-extractor-part-1).

## Filter Structure

` Dust Filter ---> HEPA Filter ---> Activated Carbon Filter ---> Dual Fan sucking air ---> Clean air exit `

## Circuit structure

```
USB-C → TP4056 → 18650 cells (1S2P) → Power Button → #1 MT3608 12v → Dual Fan
                                                   → #2 MT3608 5v → ESP32 → OLED
```

## Structure

- I'll seal fans side with MDF sheets so all bad fumes are forced to pass through all 3 filters

## Other

- I have succcesfully made whole model in CAD with proper Type-C port
- Reason for batteries to be in parallel because TP4056 cant charge two batteries in series due to low voltage output