#pragma once
#include <stdint.h>
#include <iostream>
#include <bitset>

class ALU_Control
{
public:

	uint8_t ALUOp;
	// Constructor for the ALU_Control class
	ALU_Control();
	// Function to determine the ALU operation based on the instruction and ALUOp control bits
	void ControlSignal(uint32_t instruction, bool ALUOp1 ,bool ALUOp0);

};

