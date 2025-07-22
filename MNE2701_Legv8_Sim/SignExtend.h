#ifndef SIGNEXTEND_H
#define SIGNEXTEND_H

#include <cstdint>

class SignExtend {
public:
	// 64 bit sign-extended instrcution
	uint64_t extended;
	// Constructor for extending the instruction
	SignExtend();
	// Function to extend the instruction
	void seFunction(uint32_t instr);
};

#endif // SIGNEXTEND_H
