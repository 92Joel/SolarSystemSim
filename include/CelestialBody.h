#include <iostream>

#ifndef CELSTIALBODY_H
#define CELESTIALBODY_H
class CelestialBody
{
    double mass;
    std::vector<double> velocity(3);
    std::vector<double> position(3);

    CelestialBody(double m, std::vector<double> v(3), std::vector<double> p(3));
};

#endif 