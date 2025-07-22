#pragma once
#include <iostream>
#include <cstdint>

class Reg2_Multiplexer
{
	public:
		uint32_t ReadReg2;
		// Constructor to initialize the instruction
		Reg2_Multiplexer();
		// Constructor to multiplex the instruction
		void Multiplex(uint32_t instr, bool Reg2Loc);
};

