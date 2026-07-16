# TEST-ESP-001 — ESP32 Serial Bring-Up

**Project version:** v0.3 draft  
**Board under test:** ESP32-A  
**Board model:** ESP32 DEVKIT V1  
**Firmware version:** 0.3.0-dev
**Test date:** 16/07/2026
**Serial port:** COM6

## Objective

Verify that the firmware toolchain, USB upload interface, ESP32 execution and serial communication operate correctly before peripheral testing begins.

## Test Setup

- ESP32-A
- USB data cable
- Computer USB port
- VS Code
- PlatformIO
- Arduino framework
- Serial baud rate: 115200
- No external circuit connected

## Results

| Check | Result | Observation |
|---|---|---|
| Visual inspection | PASS | |
| USB power | PASS | |
| Serial port detected | PASS | |
| Firmware build | PASS | |
| Firmware upload | PASS | |
| Boot message received | PASS | |
| Ten sequential heartbeats | PASS | |
| Approximate one-second timing | PASS | |
| Reset behaviour | PASS | |
| Reconnection behaviour | PASS | |

## Overall Result

**PASS**

## Observations

ESP32-A appeared as COM6. Firmware built and uploaded successfully. Thirteen sequential heartbeat messages were captured, with each adjacent timestamp differing by 1000 ms. Resetting and reconnecting the board restored the boot header and heartbeat output. No unexpected resets, corrupted output or communication anomalies were observed.

## Conclusion

The ESP32-A board and the development toolchain are suitable for subsequent ADC characterisation.