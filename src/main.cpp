#include <iostream>
#include <vector>
#include <string>

#include "CelestialBody.h"
#include "VectorNd.h"
#include "Initial.h"
#include "Solver.h"

int main()
{
    CelestialBody<double> earth(m_earth, "Earth", {earth_sun, 0, 0}, {0, 30000, 0}, {0, 0, 0});
    CelestialBody<double> sun(m_sun, "Sun", {0, 0, 0}, {0, 0, 0}, {0, 0, 0});
    int time_taken = 0;
    for (int time_taken = 0; time_taken < t_tot; time_taken += dt)
    {
        Solver<double>::Compute(earth, sun);
        // Solver<double>::Compute(sun,earth);
    }
    earth.Print();
    // sun.Print();
    std::cout << earth_sun;
    return 0;
}