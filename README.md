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

This project simulates a **single-cycle implementation** of the LEGv8 processor architecture as part of the University of Malta’s study unit [CCE2017](https://www.um.edu.mt/courses/studyunit/CCE2017). The simulator replicates the main datapath components and control logic, executing LEGv8 assembly instructions for:

- **Arithmetic and Logical Operations**
- **Data Transfer (Load/Store)**
- **Branch Instructions**
- **Bubble Sort Routine Simulation**

Assembly test cases and outputs are provided across all key instruction classes.

> 📘 Refer to the accompanying [report](CCE2017.pdf) for design rationale, component implementation details, and testing methodology.

---

## 🗂️ Repository Structure

```bash
.
├── MNE2701_Legv8_Sim/               # Core C++ simulator source
│   ├── ALU_Control.*                # ALU control unit
│   ├── ALU.*                        # Arithmetic Logic Unit
│   ├── ControlUnit.*               # Main control signal logic
│   ├── DataMemory.*                # Memory read/write simulation
│   ├── Instruction_*.cpp/.h        # Instruction decode and identification
│   ├── Multiplexer modules         # Various signal selectors
│   ├── Registers.*                 # Register file management
│   ├── SignExtend.*                # Sign extension for immediates
│   ├── MNE2701_Legv8_Sim.cpp       # Main simulator driver
│   └── *.vcxproj / *.sln           # Visual Studio build files
├── assembly_test/                  # Instruction class test programs
│   ├── Arithmetic/                 # Arithmetic operations
│   ├── Branch/                     # Conditional branching
│   └── DataTransfer/              # Load/store tests
├── bubble_sort/                    # LEGv8 assembly implementation of bubble sort
├── .gitignore
├── README.md
└── CCE2017.pdf                     # 📄 Final course project report
```

---

## ⚙️ Build & Run

To compile and run the simulator:

1. Ensure a C++17 compatible compiler is available (e.g. `g++`, MSVC).
2. Compile all `.cpp` files inside `MNE2701_Legv8_Sim/`.
3. Provide `.s`, `.data`, and `.text` files as input to simulate a test case.

> Assembly input/output examples can be found under `assembly_test/` and `bubble_sort/` folders.

---

## 🧪 Assembly Test Programs

Each test case includes:
- `*.s`: Assembly code
- `*.data`: Data section
- `*.text`: Instruction section
- `*.txt`: Expected output for validation

These span tests for:
- **Arithmetic**: Basic math, register interactions
- **Data Transfer**: Memory read/write correctness
- **Branch**: Proper PC updates and condition handling
- **Bubble Sort**: Algorithmic logic across memory

---

## 👨‍💻 Author

**Graham Pellegrini**  
University of Malta – Department of Computer Engineering  
GitHub: [@GrahamPellegrini](https://github.com/GrahamPellegrini)

---

## 📘 Report

📄 Full report available here: [`CCE2017.pdf`](CCE2017.pdf)
