# ESP32 ADC Characterisation

GPIO34 was tested using a potentiometer as a variable DC voltage source and a multimeter as the reference.

| Measured voltage | ADC reading |
|---|---:|
| ~0.80 V | ~830 |
| 1.510 V | ~1715 |
| 2.555 V | ~3020 |

At a fixed input of approximately 1.5 V, most readings remained between 1702 and 1714, with occasional values between 1693 and 1723.

The ADC response was monotonic and sufficiently stable for use in the RF detector prototype.