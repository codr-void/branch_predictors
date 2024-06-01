
# Branch Prediction Simulation

This simulation evaluates the performance of 1-bit and 2-bit branch predictors by analyzing a sequence of branch outcomes from a trace file.

## Prerequisites

You will need a C++ compiler such as g++ to compile and run this simulation.

## Compilation Instructions

1. **Download the source files**:
   Ensure that you have `main.cpp`, `predictors.cpp`, and `predictors.h` downloaded to your local machine.

2. **Compile the Program**:
   Open a terminal in the directory where the files are located and compile the program using the following command:
   ```bash
   make all
   ```
   This command will compile the source files and link them into a single executable named `branch_predictor`.

3. **Run the Program**:
   Execute the program with:
   ```bash
   ./main
   ```

   This will run the simulation and output the accuracy of the 1-bit and 2-bit predictors based on the branch outcomes provided in the `trace.txt` file.

## Input Data

The program requires a trace file named `trace.txt` located in the same directory as the executable. This file should contain branch outcomes in the format:
```
[address] [outcome]
```
Where `[outcome]` is `T` for Taken and `NT` for Not Taken.
