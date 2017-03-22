/**********************************
region.cxx
implementation of region.h
***********************************/

#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "region.h"

using std::cerr;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::ios;

Region::Region() {
  type = SPHERE;
  x = y = z = 0;
  radius = 1;
  delta_x = delta_y = delta_z = -1;
  volume = 4.0/3.0*3.14159265;

  for (int i=0; i<N_ELEMENTS; i++) {
    number_densities[i] = 0;
    excess[i] = 0;
    excess_max[i] = 0;
  }
}

//for sphere, give coordinates of center and radius
Region::Region(double xx, double yy, double zz, double r) { //sphere
  type = SPHERE;
  x = xx;   
  y = yy;
  z = zz;
  radius = r;
  delta_x = delta_y = delta_z = -1;  //not used for sphere
  volume = 4.0/3.0*3.14159265*radius*radius*radius;

  //densities will be set later, so just set to 0 for now
  for (int i=0; i<N_ELEMENTS; i++) {
    number_densities[i] = 0;
    excess[i] = 0;
    excess_max[i] = 0;
  }
}

//for rectangular prism, give coordinates of center and height, width, and depth
Region::Region(double xx, double yy, double zz, double dx, double dy, double dz) { //rectangular prism
  type = RECT_PRISM;
  x = xx;   
  y = yy;
  z = zz;
  delta_x = dx;
  delta_y = dy;
  delta_z = dz;
  radius = -1;  //not used for rectangular prism
  volume = delta_x*delta_y*delta_z;

  //densities will be set later, so just set to 0 for now
  for (int i=0; i<N_ELEMENTS; i++) {
    number_densities[i] = 0;
    excess[i] = 0;
    excess_max[i] = 0;
  }
}

//for cylinder, give coordinates of center and radius.  Of xaxis, yaxis, and zaxis, two should be set to a negative value.  Third
//will be height of cylinder.  The symmetry axis will be the one with the non-negative value
//function will actually take largest of three as symmetry axis
Region::Region(double xx, double yy, double zz, double r, double xaxis, double yaxis, double zaxis) { //cylinder
  type = CYLINDER;
  x = xx;   
  y = yy;
  z = zz;
  radius = r;
  delta_x = xaxis;
  delta_y = yaxis;
  delta_z = zaxis;

  //choose cylinder height as largest of delta_x, delta_y, delta_z
  double cylinder_height = delta_x;
  if (delta_y > cylinder_height) {
    cylinder_height = delta_y;
  }
  if (delta_z > cylinder_height) {
    cylinder_height = delta_z;
  }

  volume = 3.14159265*radius*radius*cylinder_height;

  //densities will be set later, so just set to 0 for now
  for (int i=0; i<N_ELEMENTS; i++) {
    number_densities[i] = 0;
    excess[i] = 0;
    excess_max[i] = 0;
  }
}

void Region::calc_volume() {
  if (type == SPHERE) {
    volume = 4.0/3.0*3.14159265*radius*radius*radius;
  } else if (type == RECT_PRISM) {
    volume = delta_x*delta_y*delta_z;
  } else { //cylinder
    if (delta_x >= delta_y && delta_x >= delta_z) {
      volume = 3.14159265*radius*radius*delta_x;
    } else if (delta_y >= delta_x && delta_y >= delta_z) {
      volume = 3.14159265*radius*radius*delta_y;
    } else {
      volume = 3.14159265*radius*radius*delta_z;
    }
  }
}

void Region::set_density(int i, double rho) {
  if (i >= 0 && i < N_ELEMENTS) {
    number_densities[i] = rho;
    excess[i] = 0;                      
    excess_max[i] = floor(volume*rho*1e-10);  //double has ~15 digits, so 1e-10 gives 5 digits leeway
    if (excess_max[i] < 1) {
      excess_max[i] = 1;
    }
  }
    
}

void Region::add_nuclei(int i, long long num_added) {
  excess[i] += num_added;

  int sign = 1;

  if (excess[i] < 0) {
    sign = -1;
  }

  if (abs(excess[i]) >= excess_max[i]) {
    number_densities[i] += sign*(excess_max[i]*(abs(excess[i])/excess_max[i]))/volume;
    excess[i] = sign*abs(excess[i])%excess_max[i];

    if (number_densities[i] < 0) {
      number_densities[i] = 0;
    }

    //re-calculate excess_max
    excess_max[i] = floor(volume*number_densities[i]*1e-10);  //double has ~15 digits, so 1e-10 gives 5 digits leeway
    if (excess_max[i] < 1) {
      excess_max[i] = 1;
    }
			    
  }
}

bool Region::is_in_region(double xx, double yy, double zz) {

  //calculate distance from center
  double dx = xx - x;
  double dy = yy - y;
  double dz = zz - z;


  if (type == SPHERE) {
    if (dx*dx + dy*dy + dz*dz <= radius*radius) {
      return true;
    } else {
      return false;
    }
  } else if (type == RECT_PRISM) {
    if ((fabs(dx) <= 0.5*delta_x) && (fabs(dy) <= 0.5*delta_y) && (fabs(dz) <= 0.5*delta_z)) {
      return true;
    } else {
      return false;
    }
  } else { //cylinder
    if (delta_x >= delta_y && delta_x >= delta_z) { //axis along x
      if ((dy*dy + dz*dz <= radius*radius) && (fabs(dx) <= 0.5*delta_x)) {
	return true;
      } else {
	return false;
      }
    } else if (delta_y >= delta_x && delta_y >= delta_z) { //axis along y
      if((dx*dx + dz*dz <= radius*radius) && (fabs(dy) <= 0.5*delta_y)) {
	return true;
      } else {
	return false;
      }
    } else { //axis along z
      if ((dx*dx + dy*dy <= radius*radius) && (fabs(dz) <= 0.5*delta_z)) {
	return true;
      } else {
	return false;
      }
    }
  }  //end if cylinder
} //end is_in_region
