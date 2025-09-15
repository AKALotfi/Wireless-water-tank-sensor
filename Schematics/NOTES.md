# IMPORTANT
## Electrical issues:
In the schematic, the HC-12 is directly connected to the Arduino Nano.
For safety, it is recommended to as **Voltage Divider** on the Arduino line to step down from 5V to -3.3V.
Voltage divider = 1k + 2k.
## Connections:
- HC-12 TX -> Arduino RX (D2)
- HC-12 RX -> Arduino TX (D3 + Voltage Divider)

- ADD 2 resistors (220 ome) to the LEDs
