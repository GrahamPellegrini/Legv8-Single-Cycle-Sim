#ifndef INSTRUCTION_LOADER_H
#define INSTRUCTION_MEMORY_H

#include <string>
#include <vector>

class Instruction_Memory {
public:
    Instruction_Memory(const std::string& filename);
    uint32_t readaddress(uint32_t PC);
    int getInstructionCount();

    private:
        std::vector<uint32_t> instructions;
};

#endif // INSTRUCTION_MEMORY_H
