#include <iostream>
#include <math.h>
#include <vector>
#include "CelestialBody.h"
#include "Solver.h"
#include "Initial.h"

void Solver::verlet(CelestialBody &body1, CelestialBody &body2)
{
    std::vector<double> a1(2, 0.0);
    std::vector<double> a2(2, 0.0);

    std::vector<double> a1p(2, 0.0);
    std::vector<double> a2p(2, 0.0);

    double f = force(body1, body2);
    double theta = angle(body1, body2);
    double fx = f * cos(theta);
    double fy = f * sin(theta);

    a1[0] = -fx / body1.getM();
    a2[0] = fx / body2.getM(); // x components of accel.

    a1[1] = -fy / body1.getM();
    a2[1] = fy / body2.getM();

    // Set positions
    // x = x +v *dt + a*dt*dt/2
    body1.setP(body1.getX() + body1.getVx() * dt + 0.5 * a1[0] * pow(dt, 2),
               body1.getY() + body1.getVy() * dt + 0.5 * a1[1] * pow(dt, 2));

    body2.setP(body2.getX() + body2.getVx() * dt + 0.5 * a2[0] * pow(dt, 2),
               body2.getY() + body2.getVy() * dt + 0.5 * a2[1] * pow(dt, 2));

    // Update acceleeration to a' from new positions.
    double fp = force(body1, body2);
    double thetap = angle(body1, body2);
    double fxp = fp * cos(thetap);
    double fyp = fp * sin(thetap);

    a1p[0] = -fxp / body1.getM();
    a2p[0] = fxp / body2.getM();

    a1p[1] = -fyp / body1.getM();
    a2p[1] = fyp / body2.getM();
    // Update velocities
    // v = v + (a + a')*dt/2
    body1.setV(body1.getVx() + 0.5 * (a1[0] + a1p[0]) * dt,
               body1.getVy() + 0.5 * (a1[1] + a1p[1]) * dt);

    body2.setV(body2.getVx() + 0.5 * (a2[0] + a2p[0]) * dt,
               body2.getVy() + 0.5 * (a2[1] + a2p[1]) * dt);
}

double Solver::distance_sq(CelestialBody &body1, CelestialBody &body2)
{
  return pow(body1.getX() - body2.getX(), 2) +
         pow(body1.getY() - body2.getY(), 2);
} // Returns square of the distance

double Solver::angle(CelestialBody &body1, CelestialBody &body2)
{
  double deltaY = body2.getY() - body1.getY();
  double deltaX = body2.getX() - body1.getX();
  return atan2(deltaY, deltaX);
}

double Solver::force(CelestialBody &body1, CelestialBody &body2)
{
  return G * body1.getM() * body2.getM() / distance_sq(body1, body2);
}