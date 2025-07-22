#include "Reg2_Multiplexer.h"
#include <cstdint>

// Constructor to initialize the instruction
Reg2_Multiplexer::Reg2_Multiplexer() {
	ReadReg2 = 0;
};

// Constructor to multiplex the instruction
void Reg2_Multiplexer::Multiplex(uint32_t instr, bool Reg2Loc) {
 //This multiplexer is used to select the second register to be read from the register file
	if (Reg2Loc == 0) {
		// (0) ReadReg2 is equal to bits 20-16 of the instruction
		ReadReg2 = (instr >> 16) & 0x0000001F;	
	}
	else {
		// (1) ReadReg2 is equal to bits 4-0 of the instruction
		ReadReg2 = instr & 0x0000001F;
	}	
};

