//#include <iostream>
//#include <math.h>
//#include <vector>
//#include "celestialbody.h"
//#include "solver.h"
//#include "initial.h"
//
//int main()
//{
//  std::cout << g << std::endl;
//    initialise earth mass, velocity, position, acceleration.
//  celestialbody earth(
//      m_earth, std::vector<double>{0, 30},
//      std::vector<double>{-earth_sun, 0},
//      std::vector<double>{0,0});
//    init sun mass, position, velocity and acceleration.
//  celestialbody sun(
//      m_sun, std::vector<double>{0, 0},
//      std::vector<double>{0, 0},
//      std::vector<double>{0,0});
//      std::cout << "initial positions" << std::endl
//            << "earth: " << earth.getx() << " " << earth.gety() << std::endl
//            << "sun: " << sun.getx() << " " << sun.gety() << std::endl
//            << "distance " << sqrt(solver::distance_sq(earth, sun)) << std::endl
//            << "angle: " << solver::angle(earth, sun) * 180 / 3.14159 << " deg" << std::endl
//            << "velocity: " << sqrt(pow(earth.getvx(), 2) + pow(earth.getvy(), 2))
//            << std::endl
//            << std::endl;
//  double curr_time = 0;
//  for (int i = 0; curr_time < t_tot; i++)
//  {
//    solver::verlet(sun, earth);
//    curr_time = curr_time + dt;
//    std::cout << "current angle: " << solver::angle(earth,sun) * 180 / 3.14159 << std::endl;
//    std::cout << curr_time << std::endl;
//  }
//
//  std::cout << "final positions" << std::endl
//            << "earth: " << earth.getx() << " " << earth.gety() << std::endl
//            << "sun: " << sun.getx() << " " << sun.gety() << std::endl
//            << "distance: " << sqrt(solver::distance_sq(earth, sun)) << std::endl
//            << "angle: " << solver::angle(earth, sun) * 180 / 3.14159 << " deg" << std::endl
//            << "velocity: " << sqrt(pow(earth.getvx(), 2) + pow(earth.getvy(), 2))
//            << std::endl;
//  return 0;
//}
//
