#include "ALU_Control.h"

// Constructor for the ALU_Control class
ALU_Control::ALU_Control()
{
	ALUOp = 0b0000;
}
// Function to determine the ALU operation based on the instruction and ALUOp control bits
void ALU_Control::ControlSignal(uint32_t instruction , bool ALUOp1 , bool ALUOp0)
{
	// Extract the {31-21} bits from the instruction to determine the instruction type
	uint32_t opcode = (instruction >> 21) & 0x7FF;

	// Determine the instruction operation based on the ALUOp control bits
	// LDUR and STUR ALUOp (00) desired ALU action - add : control input -> 0010
	if ( (ALUOp1 == 0) && (ALUOp0 == 0) ) {
		ALUOp = 0b00000010;
	}
	// CBZ ALUOp (01) desired ALU action - pass input b : control input -> 0111
	else if ( (ALUOp1 == 0) && (ALUOp0 == 1) ) {
		ALUOp = 0b00000111;
	}
	// R-type ALUOp (10) and opcode (10001011000) desired ALU action - add : control input -> 0010
	else if ((ALUOp1 == 1) && (ALUOp0 == 0) && (opcode == 0b10001011000)) {
		ALUOp = 0b00000010;
	}
	// R-type ALUOp (10) and opcode (11001011000) desired ALU action - sub : control input -> 0110
	else if ((ALUOp1 == 1) && (ALUOp0 == 0) && (opcode == 0b11001011000)) {
		ALUOp = 0b00000110;
	}
	// R-type ALUOp (10) and opcode (11101011000) desired ALU action - subs : control input -> 1010
	else if ((ALUOp1 == 1) && (ALUOp0 == 0) && (opcode == 0b11101011000)) {
		ALUOp = 0b00001010;
	}
	// R-type ALUOp (10) and opcode (10001010000) desired ALU action - and : control input -> 0000
	else if ((ALUOp1 == 1) && (ALUOp0 == 0) && (opcode == 0b10001010000)) {
		ALUOp = 0b00000000;
	}
	// R-type ALUOp (10) and opcode (10101010000) desired ALU action - orr : control input -> 0001
	else if ((ALUOp1 == 1) && (ALUOp0 == 0) && (opcode == 0b10101010000)) {
		ALUOp = 0b00000001;
	}
	// I-type ALUOp (11) and opcode (1001001000) desired ALU action - add : control input -> 0010
	else if ((ALUOp1 == 1) && (ALUOp0 == 1) && (opcode == 0b10010001000)) {
			ALUOp = 0b00000010;
	 }
	// I-type ALUOp (11) and opcode (1101000100) desired ALU action - sub : control input -> 0110
	else if ((ALUOp1 == 1) && (ALUOp0 == 1) && (opcode == 0b11010001000)) {
		ALUOp = 0b00000110;
	}
	// Error handling
	else {
		ALUOp = -1; // Indicate unknown instruction type
	}

	


}
