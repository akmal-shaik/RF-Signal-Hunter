# RF Signal Hunter

RF Signal Hunter is a handheld relative RF activity detector designed to demonstrate the complete engineering lifecycle of an embedded hardware product.

The instrument will use a broadband analogue detector front end to convert nearby RF activity into a measurable low-frequency voltage. An ESP32 will sample, process and display this relative activity level.

The device is intended as an educational and portfolio instrument for observing changes in local RF activity. It is not a spectrum analyser, calibrated RF power meter, frequency counter or transmitter identification device.

## Current Status
v0.3 Breadboard Prototype — in progress

Validated:
- v0.1 requirements baseline
- v0.2 system architecture
- TEST-ESP-001 ESP32 serial bring-up

Current work:
- ESP32 ADC characterisation

## Repository Navigation
- [Requirements](docs/requirements.md)
- [System Architecture](docs/system_architecture.md)
- [Design Decisions](docs/design_decisions_log.md)
- [Engineering Log](docs/engineering_log.md)
- [Release Notes](RELEASE_NOTES.md)
- [Firmware](firmware/)
- [Test Results](results/)