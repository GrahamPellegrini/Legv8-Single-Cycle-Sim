// This Assembler source is going to test ADD, SUB, ADDI, SUBI

.text
start:
    // ADDI 10 to register X0 (also a loading method)
    ADDI X0, XZR, #10

    // ADDI 5 to register X1 
    ADDI X1, XZR, #5

    // Add X0 and X1 into X2
    ADD X2, X0, X1

    // SUBI 5 from X2 and store in X3
    SUBI X3, X2, #5

    // SUB X1 from X0 and store in X4
    SUB X4, X0, X1

