# RF Signal Hunter — Requirements Specification

**Project release:** v0.1  
**Status:** Approved Baseline 
**Instrument type:** Handheld relative RF activity detector

---

## 1. Project Objective

The objective is to design, validate and document a handheld instrument capable of detecting and displaying relative changes in nearby RF activity.

The project will demonstrate:

- Analogue detector design
- RF measurement fundamentals
- Embedded firmware development
- Signal processing
- Experimental validation
- PCB design
- Hardware assembly
- Mechanical enclosure design
- Professional engineering documentation

---

## 2. Functional Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-F-001 | The device shall detect relative changes in nearby RF activity. | Must | Compare readings with an RF source active and inactive under controlled conditions. |
| REQ-F-002 | The device shall convert the analogue detector output into a digital measurement using an ESP32. | Must | Apply known DC voltages to the ADC input and compare measured values. |
| REQ-F-003 | The device shall display the relative RF activity level to the user. | Must | Confirm that the displayed indication changes in response to controlled detector input changes. |
| REQ-F-004 | The device shall provide a clear indication of increasing and decreasing RF activity. | Must | Move a repeatable RF source between controlled positions and observe the displayed response. |
| REQ-F-005 | The device shall support the recording or transmission of measurement data for analysis. | Should | Capture a sequence of detector readings using serial communication or another validated interface. |
| REQ-F-006 | The final device shall operate as a self-contained handheld instrument. | Must | Demonstrate operation without dependence on laboratory bench equipment. |

---

## 3. Performance Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-P-001 | Measurements shall be repeatable under the same controlled test conditions. | Must | Repeat the same test multiple times and compare the resulting readings. |
| REQ-P-002 | The instrument shall respond clearly to at least one commonly available RF source during controlled testing. | Must | Test using an available legal consumer RF source such as a phone, Wi-Fi device or Bluetooth device. |
| REQ-P-003 | The displayed output shall be sufficiently stable to distinguish genuine activity changes from measurement noise. | Must | Record the detector output with no intentional source changes and quantify baseline variation. |
| REQ-P-004 | The instrument shall update quickly enough for the user to observe changes while moving around an RF source. | Should | Perform a practical movement test and record the update behaviour. |
| REQ-P-005 | The analogue detector output shall remain within the safe input range of the ESP32 ADC interface. | Must | Measure the minimum and maximum detector output voltage under tested conditions. |

Do not assign an exact frequency range, sensitivity in dBm or detection distance until experimental evidence exists.

---

## 4. User Interface Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-UI-001 | The instrument shall provide an immediately understandable indication of relative RF activity. | Must | User demonstration and inspection. |
| REQ-UI-002 | The display shall distinguish low, medium and high relative activity. | Should | Apply controlled analogue input levels and inspect the output indication. |
| REQ-UI-003 | The interface shall not display absolute RF power units unless the instrument is properly calibrated. | Must | Firmware and interface review. |
| REQ-UI-004 | Important controls shall be usable while the device is handheld. | Should | Enclosure usability test. |

---

## 5. Electrical and Power Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-E-001 | The analogue circuitry shall be electrically compatible with the ESP32. | Must | Schematic review and voltage measurements. |
| REQ-E-002 | The detector output shall not exceed the permitted ESP32 ADC input voltage. | Must | Worst-case calculation and practical measurement. |
| REQ-E-003 | The final device shall have a defined and documented power source. | Must | Power architecture review and operating test. |
| REQ-E-004 | The power system shall not introduce unacceptable noise into the detector measurement. | Must | Compare detector noise under available power configurations. |
| REQ-E-005 | The assembled device shall include appropriate supply decoupling and protection. | Must | Schematic review and power-up testing. |

The final battery or power arrangement is currently **TBD** and will be selected during system architecture development.

---

## 6. Mechanical Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-M-001 | The final instrument shall fit within a handheld enclosure. | Must | Physical inspection and enclosure measurements. |
| REQ-M-002 | The PCB, display, controls, antenna and power system shall be mechanically secured. | Must | Assembly inspection. |
| REQ-M-003 | External connectors and controls shall remain accessible. | Must | Enclosure usability test. |
| REQ-M-004 | The enclosure shall not create an obvious electrical short-circuit hazard. | Must | Mechanical and electrical inspection. |

Exact dimensions remain **TBD** until the system architecture and major components are confirmed.

---

## 7. Firmware and Software Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-SW-001 | ESP32 firmware shall acquire measurements from the detector interface. | Must | ADC input test. |
| REQ-SW-002 | Firmware shall process the raw signal into a stable relative activity indication. | Must | Compare raw and processed captured data. |
| REQ-SW-003 | Signal processing shall not hide genuine changes or create misleading measurements. | Must | Controlled step-input and RF-source testing. |
| REQ-SW-004 | Important constants and calibration parameters shall be documented. | Must | Code review. |
| REQ-SW-005 | Python tools shall support plotting and analysing recorded measurements. | Must | Run the tool using captured project data. |
| REQ-SW-006 | Source code shall be structured and documented for public GitHub publication. | Must | Repository review. |

---

## 8. Documentation Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-D-001 | Major design decisions shall be recorded in the Design Decisions Log. | Must | Documentation review. |
| REQ-D-002 | Each engineering session shall be recorded in the Engineering Log. | Must | Documentation review. |
| REQ-D-003 | Every validated subsystem shall include documented test evidence. | Must | Documentation and test-result review. |
| REQ-D-004 | Assumptions and limitations shall be stated explicitly. | Must | Documentation review. |
| REQ-D-005 | The final repository shall contain sufficient information to understand and reproduce the project. | Must | Final repository review. |

---

## 9. Safety Requirements

| ID | Requirement | Priority | Verification method |
|---|---|---:|---|
| REQ-S-001 | The project shall only receive and measure RF activity; it shall not intentionally transmit RF signals. | Must | Hardware and firmware review. |
| REQ-S-002 | Testing shall use legal consumer transmitters and normal operating modes. | Must | Test-plan review. |
| REQ-S-003 | The device shall operate from safe extra-low voltages. | Must | Power architecture review. |
| REQ-S-004 | Power rails shall be checked before connecting sensitive subsystems. | Must | Bring-up checklist and measurement evidence. |
| REQ-S-005 | The PCB shall not be connected to power until assembly inspection and continuity testing are complete. | Must | PCB bring-up record. |

---

## 10. Non-Requirements

The following capabilities are explicitly outside the initial project scope:

- Frequency spectrum display
- Frequency identification
- Protocol decoding
- Transmitter identification
- Accurate transmitter localisation
- Direction finding
- Calibrated RF power measurement in dBm
- Regulatory-compliance measurements
- Cellular interception
- Wi-Fi packet capture
- Bluetooth packet capture
- Intentional RF transmission

These are excluded because they require different hardware architectures, additional calibration or significantly greater project scope.

---

## 11. Initial Success Criteria

The project will be considered successful when:

1. A breadboard analogue detector produces a measurable and repeatable response to controlled nearby RF activity.
2. The detector output is safely acquired by an ESP32.
3. Firmware displays a stable relative activity indication.
4. Python tools can plot and analyse recorded measurement data.
5. Experimental results and limitations are documented honestly.
6. A custom KiCad PCB is designed from the validated prototype.
7. The assembled PCB operates correctly.
8. The complete system is installed in a handheld enclosure.
9. The repository documents the complete engineering lifecycle.