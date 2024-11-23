
#include "components.h"
#include <fstream>
#include <sstream>

// Signal Block Design
class SignalBlock {
public:
    Amplifier amp;
    Attenuator att;
    Switch sw1, sw2;
    PowerDivider pd;

    SignalBlock(Amplifier a, Attenuator at, Switch s1, Switch s2, PowerDivider p)
        : amp(a), att(at), sw1(s1), sw2(s2), pd(p) {}

    void simulate(double inputPower, double frequency, bool state1, bool state2, ostream &output) {
        double output1 = sw1.computeOutput(att.computeOutput(amp.computeOutput(inputPower, frequency)), frequency);
        double output2 = sw2.computeOutput(att.computeOutput(amp.computeOutput(inputPower, frequency)), frequency);

        // Adjust for ON/OFF states
        if (!state1) output1 = -100; // Assume leakage
        if (!state2) output2 = -100;

        // Print Results
        output << "Output P1: " << output1 << " dBm\n";
        output << "Output P2: " << output2 << " dBm\n";
    }
};

int main() {
    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file!" << endl;
        return 1;
    }

    // Output file
    ofstream outputFile("output.txt");

    // Read components from input
    string line;
    getline(inputFile, line);
    istringstream iss(line);

    // Example Components
    double ampCost, ampGain1, ampGain20, attCost, attAttenuation, swCost, pdCost;
    iss >> ampCost >> ampGain1 >> ampGain20 >> attCost >> attAttenuation >> swCost >> pdCost;

    Amplifier amp(ampCost, ampGain1, ampGain20);
    Attenuator att(attCost, attAttenuation);
    Switch sw1(swCost, true);
    Switch sw2(swCost, false);
    PowerDivider pd(pdCost);

    // Create signal block
    SignalBlock block(amp, att, sw1, sw2, pd);

    // Simulate multiple scenarios
    double inputPower = 9.0; // Example input power in dBm
    block.simulate(inputPower, 1.0, true, false, outputFile); // 1 GHz, ON/OFF
    block.simulate(inputPower, 20.0, false, true, outputFile); // 20 GHz, OFF/ON

    // Close files
    inputFile.close();
    outputFile.close();

    cout << "Simulation complete. Results are saved in output.txt." << endl;
    return 0;
}
