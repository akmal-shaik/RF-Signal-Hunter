# RF Signal Hunter

A handheld device for detecting and displaying relative changes in nearby RF activity.

The project combines an analogue RF envelope detector with an ESP32, signal processing, data logging and a future handheld interface.

> This is a relative activity detector, not a spectrum analyser, frequency counter or calibrated RF power meter.

## Current Status

The ESP32 development environment and serial communication have been verified.

Current work:

* Characterising the ESP32 ADC
* Developing the analogue detector
* Measuring detector noise and response
* Preparing for breadboard integration

## Planned Signal Path

```text
RF pickup → envelope detector → filtering/protection
          → ESP32 ADC → signal processing → display/serial output
```

## Technology

* ESP32 DEVKIT V1
* C++ with the Arduino ESP32 framework
* PlatformIO
* Analogue RF electronics
* Python for measurement analysis
* KiCad for the future PCB

## Repository

```text
docs/       Short design overview
firmware/   ESP32 PlatformIO project
results/    Useful experimental evidence
```

## Build Firmware

Install PlatformIO, then run:

```bash
cd firmware
pio run
```

Upload to the ESP32:

```bash
pio run --target upload
```

## Progress

* [x] Project concept defined
* [x] ESP32 firmware environment configured
* [x] Firmware upload verified
* [x] Serial communication verified
* [ ] ESP32 ADC characterised
* [ ] RF detector breadboard prototype
* [ ] Integrated handheld prototype
* [ ] PCB and enclosure

More technical detail is available in [`docs/design.md`](docs/design.md).
