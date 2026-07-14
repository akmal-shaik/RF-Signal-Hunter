# Engineering Log

## Session 001 — Requirements Definition

**Project version:** v0.1 draft

### Objective

Define the intended capabilities, constraints, verification methods and limitations of the RF Signal Hunter before selecting the detailed architecture.

### Work completed

- Created the initial repository structure.
- Defined the project mission statement.
- Defined functional requirements.
- Defined performance requirements.
- Defined electrical, mechanical, firmware and documentation requirements.
- Defined explicit non-requirements.
- Established initial project success criteria.
- Created the first Design Decisions Log entries.

### Implementation

No hardware or firmware was implemented during this session.

This was intentional because the project requirements must be understood before selecting components or designing circuits.

### Testing

No electrical testing was performed.

The requirements were reviewed for:

- Clarity
- Testability
- Realistic scope
- Honest capability claims
- Compatibility with the intended handheld final product

### Results

A draft requirements specification was produced for v0.1.

Several performance quantities remain TBD, including:

- Practical sensitivity
- Useful detection distance
- Effective frequency response
- Required sampling rate
- Display update rate
- Final power source
- Enclosure dimensions

These values will be determined through architecture analysis and experimental testing rather than guessed.

### Lessons Learned

- A broadband RF detector measures a combined response to received RF energy; it does not automatically reveal frequency.
- Absolute units require calibration and a characterised signal path.
- Requirements should describe both desired behaviour and the method used to prove that behaviour.
- Explicit non-requirements help prevent uncontrolled project expansion.

### Next controlled action

Review and approve the v0.1 requirements before beginning the v0.2 system architecture.