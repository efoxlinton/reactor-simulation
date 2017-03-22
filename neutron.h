#ifndef NEUTRON_H
#define NEUTRON_H

#define Mneut 939.57  //neutron mass in MeV/c^2
#define light_speed 3.0e8            //speed of light in m/s

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>

using std::ofstream;
using std::ostream;
using std::string;



class Neutron {
 private:
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double ke;

 public:
  //constructor
  Neutron();
  Neutron(double xx, double yy, double zz, double new_ke);
  Neutron(double xx, double yy, double zz, double vxx, double vyy, double vzz);

  void move(double dt);
  double get_x() {return x;}
  double get_y() {return y;}
  double get_z() {return z;}
  double get_vx() {return vx;}
  double get_vy() {return vy;}
  double get_vz() {return vz;}
  double get_ke() {return ke;}
  double get_theta() {return acos(vz/sqrt(vx*vx + vy*vy + vz*vz));}
  double get_phi() {return acos(vx/sqrt(vx*vx + vy*vy));}
  double get_speed() {return sqrt(vx*vx + vy*vy + vz*vz);}
  void set_ke(double new_ke);
  void set_x(double xx) {x = xx;}
  void set_y(double yy) {y = yy;}
  void set_z(double zz) {z = zz;}
  void copy(Neutron neut);  //copy Neutron neut to this neutron 

  //destructor
  ~Neutron() {}
};


#endif  //ifndef NEUTRON_H
