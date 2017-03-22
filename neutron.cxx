/**********************************
neutron.cxx
implementation of neutron.h
***********************************/

#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "neutron.h"

using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::ios;

Neutron::Neutron() {
  x = 0;
  y = 0;
  z = 0;
  vx = 0;
  vy = 0;
  vz = 0;
  ke = 0;
}

Neutron::Neutron(double xx, double yy, double zz, double new_ke) {
  x = xx;
  y = yy;
  z = zz;

  set_ke(new_ke);
}

Neutron::Neutron(double xx, double yy, double zz, double vxx, double vyy, double vzz) {
  x = xx;
  y = yy;
  z = zz;
  vx = vxx;
  vy = vyy;
  vz = vzz;

  double beta = sqrt(vx*vx+vy*vy+vz*vz)/light_speed;
  double gamma = 1.0/sqrt(1 - beta*beta);
  ke = (gamma - 1)*Mneut;
}

void Neutron::move(double dt) {
  x += vx*dt;
  y += vy*dt;
  z += vz*dt;
}

void Neutron::set_ke(double new_ke) {
  ke = new_ke;

  //choose random direction so we can set velocities
  double phi = (rand()*2*3.14159265)/RAND_MAX;
  double theta = acos(1 - (2.0*rand())/RAND_MAX);

  double gamma = ke/Mneut + 1;

  double speed = light_speed*sqrt(1-1.0/(gamma*gamma));

  vx = speed*sin(theta)*cos(phi);
  vy = speed*sin(theta)*sin(phi);
  vz = speed*cos(theta); 

}

void Neutron::copy(Neutron neut) {
  x = neut.get_x();
  y = neut.get_y();
  z = neut.get_z();

  vx = neut.get_vx();
  vy = neut.get_vy();
  vz = neut.get_vz();

  //set kinetic energy
  double speed = sqrt(vx*vx + vy*vy + vz*vz);
  double beta = speed/light_speed;
  double gamma = 1.0/sqrt(1- beta*beta);
  ke = (gamma-1)*Mneut;
}
