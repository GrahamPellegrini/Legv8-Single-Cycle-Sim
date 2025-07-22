// This Assembly Source will test the B, B.HS, SUBS, CBZ and CBNZ instructions

.text
start:
	// First we must load some values using ADDI
	// ADDI 5 into X0
	ADDI X0,XZR, 5

	// ADDI 10 into X1
	ADDI X1,XZR, 10

	// ADDI 15 into X2
	ADDI X2,XZR, 15

	// Begin Branch Testing
	B UncondtionalB

UncondtionalB:
	// Here we will test all the branches for invalid values
	// That is no branching

	// Test CBZ with XO (value 5)
	CBZ X0, Wrong

	// Test CBNZ with X3 (value 0)
	CBNZ X3, Wrong

	// Test B.HS with X0 and X1
	SUBS X4, X0, X1
	B.HS Wrong

	// Now we test the branches for good values	
	// That is all branches should be taken

	// Test CBZ with X3 (value 0)
	CBZ X3, Good1


Wrong:
	// If we reach here, the test has failed
	// We will set X8 to 32
	ADDI X8, X8, 32

	// Now we test the branches for good values	
	// That is all branches should be taken

	// Test CBZ with X3 (value 0)
	CBZ X3, Good1

Good1:
	// If we reach here, CBZ works
	// We will set X5 to 1
	ADDI X5, XZR, #1

	// Now we test CBNZ with X0
	CBNZ X0, Good2

Good2:
	// If we reach here, CBNZ works
	// We will set X6 to 1
	ADDI X6, XZR, #1

	// Now we test B.HS with X2 and X1
	SUBS X4, X2, X1
	B.HS Good3

Good3:
	// If we reach here, B.HS works
	// We will set X7 to 1
	ADDI X7, XZR, #1
	
	// If we reach here, the test has passed