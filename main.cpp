#include "Car.h"
#include <iostream>

// Funkcja wizualizuj¹ca stan samochodu
void visualizeCarState(const Car& car) {
    std::cout << "------------------------\n";
    std::cout << "Current Car State:\n";
    std::cout << "Engine: " << (car.isEngineOn() ? "On" : "Off") << "\n";
    std::cout << "Gear: " << car.getGear() << "\n";
    std::cout << "Speed: " << car.getSpeed() << " km/h\n";
    std::cout << "Engine RPM: " << car.getEngineRpm() << "\n";
    std::cout << "Fuel level: " << car.getFuelLevel() << " liters\n";
    std::cout << "Engine state: " << (car.isEngineDamaged() ? "Damaged" : "Ok") << "\n";
    std::cout << "------------------------\n";
}

int main() {
    Car car;

    int choice;
    do {
        std::cout << "Car Simulation Program\n";
        std::cout << "1. Turn on engine\n";
        std::cout << "2. Turn off engine\n";
        std::cout << "3. Change gear\n";
        std::cout << "4. Accelerate\n";
        std::cout << "5. Brake\n";
        std::cout << "6. Check car state\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            car.turnOnEngine();
            break;
        case 2:
            car.turnOffEngine();
            break;
        case 3: {
            int newGear;
            std::cout << "Enter new gear: ";
            std::cin >> newGear;
            car.changeGear(newGear);
            break;
        }
        case 4: {
            int acceleration;
            std::cout << "Enter acceleration: ";
            std::cin >> acceleration;
            car.accelerate(acceleration);
            break;
        }
        case 5: {
            int brakeForce;
            std::cout << "Enter brake force: ";
            std::cin >> brakeForce;
            car.brake(brakeForce);
            break;
        }
        case 6:
            visualizeCarState(car);
            break;
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}
