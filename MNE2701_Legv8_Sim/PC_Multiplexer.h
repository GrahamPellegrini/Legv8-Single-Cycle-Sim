#pragma once
#include <cstdint>

class PC_Multiplexer {
public:
	uint32_t PC;
	// Constructor 
	PC_Multiplexer();
	// Multiplex function
	void Multiplex(uint32_t PCinc4, uint32_t PCALU, bool Branch, bool UncondBranch, bool InvZero, bool HS, bool Zero, bool Carry);

	private:
		bool PCSrc;
};

