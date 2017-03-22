#ifndef REACTOR_H
#define REACTOR_H

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
#include "neutron.h"
#include "region.h"
#include "material_dictionary.h"

#define NX 40    //number of bins in x direction
#define NY 40    //number of bins in y direction
#define NZ 40    //number of bins in z direction
#define DX 1e-3   //linear size of each bin in m
#define Max_Num_Neutrons 10000 //maximum number of neutrons we can keep track of

using std::ofstream;
using std::ostream;
using std::string;


class Reactor {

 protected:
  int num_regions;   //number of regions that make up reactor (see Region.h)
  Region *region_arr;  //array of regions that make up reactor
  Neutron neutron_arr[Max_Num_Neutrons];  //array of neutrons
  int num_neutrons;
  Material_Dictionary mat_dict;  //see material_dictionary.h -- allows for look up of different types of nuclei
  int neutron_multiplier;        //if a lot of neutrons (more than Max_Num_Neutrons), let each neutron represent multiple neutrons
  

 public:
  //constructor
  Reactor(char *filename);

  void evolve_neutrons(double dt);   //Updates neutron and neut_energy arrays based solely on motion of neutrons w/o reactions
                                     //dt = time step in seconds
  void react(double dt);            //checks for reactions.  essentially steps through neuclei array and calls material.react()
                                     //at each location.  dt = time step in seconds             

  void add_neutron(int x, int y, int z, double ke); //add a  neutron with kinetic energy ke at location (x,y,z)
                                                           //x, y, z are array indices

  void remove_neutron(int i);  //remove neutron at index i

  int count_neutrons() {return num_neutrons;}   //returns current number of neutrons

  double calc_neutron_energy(double E_in);  //calculate energy of emitted neutron based on KE of neutron that induced the fission

  int get_num_neutrons(){return num_neutrons;}

  double get_neutron_x(int i) {return neutron_arr[i].get_x();}
  double get_neutron_y(int i) {return neutron_arr[i].get_y();}

  //destructor
  ~Reactor() {delete [] region_arr;}
};


#endif  //ifndef REACTOR_H
