#include "kinematicModel2D.hpp"

int main()
{
    Input vehicleInput;
    vehicleInput.getFileContent();
    vehicleInput.setCSVContents();
    vehicleInput.setOmega1();
    vehicleInput.setOmega2();
    vehicleInput.setSizeOfInput();
    vehicleInput.setTime();
    vehicleInput.setWheelRadius();
    vehicleInput.setWheelToCenter();

    Vehicle newVehicle;
    int sizeOfInput = vehicleInput.getSizeOfData();
    std::vector<double> omega1 = vehicleInput.getOmega1();
    std::vector<double> omega2 = vehicleInput.getOmega2();
    std::vector<double> time = vehicleInput.getTime();
    std::vector<double> x, y, theta;
    double wheelRadius{vehicleInput.getWheelRadius()}, wheelToCenter{vehicleInput.getWheelToCenter()}; 

    // Assuming zero initial conditions
    double x_curr{0}, x_prev{0}, y_curr{0}, y_prev{0}, theta_curr{0}, theta_prev{0};
    x.push_back(x_curr);
    y.push_back(y_curr);
    theta.push_back(theta_curr);
    
    for(int i{0}; i < sizeOfInput - 1; i++)
    {
        x_curr = newVehicle.calcX(x.back(), theta.back(), omega1[i], omega2[i], time[i+1] - time[i], wheelRadius);
        y_curr = newVehicle.calcY(y.back(), theta.back(), omega1[i], omega2[i], time[i+1] - time[i], wheelRadius);
        theta_curr = newVehicle.calcTheta(theta.back(), omega1[i], omega2[i], time[i+1] - time[i], wheelRadius, wheelToCenter);
        x.push_back(x_curr);
        y.push_back(y_curr);
        theta.push_back(theta_curr);
    }

    // Outputs are stored in x, y, and theta
    std::cout << "Check";
}