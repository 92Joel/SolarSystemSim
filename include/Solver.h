#include <iostream>
#include <math.h>
#include <vector>
#include "CelestialBody.h"

#ifndef SOLVER_H
#define SOLVER_H
namespace Solver {
    
    // Verlet solver method
     void verlet(CelestialBody &body1, CelestialBody &body2);
    // Calculate angle between two objects
     double angle(CelestialBody &body1, CelestialBody &body2);
    // Calculate grav force on an object
     double force(CelestialBody &body1, CelestialBody &body2);
    // Returns squared distance between two objects
     double distance_sq(CelestialBody &body1, CelestialBody &body2);

};

#endif