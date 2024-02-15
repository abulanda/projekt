#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    ~Car() override {} // Override destructor
    void turnOnEngine() override;
    void changeGear(int newGear) override;
    void accelerate(int amount) override;
    void brake(int amount) override;
    void checkState() override;
    void addActionToHistory(const std::string& action);
    void displayActionHistory();
};

#endif
