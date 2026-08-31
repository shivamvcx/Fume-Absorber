## Plan -

> I have designed my project and added this project on my website and saved it as a demo url.

My plan is inspired by [this blog](https://community.element14.com/technologies/open-source-hardware/b/blog/posts/building-a-low-cost-solder-fume-extractor-part-1).

## Filter Structure

` Dust Filter ---> HEPA Filter ---> Activated Carbon Filter ---> Dual Fan sucking air ---> Clean air exit `

## Power Structure

` TP4056 -> 2*18650 -> On/Off Switch -> 1st MT3608 set to 12v -> Fans +ve and -ve
                            ↓
                            2nd MT3608 set to 5v -> ESP32-WROOM