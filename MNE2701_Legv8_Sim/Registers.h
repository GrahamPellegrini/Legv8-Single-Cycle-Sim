#pragma once
#include <iostream>
#include <bitset>
#include <cstdint>


class Registers
{
	// This class is used to simulate the registers in the Legv8 processor
	public:
		uint64_t  ReadData1;
		uint64_t  ReadData2;
		// Constructor for the Registers class
		Registers();
		// Function to set the ReadData1, ReadData2 and write to the register file
		void RegFunction(uint32_t ReadReg1, uint32_t ReadReg2 , uint32_t WriteReg,
			uint64_t WriteData, bool RegWrite , uint64_t* REG);
};

