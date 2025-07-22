// Make a bubble sort algorithm that sorts the array from smallest to largest
// Using only Using LDURB, STURB, ADD, SUB, ADDI, SUBI, B , B.HS, SUBS, CBZ and CBNZ instuctions

.data
array:  .byte 200, 15, 20, 40, 8, 7, 6, 5, 20, 0
/* Notes:
	X0 is i counter starting from size of array and decrement every outer loop iteration
	X1 is j counter starting from 0 and increment every inner loop iteration
	inner loop completes when j = i-1
	outer loop completes when i = 0
	X2 is the register holidng the value at array[j]
	X3 is the register holding the value at array[j+1]
	X4 is the register holding the result of the comparison between X2 and X3
	X5 is the register holding the of i-2 for comparison with j
	X6 is the register holding the comparison between X0 and X1 for inner relooping

*/ 
.text
start:
	// Load the array length into X0 (i)
	ADDI X0, XZR, #10

outer_loop:
	// Check if the outer_loop is done (i = 0)
	CBZ X0, exit

	// Initialize the inner loop counter (j)
	ADDI X1, XZR, #0
	
	// Branch to inner_loop:
	B inner_loop

inner_loop:
	// Load the value at array[j] into X2
	LDURB X2, [X1]

	// Load the value at array[j+1] into X3
	LDURB X3, [X1, #1]

	// Compare X2 and X3
	SUBS X4, X2, X3

	// Branch to swap if X2 >= X3
	B.HS swap
	
	// Branch to inner_reloop 
	B inner_reloop

swap:
	// Store the value at X2 into array[j+1]
	STURB X2, [X1, #1]

	// Store the value at X3 into array[j]
	STURB X3, [X1]

	// Branch to inner_loop:
	B inner_reloop

inner_reloop:
	// Increment the inner loop counter (j++)
	ADDI X1, X1, #1
	// Calculate i-2 and store in X5
	SUBI X5, X0, #2
	// Compare X1 and X5
	SUBS X6, X5, X1
	// Branch back to loop if i-2 >= j
	B.HS inner_loop

	// if not then branch to outer_reloop
	B outer_reloop

outer_reloop:
	// Decrement the outer loop counter (i--)
	SUBI X0, X0, #1

	// Branch to outer_loop:
	B outer_loop

exit: 
	// Exit the program
	B exit
