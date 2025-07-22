// MNE2701_Legv8_Sim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Instruction_Memory.h"
#include "ControlUnit.h"
#include "Reg2_Multiplexer.h"
#include "Registers.h"
#include "SignExtend.h"
#include "ALU_Control.h"
#include "ALU_Multiplexer.h"
#include "ALU.h"
#include "DataMemory.h"
#include "DataMultiplexer.h"
#include "PC_Multiplexer.h"

#include <iostream>
#include <bitset>

int main() {
    //an array of 32 registers 
    uint64_t REG[32] = { 0 };

    //an array of 32 memory locations
    uint64_t memory[32] = { 0 };

    //initialize the PC to 0
    uint32_t PC = 0x00000000;
    //initialize the Instruction to 0x00000000
    uint32_t  Instruction = 0x00000000;
    // ReadReg1 intialization
    uint32_t ReadReg1 = 0x00000000;
    // WriteReg intialization
    uint32_t WriteReg = 0x00000000;
    // WriteData intialization
    uint64_t WriteData = 0x00000000;

    // Initailize the control unit
    ControlUnit cu;
    // Initialize the Reg2_Multiplexer
    Reg2_Multiplexer reg2mux;
    // Initialize the Registers
    Registers reg1;
    // Initialize the Sign Extend
    SignExtend se;
    // Initialize the ALU Control
    ALU_Control alucontrol;
    // Initialize the ALU Multiplexer
    ALU_Multiplexer aluMux;
    // Initialize the first ALU
    ALU alu1;
    // Initialize the Data Memory
    DataMemory dMem(memory);
    // Initialize the Data Multiplexer
    DataMultiplexer dataMux;
    // Initialize the second ALU
    ALU alu2;
    // Initialize the third ALU
    ALU alu3;
    // Initialize the PC Multiplexer
    PC_Multiplexer pc_mux;


    // Create an instance of the Instruction Memory  
    Instruction_Memory* iMem = new Instruction_Memory("C:\\Users\\user\\OneDrive\\Documents\\UOM_Documents\\sumtwo\\bubble_sort\\bubble_sort.text");
    int Icount = iMem->getInstructionCount();
    // Print the number of instructions
    std::cout << "Number of instructions: " << Icount << std::endl;

    //loop through the instructions in the instruction memory accounting for branch instructions
    while (PC < Icount * 4)
     {   
        
        // set the instruction to the value at the PC
        Instruction = iMem->readaddress(PC/4);
        //print the instruction
        std::cout << "Instruction: " << std::bitset<32>(Instruction) << std::endl;  

        // Set the control signals
        cu.setControlSignals(Instruction);

        // Multiplex to get the second register
        reg2mux.Multiplex(Instruction, cu.Reg2Loc);

        // ReadReg1 is instruction[9-5]
        ReadReg1 = (Instruction >> 5) & 0x0000001F;
        /* print read register 1
        std::cout << "Read Register 1: " << std::bitset<32>(ReadReg1) << std::endl;*/
        // WriteReg is instruction[4-0] 
        WriteReg = Instruction & 0x0000000F;
        /* print write register
        std::cout << "Write Register: " << std::bitset<32>(WriteReg) << std::endl;*/
        // Clear reinitialize of the WriteData to 0
        WriteData = 0x00000000;

        // Function the register file to get the ReadData1 and ReadData2
        reg1.RegFunction(ReadReg1, reg2mux.ReadReg2, WriteReg, WriteData, cu.RegWrite , REG);
        
        // Sign Extend the instruction
        se.seFunction(Instruction);
        //print the SignExtendedValue
        std::cout << "Sign Extended Value: " << std::bitset<64>(se.extended) << std::endl;

        //Shift left by 2 to get the offset
        uint64_t offset = se.extended << 2;
        //print the offset
        std::cout << "Offset: " << std::bitset<64>(offset) << std::endl;

        // Set the ALU control signals
        alucontrol.ControlSignal(Instruction, cu.ALUOp1, cu.ALUOp0);

        // Multiplex to get the second ALU input
        aluMux.Multiplex(se.extended, reg1.ReadData2,cu.ALUSrc);

        // Pass the values to the ALU to get the result
        alu1.aluFunction(reg1.ReadData1,aluMux.ALUReg2,alucontrol.ALUOp);
        // Print the ALU result
        std::cout << "ALU Result: " << std::bitset<32>(alu1.ALU_Result) << std::endl;

        // Function the Data Memory to get the ReadData
        dMem.dmFunction(alu1.ALU_Result, reg1.ReadData2, cu.MemRead , cu.MemWrite);

        // Multiplex to get the value to write to the register
        dataMux.Multiplex(dMem.ReadData, alu1.ALU_Result, cu.MemtoReg);
        // Save the value to WriteData
        WriteData = dataMux.WriteData;
        // Print the value to write to the register
        std::cout << "Write Data: " << std::bitset<64>(WriteData) << std::endl;

        // Write back to register (Only does something when RegWrite is 1)
        reg1.RegFunction(ReadReg1, reg2mux.ReadReg2, WriteReg, WriteData, cu.RegWrite, REG);

        // Function the ALU that adds 4 to the PC
        alu2.aluFunction(PC, 0x00000004, 0b0010);

        // Function the ALU that adds the PC to the sign-extended instruction
        alu3.aluFunction(PC, offset, 0b0010);

        // Multiplex to get the new PC
        pc_mux.Multiplex(alu2.ALU_Result, alu3.ALU_Result, cu.Branch, cu.UncondBranch, cu.InvZero, cu.HS, alu1.ZeroFlag, alu1.CarryFlag);

        // Set the PC to the new PC
        PC = pc_mux.PC;
        // Print the new PC
        std::cout << "PC: " << std::bitset<32>(PC) << std::endl;
       
        // Print the contents of the registers
       for (int i = 0; i < 32; i++) {
		    std::cout << "Register " << i << ": " << std::bitset<32>(REG[i]) << std::endl;
	    }
       // Print dash separator
       std::cout << "--------------------------------" << std::endl;
       
       
	    // Print the contents of the memory
        for (int i = 0; i < 32; i++) {
		    std::cout << "Memory " << i << ": " << std::bitset<32>(memory[i]) << std::endl;
	    }
        // Print a new line
        std::cout << std::endl;
        // Print dash separator
        std::cout << "--------------------------------" << std::endl;
        
	}

	return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
