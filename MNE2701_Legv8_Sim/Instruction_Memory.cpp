#include "Instruction_Memory.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <string>
#include <vector>


//constructor initializor
Instruction_Memory::Instruction_Memory(const std::string& filename) {
	// Initialize the vector size of instruction memory to be 1000
    instructions.resize(1000);

    //open file
    std::ifstream
        infile(filename);
    std::string line;


    // check if file is open
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        instructions = {};
    }
    //instruction bit counter
    int i = 0;

    // Read each line of the file
    while (std::getline(infile, line)) {

        // Find the position of the comment
        size_t commentPos = line.find('\\');
        // Check if a comment exists
        if (commentPos != std::string::npos) {
            // Remove the comment
            line = line.substr(0, commentPos);
        }

        //remove all spaces
        line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

        // Check if the line is empty
        if (line.empty()) {
            // Skip the line
            continue;
        }

        //convert the hex instruction to uint32_t
        uint32_t binaryInstruction = std::stoul(line, nullptr, 16);

        // Store the binary instruction in the vector
        instructions[i] = binaryInstruction;
        i++;

        //check if the instruction memory is full
        if (i == 1000) {
			break;
		}


    }
	
}

uint32_t Instruction_Memory::readaddress(uint32_t PC) {
    //return the instruction at the PC
    return instructions[PC];
}

int Instruction_Memory::getInstructionCount() {
    //resize the vector to remove the empty elements
    instructions.resize(std::distance(instructions.begin(), std::find(instructions.begin(), instructions.end(), 0)));
    return instructions.size();
}



