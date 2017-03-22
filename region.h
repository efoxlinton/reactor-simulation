#ifndef REGION_H
#define REGION_H

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "material.h"
#include "URANIUM235.h"
#include "URANIUM238.h"
#include "BARIUM144.h"
#include "KRYPTON89.h"
#include "XENON140.h"
#include "STRONTIUM94.h"

#define SPHERE 1   //types of shapes we can have
#define RECT_PRISM 2
#define CYLINDER 3

using std::ofstream;
using std::ostream;
using std::string;

/************************************
Can define regions of different shapes based on constants above
1) SPHERE: Constructor: Region(double xx, double yy, double zz, double r)
    give coordinates of center and radies
2) Rectangular Prism, Constructor: Region(double xx, double yy, double zz, double dx, double dy, double dz);
    give coordinates of center and widths in x, y, and z directions
3) Cylinder, Constructor:   Region(double xx, double yy, double zz, double r, double xaxis, double yaxis, double zaxis)
   give coordinates of center, radius, and height -- height is specified by making xaxis, yaxis, or zaxis = height, depending
   on orientaion of cylinder.  Other two are set negative.
*************************************/

class Region {
 private:
  int type;  //SPHERE, RECT_PRISM, CYLINDER as defined in constants above
  double x;
  double y;
  double z;
  double radius;
  double delta_x;
  double delta_y;
  double delta_z;
  double volume;
  double number_densities[N_ELEMENTS];
  long long excess[N_ELEMENTS];  //keep track of nuclei added that are too few to affect number_dnnsity.  Wait until they accumulate enough to have an effect
  long long excess_max[N_ELEMENTS]; //level at which excess array cleared and number_density updated

 public:
  //constructors
  Region();
  Region(double xx, double yy, double zz, double r);  //sphere constructor
  Region(double xx, double yy, double zz, double dx, double dy, double dz);  //rectangular constructor
  Region(double xx, double yy, double zz, double r, double xaxis, double yaxis, double zaxis);  //cylinder constructor

  //set functions
  void set_type(int t) {type = t;}
  void set_x(double xx) {x = xx;}
  void set_y(double yy) {y = yy;}
  void set_z(double zz) {z = zz;}
  void set_radius(double r) {radius = r;}   //note, setting parameters does not re-calculate volume
  void set_delta_x(double dx) {delta_x = dx;}
  void set_delta_y(double dy) {delta_y = dy;}
  void set_delta_z(double dz) {delta_z = dz;}
  void calc_volume();  //re-calculate volume.  Must be used after changing type, radius, delta_x, etc.
  void set_density(int i, double rho);  //set number density of ith species
  void add_nuclei(int i, long long num_added);  //add num_added nuclei of ith species.  Note, can handle negative num_added

  //accessors
  double get_density(int i){if (i < N_ELEMENTS) { return number_densities[i];} else {return 0;}}

  //other functions
  bool is_in_region(double xx, double yy, double zz);  //return true if xx, yy, zz is in region

  //destructor
  ~Region() {}
};


#endif  //ifndef REGION_H
