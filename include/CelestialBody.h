#include <iostream>
#include <math.h>
#include <vector>

#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H

class CelestialBody {
  double mass;
  std::vector<double> velocity;
  std::vector<double> position;

public:
  CelestialBody(double m, std::vector<double> v, std::vector<double> p) {
    mass = m;
    velocity = v;
    position = p;
  } // Constructor

  ~CelestialBody();
  void setP(double X, double Y) {
    position[0] = X;
    position[1] = Y;
  }
  void setV(double Vx, double Vy) {
    velocity[0] = Vx;
    velocity[1] = Vy;
  }

  double getX() { return position[0]; }
  double getY() { return position[1]; }           // Access position components
  std::vector<double> getP() { return position; } // Position vector accessor

  double getVx() { return velocity[0]; } // Access velocity components
  double getVy() { return velocity[1]; }
  std::vector<double> getV() { return velocity; } // Velocity vector accessor
  double getM() { return mass; }                  // Access mass
};

inline CelestialBody::~CelestialBody() {} // Must be declared inline to prevent multiple definitions

#endif