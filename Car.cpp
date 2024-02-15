#include "Car.h"
#include <sstream>

Car::Car() : Vehicle() {}

void Car::turnOnEngine() {
    if (!engineDamaged) {
        engineOn = true;
        addActionToHistory("Car Engine turned on.");
        checkState();
    }
    else {
        addActionToHistory("Cannot turn on car engine - engine damaged.");
    }
}

void Car::changeGear(int newGear) {
    if (newGear >= -1 && newGear <= 6) {
        gear = newGear;
        std::stringstream ss;
        ss << "Car Gear changed to: " << gear;
        addActionToHistory(ss.str());
        checkState();
    }
    else {
        addActionToHistory("Invalid car gear.");
    }
}

void Car::accelerate(int amount) {
    if (engineOn) {
        if (fuelLevel > 0) {
            speed += amount;
            engineRpm += amount * 100;
            std::stringstream ss;
            ss << "Car accelerated to: " << speed << " km/h";
            addActionToHistory(ss.str());
            fuelLevel--; // Decrease fuel level by 1
            checkState();
        }
        else {
            addActionToHistory("Cannot accelerate the car - out of fuel.");
        }
    }
    else {
        addActionToHistory("Cannot accelerate the car - engine off.");
    }
}

void Car::brake(int amount) {
    if (engineOn) {
        speed -= amount;
        if (speed < 0) speed = 0;
        std::stringstream ss;
        ss << "Car Braking. Speed: " << speed << " km/h";
        addActionToHistory(ss.str());
        checkState();
    }
    else {
        addActionToHistory("Cannot brake car - engine off.");
    }
}

void Car::checkState() {
    //addActionToHistory("Checking car state.");
    if (fuelLevel == 0) {
        engineDamaged = true;
        addActionToHistory("Engine damaged - no fuel.");
    }
    displayActionHistory();
}

void Car::addActionToHistory(const std::string& action) {
    actionHistory.push_back(action);
}

void Car::displayActionHistory() {
    std::cout << "Action history:\n";
    for (const auto& action : actionHistory) {
        std::cout << "- " << action << "\n";
    }
}