<h1 align="center">LEGv8 Single-Cycle Architecture Simulation</h1>

<p align="center">
  <a href="https://www.um.edu.mt/courses/studyunit/CCE2017">
    <img src="https://img.shields.io/badge/University%20of%20Malta-CCE2017-blue?style=for-the-badge" alt="CCE2017">
  </a>
  <a href="https://github.com/GrahamPellegrini/legv8-single-cycle-sim">
    <img src="https://img.shields.io/badge/Architecture-Single--Cycle-green?style=for-the-badge" alt="Single-Cycle">
  </a>
  <a href="https://www.um.edu.mt/profile/victorbuttigieg">
    <img src="https://img.shields.io/badge/Supervisor-Dr.%20Victor%20Buttigieg-lightgrey?style=for-the-badge" alt="Supervisor">
  </a>
</p>

---

## 🧠 Overview

This repository contains a simulation of a **single-cycle processor architecture** based on the LEGv8 instruction set. Developed for the [CCE2017](https://www.um.edu.mt/courses/studyunit/CCE2017) unit at the University of Malta, the simulator was written in C++ to replicate the internal workings of a simplified RISC-style CPU.

### 🧩 Features Implemented
- Instruction fetch from `.text` file
- Data memory and register file setup with `.data` files
- Control signal generation through a dedicated `ControlUnit` module
- Handling of ALU operations and control logic
- PC update via multiplexer logic (with flag support for branches)
- Support for key LEGv8 instructions including `ADD`, `SUB`, `ADDI`, `LDURB`, `STURB`, `CBNZ`, `CBZ`, `B`, and `B.HS`


---

## 📁 Repository Structure

```bash
legv8-single-cycle-sim/
├── MNE2701_Legv8_Sim/            # C++ source code for processor modules
│   ├── ALU.cpp/.h                # Arithmetic Logic Unit
│   ├── ControlUnit.cpp/.h       # Instruction decoder & signal generator
│   ├── DataMemory.cpp/.h        # Memory read/write handling
│   ├── Instruction_Memory.cpp/.h# Instruction fetch from file
│   ├── Registers.cpp/.h         # Register file with XZR logic
│   ├── Multiplexers/*.cpp/.h    # ALU/PC/Data/Reg2 multiplexers
│   ├── SignExtend.cpp/.h        # Immediate value extender
│   ├── Instruction_Identifier.cpp/.h
│   ├── MNE2701_Legv8_Sim.cpp    # Main simulation loop
│   └── MNE2701_Legv8_Sim.vcxproj
├── assembly_test/                # Tests for arithmetic, branch, transfer
│   ├── Arithemtic/
│   ├── Branch/
│   └── DataTransfer/
├── bubble_sort/                  # Partial implementation of bubble sort
├── Latex/                        # LaTeX report files and screenshots
│   └── CCE2017.pdf
└── README.md
```

---

## ⚙️ Functional Components

Each module plays a specific role in the simulation of the datapath:

- `Instruction_Memory` – Loads `.text` file and handles instruction fetch
- `ControlUnit` – Decodes opcode and sets all control signals
- `Multiplexers` – Reg2, ALU, Data, and PC input selection
- `Registers` – Handles register file read/write with XZR (X31 = 0)
- `SignExtend` – Extends various immediate formats depending on instruction
- `ALU_Control` – Selects operation based on ALUOp and funct fields
- `ALU` – Executes arithmetic/logic ops, with support for SUBS and PASS flags
- `DataMemory` – Loads `.data` into memory and performs memory access

All components are wired inside `MNE2701_Legv8_Sim.cpp`, which handles clocked execution, register/memory state updates, and output logging.

---

## 🧪 Test Cases

The simulator was validated using three main categories:

- **Arithmetic**: Testing `ADD`, `SUB`, `ADDI`, `SUBI`
- **Branching**: With `CBZ`, `CBNZ`, `B`, `B.HS`, `SUBS`
- **Data Transfer**: With `LDURB`, `STURB`

Each test folder contains:
- `.s`: Assembly source
- `.data`: Initial memory contents
- `.text`: Instruction file
- `.txt`: Expected output and register/memory state

---

## 🔁 Bubble Sort (Bonus Task)

An attempt was made to implement a **bubble sort algorithm** using the supported instructions. Though the first iteration executes correctly, the loop fails to continue due to suspected PC multiplexer logic or branch condition error.

> 📄 Output and source can be found under the `bubble_sort/` directory.

---

## ⚙️ Build Instructions

To compile the simulator:
```bash
g++ -std=c++17 -I MNE2701_Legv8_Sim/ MNE2701_Legv8_Sim/*.cpp -o legv8_sim
```
To run a test case:
```bash
./legv8_sim
```
Edit hardcoded paths for `.data` and `.text` inside `DataMemory.cpp` and `Instruction_Memory.cpp` as needed.

---

## 📘 Report

📄 Full documentation of architecture, modules, and testing is available at [`Latex/CCE2017.pdf`](Latex/CCE2017.pdf)

---

## 👨‍💻 Author

**Graham Pellegrini**  
University of Malta – Department of Computer Engineering  
GitHub: [@GrahamPellegrini](https://github.com/GrahamPellegrini)
