#include "Initial.h"

const double G = 6.67449e-11;                   // Universal gravitational constant km^3 kg^-1 s^-2
const double m_sun = 1.98e30;                // Mass of sun in kg
const double m_earth = 5.972e24;             // Mass of earth in kg
const double earth_sun = 149597870700;            // Earth sun distance in km
const double t_tot = 20*365 * 24 * 60 * 60;     // Time to run for
const int Nt = t_tot * 0.01;                   // Number of timesteps
const double dt = 1000;                // Timestep size
