#include "ALU.h"

// Constructor to initialize the instruction
ALU::ALU() {
	ALU_Result = 0;
	ZeroFlag = 0;
	CarryFlag = 0;
}
// Function to perform the ALU operation
void ALU::aluFunction(uint64_t x, uint64_t y, uint8_t ALUOp) {
	//switch case based on the ALUOp from ALUfunction
	switch (ALUOp) {

	//(0000) AND
	case  0b00000000: 
		//perform AND operation
		ALU_Result = x & y;
		// Reset the flags
		ZeroFlag = 0;
		CarryFlag = 0;
		break;

	//(0001) ORR
	case  0b00000001:
		//perform OR operation
		ALU_Result = x | y;
		// Reset the flags
		ZeroFlag = 0;
		CarryFlag = 0;
		break;

	//(0010) ADD
	case  0b00000010:
		//perform ADD operation
		ALU_Result = x + y;
		// Reset the flags
		ZeroFlag = 0;
		CarryFlag = 0;
		break;

	//(0110) SUB
		case  0b00000110:
		//perform SUB operation
		ALU_Result = x - y;
		// Reset the flags
		ZeroFlag = 0;
		CarryFlag = 0;
		break;

	//(1010) SUBS
		case  0b00001010:
		if (x >= y) {
			//perform SUBS operation
			ALU_Result = x - y;
			ZeroFlag = (ALU_Result == 0); // Zero flag set when result is zero
			CarryFlag = 0; // Carry set to zero when there is no borrow
		}
		else {
			// Since x is smaller than y, we need to add a carry bit to x
			// Find y's most significant 1 bit
			int y_msb = 0;
			for (int i = 63; i >= 0; i--) {
				if ((y >> i) & 1) {
					y_msb = i;
					break;
				}
			}
			// Add the carry bit (left shifted by 1) to x
			x = x + (1 << (y_msb + 1));
			//perform SUBS operation
			ALU_Result = x - y;
			ZeroFlag = 0; // Zero flag has to be zero
			CarryFlag = 1; // Carry set to one when there is a borrow
		}
		break;

	//(0111) PASS
		case  0b00000111:
		//perform PASS operation pass input b
		ALU_Result = y;
		// Reset the flags
		ZeroFlag = (ALU_Result == 0);
		// Carry flag is passed through from the previous ALU operation
		CarryFlag = CarryFlag;
		break;

	//(1100) NOR
		case  0b00001100:
		//perform NOR operation
		ALU_Result = ~(x | y);
		// Reset the flags
		ZeroFlag = 0;
		CarryFlag = 0;
 		break;

	//default case
		default:
		// Error handling
		ALU_Result = -1; // Indicate unknown instruction type
		// Reset the flags
		ZeroFlag = 0;
		CarryFlag = 0;
	}
		
}
