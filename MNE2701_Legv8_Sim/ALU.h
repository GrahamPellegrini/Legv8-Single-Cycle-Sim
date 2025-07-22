#pragma once
#ifndef ALU_H
#define ALU_H

#include <stdint.h>
class ALU
{
	public:
		uint64_t ALU_Result;
		bool ZeroFlag = 0;
		bool CarryFlag = 0;
		// Constructor to initialize the instruction
		ALU();
		// Function to perform the ALU operation
		void aluFunction(uint64_t x, uint64_t y, uint8_t ALUOp);
};

#endif // ALU_H