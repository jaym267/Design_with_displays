# Design with Displays – Week 4: RGB Mood Light

For week 4 of Hack Club Half-Life, I designed a small RGB mood light board. A Seeed XIAO RP2040 drives a 5 mm RGB LED. A push button cycles through 7 colours, and a slide potentiometer sets the brightness from off to full.

## What I did
 <img width="1517" height="840" alt="Screenshot 2026-11-01 140233" src="https://github.com/user-attachments/assets/d1f69bb8-9c00-4c97-ab97-6c46c526d714" />
### 1. Planned the project
I followed the Tier 1 "5 mm LEDs" guide and picked the RGB mood light as my build: one common-cathode RGB LED, a slide pot, and a button, all controlled by a XIAO RP2040.

### 2. Drew the schematic in KiCad
- I created a new KiCad project and placed the XIAO RP2040, an RGB LED (LED_RKGB), three resistors, a 10 kΩ slide pot, a push button, and the power symbols.
- I picked the resistor values from the LED's forward voltage: 270 Ω for red (about 2.0 V) and 100 Ω for green and blue (about 3.0 V), all running from a 3.3 V pin.
- I wired each colour through its resistor to the LED, the LED's common cathode to GND, the pot between 3V3 and GND, and the button to GND.
- I used net labels to connect the parts to the XIAO pins: LED_RED → D6, LED_GREEN → D7, LED_BLUE → D8, SLIDER → D0/A0, BUTTON → D1.

### 3. Passed the Electrical Rules Check
- I added PWR_FLAGs on the GND and +3V3 nets so KiCad knew where power comes from.
- I put no-connect flags on all 13 unused XIAO pins.
- The ERC finished with 0 errors.

### 4. Assigned footprints
- I used through-hole parts so they're easy to hand-solder: a 5 mm 4-pin RGB LED, axial resistors, a Bourns PTA4543 slide pot, and a 6 mm tactile switch.
- I fixed a missing-footprint problem by adding Seeed's OPL XIAO footprint library to my global KiCad libraries.

### 5. Laid out the PCB
- I made a 66 × 35.5 mm two-layer board.
- I placed the XIAO with its USB-C port at the top edge, the button beside it, the resistors lined up with the LED legs, and the slide pot along the bottom edge.
- I arranged the parts so none of the signal traces cross.

### 6. Routed the board
- I used 0.25 mm traces for the signals and a 0.5 mm trace for 3.3 V power.
- I filled the whole back layer with GND copper and connected the XIAO's GND pad to it with a via.

### 7. Passed the Design Rules Check
- I fixed four annular-ring errors on the LED by shrinking its holes from 0.9 mm to 0.8 mm.
- I fixed one unconnected-item error by adding a trace between the button's two "pad 1" legs.
- The DRC finished with 0 errors.

### 8. Wrote the firmware
- I wrote an Arduino sketch for the Seeed XIAO RP2040 using the arduino-pico core.
- Each button press steps through 7 colours, and the slider sets brightness with PWM.
- It compiles successfully, and I'll flash it at build week.
-
<img width="1834" height="786" alt="Screenshot 2026-11-01 142151" src="https://github.com/user-attachments/assets/9ba4a27a-b3c2-44e1-a819-9a8da0885325" />

### 9. Pushed everything to GitHub
This repo holds the KiCad project (`rgb-light/`) and the firmware (`rgb_light_firmware/`).

## Bill of Materials

| Qty | Part | Part Number | Where to buy | Approx. price |
|---|---|---|---|---|
| 1 | Seeed Studio XIAO RP2040 | 102010428 | [DigiKey](https://www.digikey.com/en/products/detail/seeed-technology-co-ltd/102010428/14672129) | $4.68 |
| 1 | 5 mm RGB LED, diffused, common cathode | SparkFun COM-09264 | [DigiKey](https://www.digikey.com/en/products/detail/sparkfun-electronics/09264/9770728) | $2.30 |
| 2 | 100 Ω resistor, 1/4 W, through-hole | Stackpole CF14JT100R | [DigiKey](https://www.digikey.com/en/products/detail/stackpole-electronics-inc/CF14JT100R/1830327) | $0.20 |
| 1 | 270 Ω resistor, 1/4 W, through-hole | Stackpole CF14JT270R | [DigiKey](https://www.digikey.com/en/products/result?keywords=CF14JT270R) | $0.10 |
| 1 | Slide potentiometer, 10 kΩ linear, 45 mm | Bourns PTA4543-2015DPB103 | [DigiKey](https://www.digikey.com/en/products/detail/bourns-inc/PTA4543-2015DPB103/3534245) | $1.76 |
| 1 | 6 × 6 mm tactile push button, through-hole | Omron B3F-1000 | [DigiKey](https://www.digikey.com/en/products/detail/omron-electronics-inc-emc-div/B3F-1000/33150) | $0.27 |
| 5 | Custom 2-layer PCB, 66 × 35.5 mm | rgb-light gerbers | [JLCPCB](https://jlcpcb.com) | $2.00 |
| | | | **Total (before shipping)** | **≈ $11.31** |

## Tools
- KiCad 10 for the schematic and PCB
- Arduino IDE with the arduino-pico core for the firmware
- I used Claude (AI) as a step-by-step guide. It also generated the net labels, part placement, and trace routing in the KiCad files, and I reviewed and verified them with ERC and DRC.

## Time spent

8 hours
