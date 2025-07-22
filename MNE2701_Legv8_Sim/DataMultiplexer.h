#pragma once
#include <iostream>
class DataMultiplexer
{
	public:
		uint64_t WriteData;
		// Constructor
		DataMultiplexer();
		// Multiplex function
		void Multiplex(uint64_t ReadData , uint64_t ALU_Result, bool MemtoReg);
};

