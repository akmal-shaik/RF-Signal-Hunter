# RF Signal Hunter Firmware

This directory contains the embedded firmware for the RF Signal Hunter.

The firmware runs on an ESP32 development board and is responsible for:

- Acquiring analogue measurements from the RF detector
- Processing raw ADC data
- Producing a relative RF activity value
- Driving the user interface
- Transmitting measurement data over USB serial

## Development Environment

- Board: ESP32 DEVKIT V1
- Framework: Arduino for ESP32
- Build system: PlatformIO
- Editor: Visual Studio Code
- Serial baud rate: 115200

The build configuration is stored in `platformio.ini`.

## Directory Structure

```text
firmware/
├── platformio.ini
├── README.md
└── src/
    └── main.cpp