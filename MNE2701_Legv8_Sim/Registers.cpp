#include "Registers.h"

// Constructor for the Registers class
Registers::Registers() {
	//initialize the ReadData1 and ReadData2 to 0
	ReadData1 = 0;
	ReadData2 = 0;
}

void Registers::RegFunction(uint32_t ReadReg1, uint32_t ReadReg2, 
	uint32_t WriteReg, uint64_t WriteData, bool RegWrite, uint64_t* REG) {
	//X31 register is always 0
	REG[31] = 0;
	
	// This class is used to simulate the registers in the Legv8 processor
	// ReadData1 is the value stored in the register ReadReg1
	//access the register file
	ReadData1 = REG[ReadReg1];

	// ReadData2 is the value stored in the register ReadReg2
	ReadData2 = REG[ReadReg2];

	// WriteData is the value to be written to the register file but cannot write to register 31
	if ((RegWrite == 1)&&(WriteReg != 31)) {
		REG[WriteReg] = WriteData;
	}
	/*if Reg is 0, error message is displayed
	else
	{
		std::cout << "Error: Cannot write to register 0" << std::endl;
	}
	*/
}