#include <iostream>

// Add guards

class Model
{
    double wheelRadius;
    double wheelToCenter;

    public:

    void getWheelRadius()
    {
        std::cout << "Enter wheel radius: " << std::endl;
        std::cin >> wheelRadius;
    }

    void getWheelToCenter()
    {
        std::cout << "Enter wheel to center distance: " << std::endl;
        std::cin >> wheelToCenter;
    }
};