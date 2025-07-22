#ifndef ALU_MULTIPLEXER_H
#define ALU_MULTIPLEXER_H

#include <cstdint>

class ALU_Multiplexer {

	public:
		uint64_t ALUReg2;
		// Constructor to initialize the instruction
		ALU_Multiplexer();
		// Multiplex the ALU input
		void Multiplex(uint64_t extended, uint64_t ReadData2, bool ALUSrc);

};

#endif // ALU_MULTIPLEXER_H
