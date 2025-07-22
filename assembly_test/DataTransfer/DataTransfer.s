// This assembly source is going to test the LDURB and STURB fucntions in ARMv8
.text
start:
    // Use ADDI to load initial values into registers
    // Load a 1 into X1
    ADDI X1, XZR, #1
    // Load a 2 into X2
    ADDI X2, XZR, #2

    // Testing LDURB and STURB
    // Store the register value of X1 into memory at address X1
    STURB X1, [XZR, #1]
    // Store the register value of X2 into memory at address X2
    STURB X2, [X2]

    // Load the value at address X1 into X3
    LDURB X3, [X1]

    // Load the value at address X1 + 1 into X4
    LDURB X4, [X1, #1]

