#include <iostream>
#include <math.h>
#include <vector>

double G = 6.67e-20;        // Universal gravitational constant km^3 kg^-1 days^-2
double m_sun = 1.98e30;        // Mass of sun in kg
double m_earth = 5.972e24;  // Mass of earth in kg 
double earth_sun = 149.6e6; // Earth sun distance in km 
double t_tot = 5*365*24*60*60; // Time to run for
int Nt = t_tot*10;        // Number of timesteps
double dt = t_tot / Nt;     // Timestep size

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

CelestialBody::~CelestialBody() {}

double distance_sq(CelestialBody &body1, CelestialBody &body2);
double angle(CelestialBody &body1, CelestialBody &body2);
double force(CelestialBody &body1, CelestialBody &body2);
void verlet(CelestialBody &body1, CelestialBody &body2);

int main() {
  CelestialBody earth(
      m_earth, std::vector<double>{0, 30},
      std::vector<double>{-earth_sun,
                          0}); // Initialise Earth mass, velocity and position.
  CelestialBody sun(
      m_sun, std::vector<double>{0, 0},
      std::vector<double>{0, 0}); // Init Sun mass, position and velocity.
  std::cout << "Initial positions" << std::endl
            << "Earth: " << earth.getX() << " " << earth.getY() << std::endl
            << "Sun: " << sun.getX() << " " << sun.getY() << std::endl
            << "Distance " << sqrt(distance_sq(earth, sun)) << std::endl
            << "Angle: " << angle(earth, sun) * 180 / 3.14159 << " deg" << std::endl
            << "Velocity: " << sqrt(pow(earth.getVx(), 2) + pow(earth.getVy(), 2))
            << std::endl
            << std::endl;
  double curr_time = 0;
  for (int i = 0; curr_time < t_tot; i++) {
    verlet(sun, earth);
    curr_time = curr_time + dt;
    // std::cout << "Current angle: " << angle(earth,sun) << std::endl;
    // std::cout << earth.getVx() << std::endl;
    if (sqrt(distance_sq(sun, earth)) < 1000) {
      std::cout << "Collision! \n" << curr_time << std::endl;
      break;
    }
  }

  std::cout << "Final positions" << std::endl
            << "Earth: " << earth.getX() << " " << earth.getY() << std::endl
            << "Sun: " << sun.getX() << " " << sun.getY() << std::endl
            << "Distance: " << sqrt(distance_sq(earth, sun)) << std::endl
            << "Angle: " << angle(earth, sun) * 180 / 3.14159 << " deg" << std::endl
            << "Velocity: " << sqrt(pow(earth.getVx(), 2) + pow(earth.getVy(), 2))
            << std::endl;
  return 0;
}

double distance_sq(CelestialBody &body1, CelestialBody &body2) {
  return pow(body1.getX() - body2.getX(), 2) +
         pow(body1.getY() - body2.getY(), 2);
} // Returns square of the distance

double angle(CelestialBody &body1, CelestialBody &body2) {
  double deltaY = body2.getY() - body1.getY();
  double deltaX = body2.getX() - body1.getX();
  return atan2(deltaY, deltaX);
}

double force(CelestialBody &body1, CelestialBody &body2) {
  return G * body1.getM() * body2.getM() / distance_sq(body1, body2);
}

void verlet(CelestialBody &body1, CelestialBody &body2) {
  // Acceleration of each body initialised to (0,0)
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
