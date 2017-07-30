#include <iostream>
#include <math.h>
#include <vector>
#include "CelestialBody.h"

#ifndef SOLVER_H
#define SOLVER_H
class Solver {
    public:
    // Verlet solver method
     static void verlet(CelestialBody &body1, CelestialBody &body2);

     static double angle(CelestialBody &body1, CelestialBody &body2);

     static double force(CelestialBody &body1, CelestialBody &body2);

     static double distance_sq(CelestialBody &body1, CelestialBody &body2);

};

#endif