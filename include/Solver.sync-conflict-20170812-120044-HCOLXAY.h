#include <iostream>
#include <math.h>
#include <vector>

#include "Initial.h"
// #include "CelestialBody.h"
// #include "VectorNd.h"

#ifndef SOLVER2_H
#define SOLVER2_H

template <class T>
class CelestialBody;

template <class T>
class Solver;

template <class T>
class VectorND;

template <class T>
class Solver
{
  private:
    // Compute the updated positions.
    static void ComputePosition(CelestialBody<T> &body1, CelestialBody<T> &body2);
    // Compute the acceleration due to the gravitational field
    static void CalculateAcceleration(CelestialBody<T> &body1, CelestialBody<T> &body2);
    //Calculate the Velocity using the Verlet algorithm
    static void CalculateVelocity(CelestialBody<T> &body1, CelestialBody<T> &body2);

  public:
    // Compute the entire velocity verlet algorithm.
    static void Compute(CelestialBody<T> &body1, CelestialBody<T> &body2);
};

template <class T>
void Solver<T>::CalculateAcceleration(CelestialBody<T> &body1, CelestialBody<T> &body2)
{
    // Vector of body 1 to body 2.
    VectorND<T> r12 = body2.position - body1.position;
    /* 
  Vector formulation of gravitational force.
  Force exerted on body 2 by body 1.
  */
    T distance_sq = pow(r12.magnitude(), 2);
    VectorND<T> F21 = -(G * body1.mass * body2.mass / distance_sq) * r12.unit();
    body2.acceleration = F21 / body2.mass;
    body1.acceleration = (T)-1 * F21 / body1.mass;
}

template <class T>
void Solver<T>::ComputePosition(CelestialBody<T> &body1, CelestialBody<T> &body2)
{
    body1.position = body1.position + body1.velocity * dt + 0.5 * body1.acceleration * pow(dt, 2);
}

template <class T>
void Solver<T>::CalculateVelocity(CelestialBody<T> &body1, CelestialBody<T> &body2)
{
    VectorND<T> prev_accel1 = body1.acceleration;
    CalculateAcceleration(body1, body2);
    body1.velocity = body1.velocity + 0.5 * (prev_accel1 + body1.acceleration) * dt;
}

template <class T>
void Solver<T>::Compute(CelestialBody<T> &body1, CelestialBody<T> &body2)
{
    ComputePosition(body1, body2);
    CalculateVelocity(body1, body2);
}

#endif