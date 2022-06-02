/*
A simple Kinematic Model of a 2-Wheeled 2D Robot
*/

#include "inputData.hpp"
#include <cmath>

class Vehicle
{
    public:

        double calcX(double x_prev, double theta_prev, double omega1, double omega2, double deltaT, double wheelRadius)
        {
            double x_curr = x_prev + (wheelRadius * (omega1 + omega2) / 2 * cos(theta_prev)) * deltaT;
            return x_curr;
        }

        double calcY(double y_prev, double theta_prev, double omega1, double omega2, double deltaT, double wheelRadius)
        {
            double y_curr = y_prev + (wheelRadius * (omega1 + omega2) / 2 * sin(theta_prev)) * deltaT;
            return y_curr;
        }

        double calcTheta(double theta_prev, double omega1, double omega2, double deltaT, double wheelRadius, double wheelToCenter)
        {
            double theta_curr = theta_prev + (wheelRadius * (omega1 - omega2) / (2 * wheelToCenter)) * deltaT;
            return theta_curr;
        }
};
