#include "vehicleInfo.hpp"
#include <iostream>

int main()
{
    Info Vehicle;
    double aggAcc = Vehicle.aggressiveAcc;
    double comfAcc = Vehicle.comfortableAcc;
    std::cout << "Aggressive Acceleration is: " << aggAcc << "m/s" << std::endl;
    std::cout << "Comfortable Acceleration is: " << comfAcc << "m/s" << std::endl;
}