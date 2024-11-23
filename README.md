
# Signal Block Simulation

## Overview
This project simulates a signal distribution block that takes one input signal and splits it into two outputs. The block supports multiple operating states (ON/OFF combinations) and adheres to specified performance criteria such as maximum power levels, leakage, and resolution. The solution optimizes cost by selecting appropriate components like amplifiers, attenuators, switches, and power dividers.

## Project Structure
The project consists of the following files:
1. `components.h` - Header file defining the component classes (Amplifier, Attenuator, Switch, PowerDivider).
2. `main.cpp` - Main implementation file containing the signal block simulation logic.
3. `input.txt` - Input file containing the component specifications.
4. `CMakeLists.txt` - Build configuration file for compiling the project using CMake.

## How to Use
### Prerequisites
- A C++ compiler supporting C++11 or higher (e.g., g++).
- CMake version 3.10 or higher.

### Steps to Build and Run
1. **Clone or Copy Files**:
   Copy all the provided files (`components.h`, `main.cpp`, `input.txt`, `CMakeLists.txt`) into a directory.

2. **Build the Project**:
   Open a terminal in the directory and run the following commands:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Run the Simulation**:
   After successful compilation, run the program:
   ```
   ./SignalBlockSimulation
   ```

4. **View Results**:
   The program will generate an output file named `output.txt` containing the simulation results.

### Input Format
The input file `input.txt` specifies the components used in the simulation. The format is:
```
<Amplifier_Cost> <Amplifier_Gain_1GHz> <Amplifier_Gain_20GHz> <Attenuator_Cost> <Attenuator_Attenuation> <Switch_Cost> <PowerDivider_Cost>
```
For example:
```
45 15 12 19 5 13 0
```

### Output
The output file `output.txt` contains the results of the simulation, including the output power levels for each state:
```
Output P1: <value> dBm
Output P2: <value> dBm
```

## Example
#### Input (input.txt):
```
45 15 12 19 5 13 0
```

#### Output (output.txt):
```
Output P1: 19 dBm
Output P2: -100 dBm
Output P1: -100 dBm
Output P2: 16 dBm
```

## Notes
- Ensure the input file is formatted correctly; otherwise, the program may fail to parse the input.
- The program assumes certain fixed values for leakage (-100 dBm) when a switch is OFF.

## License
This project is provided for educational purposes. Feel free to modify and use it as needed.
