# RF Signal Hunter — System Architecture

**Project release:** v0.2  
**Status:** Approved at system-architecture level

Detailed subsystem implementations remain subject to experimental validation and are not yet frozen.

## 1. Architecture Objective

The RF Signal Hunter shall convert nearby broadband RF activity into a stable relative measurement that can be displayed and recorded.

The architecture separates the instrument into independently testable subsystems so that each section can be validated before complete system integration.

## 2. System Block Diagram

```text
┌──────────────────────┐
│ Nearby RF activity   │
│ Wi-Fi / Bluetooth /  │
│ mobile devices etc.  │
└──────────┬───────────┘
           │ electromagnetic energy
           ▼
┌──────────────────────┐
│ Antenna / RF pickup  │
└──────────┬───────────┘
           │ small RF voltage
           ▼
┌──────────────────────┐
│ RF detector          │
│ Rectification /      │
│ envelope detection   │
└──────────┬───────────┘
           │ low-frequency voltage
           ▼
┌──────────────────────┐
│ Analogue conditioning│
│ Filtering            │
│ Scaling              │
│ ADC protection       │
└──────────┬───────────┘
           │ safe ADC voltage
           ▼
┌──────────────────────┐
│ ESP32 ADC            │
│ Sampling             │
└──────────┬───────────┘
           │ raw digital samples
           ▼
┌──────────────────────┐
│ Digital processing   │
│ Baseline estimation  │
│ Smoothing            │
│ Relative scaling     │
└───────┬────────┬─────┘
        │        │
        ▼        ▼
┌────────────┐ ┌──────────────┐
│ User       │ │ USB serial / │
│ display    │ │ data logging │
└────────────┘ └──────┬───────┘
                      ▼
               ┌──────────────┐
               │ Python data  │
               │ analysis     │
               └──────────────┘

```

## 3. Subsystem Responsibilities

| ID | Subsystem | Input | Output | Responsibility |
|---|---|---|---|---|
| SUB-01 | RF pickup | Electromagnetic RF energy | Small RF voltage/current | Couple nearby RF energy into the detector |
| SUB-02 | RF detector | RF signal | Slowly varying analogue voltage | Convert RF amplitude into a measurable envelope |
| SUB-03 | Analogue conditioning | Detector voltage | Filtered and protected voltage | Reduce noise and make the signal safe for the ADC |
| SUB-04 | ADC acquisition | Analogue voltage | Digital samples | Measure the conditioned detector output |
| SUB-05 | Digital processing | Raw ADC samples | Relative activity value | Reduce noise and calculate a useful indication |
| SUB-06 | User interface | Relative activity value | Visual indication | Communicate low-to-high activity clearly |
| SUB-07 | Data interface | Samples and processed values | Serial data stream | Send measurements to a computer |
| SUB-08 | Python analysis | Recorded serial data | Plots and statistics | Characterise noise, response and repeatability |
| SUB-09 | Power system | External or stored energy | Regulated supply rails | Power the analogue and digital circuitry safely |
| SUB-10 | Mechanical system | Completed electronics | Handheld instrument | Secure and protect the final hardware |

## 4. Preliminary Interface Definitions

### IF-01 — RF Pickup to Detector

- Signal type: high-frequency analogue
- Expected amplitude: initially unknown and potentially very small
- Requirement: connection must have low parasitic capacitance and short physical routing
- Validation: compare detector response with and without the pickup element

### IF-02 — Detector to Analogue Conditioning

- Signal type: low-frequency analogue voltage
- Expected voltage range: TBD experimentally
- Requirement: conditioning must not overload the detector
- Validation: measure detector output directly before and after conditioning

### IF-03 — Analogue Conditioning to ESP32 ADC

- Signal type: protected analogue voltage
- Required voltage range: within the validated ESP32 ADC input range
- Requirement: no negative voltage or overvoltage shall reach the ADC
- Validation: use a multimeter and controlled DC input before connecting the ESP32

### IF-04 — ESP32 to Display

- Signal type: digital
- Protocol: TBD after available display hardware is confirmed
- Requirement: display communication shall not significantly disturb analogue measurements
- Validation: compare analogue noise with the display active and inactive

### IF-05 — ESP32 to Computer

- Signal type: USB serial data
- Data content: timestamp, raw ADC value and processed activity value
- Validation: record data into a file and inspect for missing or malformed samples

## 5. Available Hardware Inventory

| Item | Exact model/value | Quantity | Intended possible role | Confirmed working? |
|---|---|---:|---|---|
| ESP32 development board | ESP32 DEVKIT V1 | 3 | Processing, ADC and serial output | ESP32-A verified by TEST-ESP-001; remaining boards untested |
| Breadboard | Full-size solderless breadboard | 1 | Prototype construction | Yes |
| Multimeter | TESMEN TM-510 | 1 | Voltage, resistance and continuity testing | Yes |
| Display module | None currently available | 0 | Final user interface | N/A |
| Diodes | BAT46 Schottky diode | 2 | RF detector experiments | Not yet tested |
| Capacitors | Assorted, 100 pF to 10 µF | 2 of each value | Filtering and decoupling | Not individually tested |
| Resistors | Assorted, 10 Ω to 1 MΩ | 120 total | Biasing, filtering and protection | Not individually tested |
| Antenna/wire | Jumper wire / hook-up wire | Assorted | RF pickup experiments | Yes |
| Power source | Laptop USB through micro-USB cable | 1 | Prototype power | Verified with ESP32-A by TEST-ESP-001 |

## 6. Architecture Constraints

* The RF carrier shall not be sampled directly by the ESP32 ADC. The analogue front end shall first convert received RF energy into a low-frequency envelope.
* The ADC interface shall prevent negative voltage and overvoltage from reaching the ESP32.
* ADC1 shall be preferred so that future Wi-Fi operation does not conflict with ADC acquisition.
* Raw ADC measurements shall remain available over USB serial for validation and offline analysis.
* Analogue, firmware and interface subsystems shall be validated independently before complete-system integration.
* No PCB shall be released until the major analogue and digital subsystems have passed documented breadboard tests.
* Display and power-system activity shall not be allowed to invalidate analogue measurements through excessive noise or interference.

## 7. Planned Validation Order

1. Verify the ESP32 development board and serial communication.
2. Characterise the ESP32 ADC using controlled DC voltages.
3. Build and test the RF detector independently.
4. Characterise detector baseline noise.
5. Test detector response to controlled RF activity.
6. Add analogue filtering and protection.
7. Validate the complete analogue-to-ADC interface.
8. Develop digital smoothing using recorded data.
9. Add the display and test for electrical interference.
10. Integrate the complete breadboard prototype.