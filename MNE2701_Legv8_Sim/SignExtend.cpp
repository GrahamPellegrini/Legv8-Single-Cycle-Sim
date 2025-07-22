#include "SignExtend.h"
#include <iostream>
#include <bitset>

// Constructor for extending the instruction
SignExtend::SignExtend() {
	extended = 0;
}

// Function to extend the instruction
void SignExtend::seFunction(uint32_t instr) {
	// find bit 31 from the 32 bit instruction
	int bit31 = (instr >> 31) & 0x1;

	// find bit 30 from the 32 bit instruction
	int bit30 = (instr >> 30) & 0x1;

	// find bit 26 from the 32 bit instruction
	int bit26 = (instr >> 26) & 0x1;

	uint32_t bitfield = instr;


	//choose the respective bit fields
	if ((bit31 == 0) && (bit26 == 1) && (bit30 == 0)) // B instruction 25-bit field
	{
		// Extract the last 25 bits from the instruction
		bitfield = instr & 0x01FFFFFF;
	}
	if ((bit31 == 0) && (bit26 == 1) && (bit30 == 1)) // B.cond instruction 19-bit field
	{
		// Extract the 23rd till the 5th bits from the 32-bit instruction
		bitfield = (instr >> 5) & 0x0007FFFF;
	}
	if ((bit31 == 0) && (bit26 == 0)) // LDURB or STURB instruction 9-bit field
	{
		// Extract the 20th till the 12th bits from the 32-bit instruction 
		bitfield = (instr >> 12) & 0x000001FF;
	}
	if ((bit31 == 1) && (bit26 == 1)) // CBZ & CBNZ  instruction 19-bit field
	{
		// Extract the 23rd till the 5th bits from the 32-bit instruction
		bitfield = (instr >> 5) & 0x0007FFFF;
	}
	if ((bit31 == 1) && (bit26 == 0)) // I instruction 12-bit field
	{
		// Extract the 21st till the 10th bits from the 32-bit instruction
		bitfield = (instr >> 10) & 0x00000FFF;
	}
	// Find the MSB of the bitfield
	int msb = (bitfield >> 31) & 0x1;

    // If MSB is 1 (negative number), sign extend with 1s; otherwise, sign extend with 0s
    uint64_t extension = msb ? 0xFFFFFFFF00000000 : 0x0000000000000000;

    // Assign the sign-extended value to the 'extended' member variable
    extended = static_cast<uint64_t>(bitfield) | extension;
}
