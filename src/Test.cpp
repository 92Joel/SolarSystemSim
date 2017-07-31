#include <iostream>
#include <math.h>
#include <vector>
#include "CelestialBody.h"
#include "Solver.h"
#include "Initial.h"

int main()
{
  std::cout << G << std::endl;
   // Initialise Earth mass, velocity, position, acceleration.
  CelestialBody earth(
      m_earth, std::vector<double>{0, 30},
      std::vector<double>{-earth_sun, 0},
      std::vector<double>{0,0});
   // Init Sun mass, position, velocity and acceleration.
  CelestialBody sun(
      m_sun, std::vector<double>{0, 0},
      std::vector<double>{0, 0},
      std::vector<double>{0,0});
      std::cout << "Initial positions" << std::endl
            << "Earth: " << earth.getX() << " " << earth.getY() << std::endl
            << "Sun: " << sun.getX() << " " << sun.getY() << std::endl
            << "Distance " << sqrt(Solver::distance_sq(earth, sun)) << std::endl
            << "Angle: " << Solver::angle(earth, sun) * 180 / 3.14159 << " deg" << std::endl
            << "Velocity: " << sqrt(pow(earth.getVx(), 2) + pow(earth.getVy(), 2))
            << std::endl
            << std::endl;
  double curr_time = 0;
  for (int i = 0; curr_time < t_tot; i++)
  {
    Solver::verlet(sun, earth);
    curr_time = curr_time + dt;
    std::cout << "Current angle: " << Solver::angle(earth,sun) * 180 / 3.14159 << std::endl;
    std::cout << curr_time << std::endl;
  }

  std::cout << "Final positions" << std::endl
            << "Earth: " << earth.getX() << " " << earth.getY() << std::endl
            << "Sun: " << sun.getX() << " " << sun.getY() << std::endl
            << "Distance: " << sqrt(Solver::distance_sq(earth, sun)) << std::endl
            << "Angle: " << Solver::angle(earth, sun) * 180 / 3.14159 << " deg" << std::endl
            << "Velocity: " << sqrt(pow(earth.getVx(), 2) + pow(earth.getVy(), 2))
            << std::endl;
  return 0;
}

