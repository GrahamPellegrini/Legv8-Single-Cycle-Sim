#include "DataMultiplexer.h"
// Constructor
DataMultiplexer::DataMultiplexer() {
	WriteData = 0;
}
// Multiplex function
void DataMultiplexer::Multiplex(uint64_t ReadData, uint64_t ALU_Result, bool MemtoReg){
	if (MemtoReg == 0) {
		WriteData = ALU_Result;
	}
	else {
		WriteData = ReadData;
	}
}
