// #include <iostream>
// #include <math.h>
// #include <vector>
// #include "CelestialBody.h"
// #include "VectorNd.h"

// // void Solver::CalculateAcceleration(CelestialBody &body1, CelestialBody &body2)
// // {
// //   // Vector of body 1 to body 2.
// //   r12 = body2.position - body1.position;
// //   /* 
// //   Vector formulation of gravitational force.
// //   Force exerted on body 2 by body 1.
// //   */
// //   distance_sq = pow(r12.magnitude(),2);
// //   F21 = -(G * body1.m1 * body2.mass / distance_sq) * r12.unit();
// //   body2.acceleration = F21 / body2.mass;
// //   body1.acceleration = -F21 / body1.mass;
// // }

// // void Solver::ComputePosition(CelestialBody &body1)
// // {
// //   position = body1.position + body1.velocity * dt + 0.5*body1.acceleration * pow(dt,2);
// // }