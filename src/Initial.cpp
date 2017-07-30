#include "Initial.h"

double G = 6.67e-20;                   // Universal gravitational constant km^3 kg^-1 days^-2
double m_sun = 1.98e30;                // Mass of sun in kg
double m_earth = 5.972e24;             // Mass of earth in kg
double earth_sun = 149.6e6;            // Earth sun distance in km
double t_tot = 5 * 365 * 24 * 60 * 60; // Time to run for
int Nt = t_tot * 10;                   // Number of timesteps
double dt = t_tot / Nt;                // Timestep size
