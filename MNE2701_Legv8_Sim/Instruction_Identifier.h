#ifndef INSTRUCTION_IDENTIFIER_H
#define INSTRUCTION_IDENTIFIER_H

#include <cstdint>

class Instruction_Identifier {
public:
    static int getInstructionType(uint32_t instruction);
};

#endif // INSTRUCTION_IDENTIFIER_H
