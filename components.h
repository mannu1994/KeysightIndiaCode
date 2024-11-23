
#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Base class for all components
class Component {
public:
    double cost; // Cost of the component
    virtual double computeOutput(double inputPower, double frequency) = 0;
};

// Amplifier Class
class Amplifier : public Component {
public:
    double gain_1GHz, gain_20GHz;

    Amplifier(double cost, double gain1, double gain20) {
        this->cost = cost;
        this->gain_1GHz = gain1;
        this->gain_20GHz = gain20;
    }

    double computeOutput(double inputPower, double frequency) override {
        double gain = (frequency == 1) ? gain_1GHz : gain_20GHz;
        return inputPower + gain;
    }
};

// Attenuator Class
class Attenuator : public Component {
public:
    double attenuation;

    Attenuator(double cost, double attenuation) {
        this->cost = cost;
        this->attenuation = attenuation;
    }

    double computeOutput(double inputPower, double frequency) override {
        return inputPower - attenuation;
    }
};

// Switch Class
class Switch : public Component {
public:
    bool isOn;

    Switch(double cost, bool state) {
        this->cost = cost;
        this->isOn = state;
    }

    double computeOutput(double inputPower, double frequency) override {
        return isOn ? inputPower : -100; // Assume -100 dBm leakage for OFF state
    }
};

// Power Divider Class
class PowerDivider : public Component {
public:
    PowerDivider(double cost) {
        this->cost = cost;
    }

    double computeOutput(double inputPower, double frequency) override {
        return inputPower - 6.0; // Fixed 6 dB loss
    }
};

#endif // COMPONENTS_H
