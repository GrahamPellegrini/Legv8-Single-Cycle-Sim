#include "Instruction_Identifier.h"
#include <iostream>

int Instruction_Identifier::getInstructionType(uint32_t instruction) {
    // Extract the opcode from the instruction {31-21}
    uint32_t opcode = (instruction >> 21);

    // Determine the type of instruction based on the opcode
    // R-type instruction (1 X X 0 1 0 1 X 0 0 0)
    if ((opcode & 0b1001111011) == 0b10001010000) { //comparision using bitwise AND as mask
        return 0;
    }
    // LDUR instruction (1 1 1 1 1 0 0 0 0 1 0)
    else if (opcode == 0b11111000010) {
        return 1;
    }
    // STUR instruction (1 1 1 1 1 0 0 0 0 0 0)
    else if (opcode == 0b11111000000) {
        return 2;
    }
    // CBZ instruction (1 0 1 1 0 1 0 0 X X X)
    else if ((opcode & 0b11111111000) == 0b10110100000 ) { //comparision using bitwise AND as mask
        return 3;
    }
    else {
        // Handle other cases
        return -1; // Indicate unknown instruction type
    }
}
