#include "PC_Multiplexer.h"
// Constructor
PC_Multiplexer::PC_Multiplexer() {
	PC = 0;
	PCSrc = 0;
}
// Multiplex function
void PC_Multiplexer::Multiplex(uint32_t PCinc4, uint32_t PCALU, bool Branch, bool UncondBranch, bool InvZero, bool HS, bool Zero, bool Carry) {
	
	// For all branch instructions run PCSrc logic
	if (Branch == 1) {
		// Check if the Zero flag should be inverted
		if (InvZero == 1) {
			Zero = !Zero;
		}
		// Check if statement is unconditional branch
		if (UncondBranch == 1) {
			PCSrc = 1;
		}
		// Check if statement is a .hs branch
		else if (HS == 1) {
			PCSrc = !Carry;
		}
		// Logically Branch is equal to Zero flag
		else {
			PCSrc = Zero;
		}
	}
	// For all other instructions, PCSrc = 0
	else {
		PCSrc = 0;
	}

	//if PCSrc is 0, PC = PC + 4
	if (PCSrc == 0) {
		PC = PCinc4;
	}
	//if PCSrc is 1, PC = PCALU
	else {
		PC = PCALU;
	}	
};