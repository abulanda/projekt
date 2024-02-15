#include "Vehicle.h"
#include <sstream>

Vehicle::Vehicle() : engineOn(false), gear(0), speed(0), engineRpm(0), fuelLevel(50), engineDamaged(false) {}

void Vehicle::turnOnEngine() {
    if (!engineDamaged) {
        engineOn = true;
        addActionToHistory("Engine turned on.");
    }
    else {
        addActionToHistory("Cannot turn on engine - engine damaged.");
    }
}

void Vehicle::turnOffEngine() {
    engineOn = false;
    addActionToHistory("Engine turned off.");
}

void Vehicle::changeGear(int newGear) {
    if (newGear >= -1 && newGear <= 6) {
        gear = newGear;
        std::stringstream ss;
        ss << "Gear changed to: " << gear;
        addActionToHistory(ss.str());
    }
    else {
        addActionToHistory("Invalid gear.");
    }
}

void Vehicle::accelerate(int amount) {
    if (engineOn) {
        if (fuelLevel > 0) {
            speed += amount;
            engineRpm += amount * 100;
            std::stringstream ss;
            ss << "Accelerated to: " << speed << " km/h";
            addActionToHistory(ss.str());
            fuelLevel--; // Decrease fuel level by 1
            checkState();
        }
        else {
            addActionToHistory("Cannot accelerate - out of fuel.");
        }
    }
    else {
        addActionToHistory("Cannot accelerate - engine off.");
    }
}


void Vehicle::brake(int amount) {
    if (engineOn) {
        speed -= amount;
        if (speed < 0) speed = 0;
        std::stringstream ss;
        ss << "Braking. Speed: " << speed << " km/h";
        addActionToHistory(ss.str());
    }
    else {
        addActionToHistory("Cannot brake - engine off.");
    }
}

void Vehicle::checkState() {
    if (fuelLevel == 0) {
        engineDamaged = true;
        addActionToHistory("Engine damaged - no fuel.");
    }
}

void Vehicle::setFuelLevel(int amount) {
    fuelLevel = amount;
    checkState(); // Check state whenever fuel level is changed
}

void Vehicle::setEngineState(bool damaged) {
    engineDamaged = damaged;
}

void Vehicle::addActionToHistory(const std::string& action) {
    actionHistory.push_back(action);
}

void Vehicle::displayActionHistory() {
    std::cout << "Action history:\n";
    for (const auto& action : actionHistory) {
        std::cout << "- " << action << "\n";
    }
}
