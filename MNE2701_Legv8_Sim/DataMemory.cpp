#include "DataMemory.h"
// Constructor
DataMemory::DataMemory(uint64_t* memory)
{	// set memory to the memory array passed in
	this->memory = memory;
	// Read .data file and store the data in memory
	std::ifstream dataFile("C:\\Users\\user\\OneDrive\\Documents\\UOM_Documents\\sumtwo\\bubble_sort\\bubble_sort.data");
	if (dataFile.is_open())
	{
		std::string line;
		int i = 0;
		while (std::getline(dataFile, line))
		{
			memory[i] = std::stoull(line, nullptr, 16);
			i++;
		}
		dataFile.close();
	}
	else
	{
		std::cout << "Unable to open file";
	}
	ReadData = 0;
}
// Function to read and write data to memory
void DataMemory::dmFunction(uint64_t address, uint64_t WriteData,
	bool MemRead, bool MemWrite)
{

	// If MemRead is 1, read the data at the address
	if (MemRead == 1)
	{
		ReadData = memory[address];
	}
	else // If MemRead is 0, set readData to 0
	{
		ReadData = 0;
	}

	// If MemWrite is 1, write the data at the address
	if (MemWrite == 1)
	{
		memory[address] = WriteData;
	}
}
