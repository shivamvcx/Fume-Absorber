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

### Further plan -

After receving fund, i will start physically wiring each components and CAD work for fan holder, filter holder etc.

> I havent started CAD work just for that i need exact measurment of components thats why i also added a good quality verneir caliper, mine is just a cheap $2 one which broke down recently.