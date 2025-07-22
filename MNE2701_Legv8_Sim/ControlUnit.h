    #pragma once
#include <iostream>
#include <cstdint>

class ControlUnit {
public:
    bool Reg2Loc;
    bool ALUSrc;
    bool MemtoReg;
    bool RegWrite;
    bool MemRead;
    bool MemWrite;
    bool ALUOp1;
    bool ALUOp0;
    bool ZeroUpp56;
    bool UncondBranch;
    bool Branch;
    bool InvZero;
    bool HS;
    int instructionType;

   // Constructor to initialize the instruction
   ControlUnit();
   // Function to set control signals based on the instruction type
   void setControlSignals(uint32_t instruction);
   // Function to print the control signals
   void printControlSignals();
};
