# Fume Absorber

![banner](https://cdn.hackclub.com/01a11491-1ef7-720c-b3e1-17ae2b50922e/Schematic_Fume-Absorber_2026-10-07.png)

## Overview

A premium Fume absorber for your work desk. It absorber all harmful chemical and fume from air and filter it and release clean air back into environment. It has 3-stage filtration system with -

1. Pre-Filter - Dust Filter
2. HEPA Filter
3. Activated Carbon Filter

## Circuit structure

```
USB-C → MRB045 → Witty Fox 11.1V Pack → Fuse 3A → ON/OFF Switch → Dual Fan (12V, parallel)
                                                                → LM2596 5V → ESP32 DevKit (VIN) → OLED
                                                                → 30K/10K divider → ESP32 IO34 (battery level)
```

## Circuit Diagram

![image](https://cdn.hackclub.com/01a11490-c32c-7656-a82a-5bedc38ba6c5/Schematic_Fume-Absorber_2026-10-07.png)
> Don't judge its my first work in Easy EDA :)
## Key Features -

- Dual-Fan system
- 3-stage filtration system
- 2*18650 battery for long runtime
- Chagrning option for longer lifetime
- Oled Display for battery percentage

## Credit - @shabaz

I used @shabaz 's [blog](https://community.element14.com/technologies/open-source-hardware/b/blog/posts/building-a-low-cost-solder-fume-extractor-part-1) from 2017 to learn how fume absorbers work, after that all the work is my original.