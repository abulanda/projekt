#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <vector>

class Vehicle {
protected:
    bool engineOn;
    int gear;
    int speed;
    int engineRpm;
    int fuelLevel; // in liters
    bool engineDamaged;
    std::vector<std::string> actionHistory;

public:
    Vehicle();
    virtual ~Vehicle() {} // Virtual destructor for polymorphism
    virtual void turnOnEngine();
    void turnOffEngine();
    virtual void changeGear(int newGear);
    virtual void accelerate(int amount);
    virtual void brake(int amount);
    virtual void checkState();
    void setFuelLevel(int amount);
    void setEngineState(bool damaged);
    void addActionToHistory(const std::string& action);
    void displayActionHistory();
    bool isEngineOn() const { return engineOn; }
    int getGear() const { return gear; }
    int getSpeed() const { return speed; }
    int getEngineRpm() const { return engineRpm; }
    int getFuelLevel() const { return fuelLevel; }
    bool isEngineDamaged() const { return engineDamaged; }
};

#endif
