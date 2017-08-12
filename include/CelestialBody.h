#include <iostream>
#include <math.h>
#include <vector>
#include <string>

#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

template <class T>
class VectorND;

/*
Class to allow the construction of a celestial body.
*/

template <class T>
class CelestialBody
{
  
  T mass;
  std::string name;
  VectorND<T> velocity;
  VectorND<T> position;
  VectorND<T> acceleration;

  public:
  // Constructor
  constexpr CelestialBody(const T &m, const std::string &n, std::vector<T> &&p,
                std::vector<T> &&v, std::vector<T> &&a) : mass(m), name(n), velocity(v), position(p), acceleration(a){};

  // Print to console the body's attributes.
  void Print();
  // // Compute the current position.
  // void ComputePosition();
  // // Compute the acceleration due to the gravitational field
  // void CalculateAcceleration();
  // //Calculate the Velocity using the Verlet algorithm
  // void VelocityVerlet();

  // T distance_sq(&body2);

  // Friend class defined in /src/Solver2.h
  template <class U> friend class Solver;

  ~CelestialBody();
};

template <class T>
inline CelestialBody<T>::~CelestialBody() {} // Must be declared inline to prevent multiple definitions

template <class T>
void CelestialBody<T>::Print()
{
    std::cout << name << std::endl 
    << "Mass: " << mass << std::endl
    << "Velocity: " << velocity
    << "Position: " << position
    << "Acceleration: " << acceleration << std::endl;
}


#endif