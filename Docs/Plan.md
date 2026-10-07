## Plan -

> I have designed my project and added this project on my website.

My plan is inspired by [this blog](https://community.element14.com/technologies/open-source-hardware/b/blog/posts/building-a-low-cost-solder-fume-extractor-part-1).

## Filter Structure

` Dust Filter ---> HEPA Filter ---> Activated Carbon Filter ---> Dual Fan sucking air ---> Clean air exit `

## Circuit structure

```
USB-C → MRB045 → Witty Fox 11.1V Pack → Fuse 3A → ON/OFF Switch → Dual Fan (12V, parallel)
                                                                → LM2596 5V → ESP32 DevKit (VIN) → OLED
                                                                → 30K/10K divider → ESP32 IO34 (battery level)
```

## Circuit Diagram

![image](https://cdn.hackclub.com/01a11490-c32c-7656-a82a-5bedc38ba6c5/Schematic_Fume-Absorber_2026-10-07.png)

## Structure

- I'll seal fans side with MDF sheets so all bad fumes are forced to pass through all 3 filters

## Other

- I have succcesfully made whole model in CAD with proper Type-C port
- Reason for batteries to be in parallel because TP4056 cant charge two batteries in series due to low voltage output