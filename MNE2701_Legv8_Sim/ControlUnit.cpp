    #include "ControlUnit.h"

ControlUnit::ControlUnit() {
	// Initialize the control signals
	Reg2Loc = 0;
	ALUSrc = 0;
	MemtoReg = 0;
	RegWrite = 0;
	MemRead = 0;
	MemWrite = 0;
	ALUOp1 = 0;
	ALUOp0 = 0;
	ZeroUpp56 = 0;
    UncondBranch = 0;
    Branch = 0;
    InvZero = 0;
    HS = 0;
	instructionType = -1;
}

void ControlUnit::setControlSignals(uint32_t instruction) {
    // Extract the {31-21} bits from the instruction to determine the instruction type
    uint32_t opcode = (instruction >> 21) & 0b11111111111;

    //Determine the type of instruction based on the opcode
    // R-type instruction (1 X X 0 1 0 1 X 0 0 0)
        if ((opcode & 0b10011110111) == 0b10001010000) { //comparision using bitwise AND as mask
            instructionType = 0;
        }
    // LDURB instruction (0 0 1 1 1 0 0 0 0 1 0)
        else if (opcode == 0b00111000010) {
            instructionType = 1;
        }
    // STURB instruction (0 0 1 1 1 0 0 0 0 0 0)
        else if (opcode == 0b00111000000) {
            instructionType = 2;
        }
    // CBZ instruction (1 0 1 1 0 1 0 0 X X X)
        else if ((opcode & 0b11111111000) == 0b10110100000) { //comparision using bitwise AND as mask
            instructionType = 3;
        }
    // B instruction (0 0 0 1 0 1 X X X X X)
        else if ((opcode & 0b11111110000) == 0b00010100000) { //comparision using bitwise AND as mask
        			instructionType = 4;
        }
    // I-type instruction (1 X 0 1 0 0 0 1 0 0 X) [ADDI -> 1001000100 || SUBI -> 1101000100]
        else if ((opcode & 0b10111111110) == 0b10010001000) { //comparision using bitwise AND as mask
        			instructionType = 5;
        }
    //CBNZ instruction (1 0 1 1 0 1 0 1 X X X)
		else if ((opcode & 0b11111111000) == 0b10110101000) { //comparision using bitwise AND as mask
        			instructionType = 6;
        }
    //B.HS instrcution (0 1 0 1 0 1 0 0 X X X)
        else if( (opcode & 0b11111111000) == 0b01010100000) { //comparision using bitwise AND as mask
            // Note that we are making for b.cond but since the only b.cod instruction is B.HS we generalize it
        			instructionType = 7;
        }
        else {
            // Handle other cases
            instructionType = -1; // Indicate unknown instruction type
        }


    // Set the control signals based on the instruction type
    switch (instructionType) {
    case 0: // R-type instruction
        // Set the control signals for R-type instruction
        Reg2Loc = 0;
        ALUSrc = 0;
        MemtoReg = 0;
        RegWrite = 1;
        MemRead = 0;
        MemWrite = 0;
        ALUOp1 = 1;
        ALUOp0 = 0;
        ZeroUpp56 = 0;
        UncondBranch = 0;
        Branch = 0;
        InvZero = 0;
        HS = 0;
        break;

    case 1: // LDURB instruction
        // Set the control signals for LDURB instruction
        Reg2Loc = 0; // this is a dont care for LDURB
        ALUSrc = 1;
        MemtoReg = 1;
        RegWrite = 1;
        MemRead = 1;
        MemWrite = 0;
        ALUOp1 = 0;
        ALUOp0 = 0;
        ZeroUpp56 = 1;
        UncondBranch = 0;
        Branch = 0;
        InvZero = 0;
        HS = 0;
        break;

    case 2: // STURB instruction
        // Set the control signals for STURB instruction
        Reg2Loc = 1;
        ALUSrc = 1;
        MemtoReg = 0; // this is a dont care for STURB
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 1;
        ALUOp1 = 0;
        ALUOp0 = 0;
        ZeroUpp56 = 1;
        UncondBranch = 0;
        Branch = 0;
        InvZero = 0;
        HS = 0;
        break;

    case 3: // CBZ instruction
        // Set the control signals for CBZ instruction
        Reg2Loc = 1;
        ALUSrc = 0;
        MemtoReg = 0; // this is a don't care for CBZ
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        ALUOp1 = 0;
        ALUOp0 = 1;
        ZeroUpp56 = 0; // this is a don't care for CBZ
        UncondBranch = 0;
        Branch = 1; // Branch if zero
        InvZero = 0; // Do not invert the zero flag
        HS = 0; // Do not set the HS flag
        break;

    case 4: // B instruction
		// Set the control signals for B instruction
        Reg2Loc = 1;
        ALUSrc = 0;
        MemtoReg = 0; // this is a don't care for B
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        ALUOp1 = 0;
        ALUOp0 = 1;
        ZeroUpp56 = 0; 
        UncondBranch = 1; // Unconditional branch
        Branch = 1; // Unconditional branch
        InvZero = 0;  // Do not invert the zero flag
        HS = 0; //  Do not set the HS flag
		break;

    case 5: // I-type instruction
		// Set the control signals for I-type instruction
		Reg2Loc = 0; // this is a don't care for I-type
		ALUSrc = 1;  // Immediate value multiplexed to alu
		MemtoReg = 0; // Alu result write back to register
		RegWrite = 1; // Write back to register
		MemRead = 0;  // No memory read
        MemWrite = 0; // No memory write
		ALUOp1 = 1; // ALUOp for I-type is 11
		ALUOp0 = 1;
		ZeroUpp56 = 0; 
        UncondBranch = 0; // No unconditional branch
        Branch = 0; // No branch
        InvZero = 0; 
        HS = 0;
		break;

    case 6: // CBNZ instruction
        // Set the control signals for CBNZ instruction
        Reg2Loc = 1;
        ALUSrc = 0;
        MemtoReg = 0; // this is a don't care for CBNZ
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        ALUOp1 = 0;
        ALUOp0 = 1;
        ZeroUpp56 = 0; // this is a don't care for CBNZ
        UncondBranch = 0; // No unconditional branch
        Branch = 1; // Branch if not zero
        InvZero = 1; // Invert the zero flag
        HS = 0; // Do not set the HS flag
        break;

    case 7: // B.HS instruction
        // Set the control signals for B.HS instruction
		Reg2Loc = 1;
		ALUSrc = 0;
		MemtoReg = 0; // this is a don't care for B.cond
		RegWrite = 0;
		MemRead = 0;
		MemWrite = 0;
		ALUOp1 = 0;
		ALUOp0 = 1;
		ZeroUpp56 = 0; // this is a don't care for B.cond
        UncondBranch = 0; // No unconditional branch
        Branch = 1; // Branch if condition HS is met
		InvZero = 0; // Do not invert the zero flag
        HS = 1; // Set the HS flag
		break;
    default:
        // Set the control signals for default instruction
        Reg2Loc = 0;
        ALUSrc = 0;
        MemtoReg = 0;
        RegWrite = 0;
        MemRead = 0;
        MemWrite = 0;
        UncondBranch = 0;
        Branch = 0;
        ALUOp1 = 0;
        ALUOp0 = 0;
        ZeroUpp56 = 0;
        InvZero = 0;
        break;
    }
}
void ControlUnit::printControlSignals() {
	std::cout << "Reg2Loc: " << Reg2Loc << std::endl;
	std::cout << "ALUSrc: " << ALUSrc << std::endl;
	std::cout << "MemtoReg: " << MemtoReg << std::endl;
	std::cout << "RegWrite: " << RegWrite << std::endl;
	std::cout << "MemRead: " << MemRead << std::endl;
	std::cout << "MemWrite: " << MemWrite << std::endl;
    std::cout << "UncondBranch: " << UncondBranch << std::endl;
	std::cout << "Branch: " << Branch << std::endl;
	std::cout << "ALUOp1: " << ALUOp1 << std::endl;
	std::cout << "ALUOp0: " << ALUOp0 << std::endl;
	std::cout << "ZeroUpp56: " << ZeroUpp56 << std::endl;

    //print the instruction type
    switch (instructionType) {
        // R-type instruction
        case 0: std::cout << "Instruction Type: R-type" << std::endl;
			break;
        // LDURB instruction
		case 1: std::cout << "Instruction Type: LDURB" << std::endl;
            break;
		// STURB instruction
        case 2: std::cout << "Instruction Type: STURB" << std::endl;
			break;
        // CBZ instruction
		case 3: std::cout << "Instruction Type: CBZ" << std::endl;
            break;
        // B instruction
        case 4: std::cout << "Instruction Type: B" << std::endl;
			break;
		// I-type instruction
            case 5: std::cout << "Instruction Type: I-type" << std::endl;
			break;
		default: std::cout << "Instruction Type: Unknown" << std::endl;
			break;
    }
}

