#include <iostream>
#include <math.h>
#include <vector>

#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

class CelestialBody {
  double mass;
  std::vector<double> velocity;
  std::vector<double> position;
  std::vector<double> acceleration;

public:
  CelestialBody(double m, std::vector<double> v, std::vector<double> p, std::vector<double> a) 
  {
    mass = m;
    velocity = v;
    position = p;
    acceleration = a;
  } // Constructor

  ~CelestialBody();
  inline void setP(double X, double Y) {
    position[0] = X;
    position[1] = Y;
  }
  inline void setV(double Vx, double Vy) {
    velocity[0] = Vx;
    velocity[1] = Vy;
  }

  // Get position and individual components
  double getX() { return position[0]; }
  double getY() { return position[1]; }  
  std::vector<double> getP() { return position; } 

  // Get velocity and individual components
  double getVx() { return velocity[0]; } 
  double getVy() { return velocity[1]; }
  std::vector<double> getV() { return velocity; } 

  // Get acceleration and individual components
  double getAx() {return acceleration[0];}
  double getaY() {return acceleration[1];}
  std::vector<double> getA() {return acceleration;}
  double getM() { return mass; }                  // Access mass
};

inline CelestialBody::~CelestialBody() {} // Must be declared inline to prevent multiple definitions

#endif