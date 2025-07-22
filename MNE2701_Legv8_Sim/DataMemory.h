#pragma once
#include <iostream>
#include <fstream>
#include <string>

class DataMemory
{
public:
	uint64_t ReadData;
	uint64_t* memory;
	// Constructor
	DataMemory(uint64_t* memory);
	// Function to read and write data to memory
	void dmFunction(uint64_t address, uint64_t WriteData ,
		bool MemRead , bool MemWrite);

};

