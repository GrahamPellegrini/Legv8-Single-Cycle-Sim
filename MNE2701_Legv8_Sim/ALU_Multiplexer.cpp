#include "ALU_Multiplexer.h"

// Constructor to initialize the instruction
ALU_Multiplexer::ALU_Multiplexer() {
	ALUReg2 = 0;
};
// Multiplex the ALU input
void ALU_Multiplexer::Multiplex(uint64_t extended, uint64_t ReadData2,bool ALUSrc) {
	//(Reg2Loc = 1 ) ALUREG2 is equal to the sign-extended instruction
	if (ALUSrc == 1) {
		ALUReg2 = extended;
	}
	//(Reg2Loc = 0) ALUREG2 is equal to the value read from the second register
	else {
		ALUReg2 = ReadData2;
	}
	
};

