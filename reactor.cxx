/*******************************************
reactor.cxx -- implementation of reactor.h

reads in file.  Format should be: 
N  (number of regions)
T 0.2 0.6 0.7...
1e22 4.5e20  0 0 0 ...
(T == S for sphere, R for rectangular prism, or C for cylinder
numbers on same line give input parameters as given in region.h constructors
numbers on next line give number densities in same order as constants in material.h
so there will be 2N lines after the initial line giving N)
Regions should be listed inside out.  That is, if there is a fuel rod in a cube of water
list cylinder first and cube second.  This is because regions will be checked from 0th index
on down.
********************************************/

#include <math.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "material.h"
#include "reactor.h"
#include "URANIUM238.h"

using std::ofstream;
using std::ifstream;
using std::ostream;
using std::string;
using std::endl;
using std::cout;
using std::cerr;


Reactor::Reactor(char *filename) {

  num_neutrons = 0;

  //open file and read in data to create reactor
  ifstream fin(filename);

  //check for proper file opne
  if (!fin.good()) {
    cerr << "Unable to open " << filename << endl;
    return;
  }

  fin >> num_regions;  //first line contains number of regions

  region_arr = new Region[num_regions];
  char type;
  double delta_x, delta_y, delta_z, x, y, z, radius, density;

  for (int i=0; i<num_regions; i++) {
    fin >> type;

    if (type == 'S' || type == 's') { //sphere
      fin >> x >> y >> z >> radius;
      region_arr[i].set_type(SPHERE);
      region_arr[i].set_x(x);
      region_arr[i].set_y(y);
      region_arr[i].set_z(z);
      region_arr[i].set_radius(radius);
    } else if (type == 'R' || type == 'r') { //rectangular prism
      fin >> x >> y >> z >> delta_x >> delta_y >> delta_z;
      region_arr[i].set_type(RECT_PRISM);
      region_arr[i].set_x(x);
      region_arr[i].set_y(y);
      region_arr[i].set_z(z);
      region_arr[i].set_delta_x(delta_x);
      region_arr[i].set_delta_y(delta_y);
      region_arr[i].set_delta_z(delta_z);
    } else { //cylinder
      fin >> x >> y >> z >> radius >> delta_x >> delta_y >> delta_z;
      region_arr[i].set_type(CYLINDER);
      region_arr[i].set_x(x);
      region_arr[i].set_y(y);
      region_arr[i].set_z(z);
      region_arr[i].set_radius(radius);
      region_arr[i].set_delta_x(delta_x);
      region_arr[i].set_delta_y(delta_y);
      region_arr[i].set_delta_z(delta_z);
    }

    region_arr[i].calc_volume();  //calculate volume given new dimensions of region

    //read in density
    for (int j = 0; j < N_ELEMENTS; j++) {
      fin >> density;
      region_arr[i].set_density(j, density);
    }

  } //end loop reading in regions

  return;
}

//just use d = vt to move neutrons.  Reactions are taken care of in Reactor::react
void Reactor::evolve_neutrons(double dt) {

  double vx, vy, vz, x, y, z;

  for (int i=0; i<num_neutrons; i++) {
    x = neutron_arr[i].get_x();
    y = neutron_arr[i].get_y();
    z = neutron_arr[i].get_z();
    vx = neutron_arr[i].get_vx();
    vy = neutron_arr[i].get_vy();
    vz = neutron_arr[i].get_vz();

    neutron_arr[i].set_x(x+vx*dt);
    neutron_arr[i].set_y(y+vy*dt);
    neutron_arr[i].set_z(z+vz*dt);
  }

  return;
}

//check for any reactions occuring in time window dt
void Reactor::react(double dt) {
  double x, y, z;  //neutron coordinates
  double dl; //pathlength traveled by neutron
  double randp;  //random number
  double Mnuc, n, A;  //mass of nucleus and number density, and mass number
  double sigma, Q;  //cross section, Q value
  int num_new_neutrons;
  int region_num, id, reaction_num;
  bool has_reacted, in_reactor;
  double ke;  //new neutron ke

  //step through all neutrons
  for (int i=0; i<num_neutrons; i++) {

    has_reacted = false; //set true if neutron reacts

    //find indices for ith neutron -- here is where we'll remove any neutrons that have left reactor
    in_reactor = false;  //set true once region neutron is in is found

    while (num_neutrons > i && !in_reactor) {   //Find out which region neutron is in.  If out of reactor, swap with last element and keep looking
      x = neutron_arr[i].get_x();
      y = neutron_arr[i].get_y();
      z = neutron_arr[i].get_z();

      //see if neutron is in the reactor
      for (region_num = 0; region_num < num_regions && !in_reactor; region_num++) {
	if (region_arr[region_num].is_in_region(x, y, z) ) {
	  in_reactor = true;
	  break;
	}
      }


      if (!in_reactor) {  //not in reactor
	remove_neutron(i);  //removes this neutron and slides last in array into its place
      }
    }

    //make sure we found a neutron in the array
    if (i >= num_neutrons) {
      break; //no more neutrons in reactor, so leave
    }
    

    dl = neutron_arr[i].get_speed()*dt;
        
    //step through all possible elements to see if there's a reaction
    for(id = 0; id<N_ELEMENTS && !has_reacted; id++) {
       
      n  = region_arr[region_num].get_density(id);  //number density of nuclei

      if (n > 0) {
	A = mat_dict.look_up(id).get_A();
	Mnuc = A/NA;  //Mass of Nucleus
	
	for (reaction_num = 0; reaction_num< mat_dict.look_up(id).get_num_react() && !has_reacted; reaction_num++) {  //step through allowed reactions for this element
	  randp = double(rand())/RAND_MAX;
	  sigma = mat_dict.look_up(id).get_cross_section(reaction_num, neutron_arr[i].get_ke());

	  if (randp < n*sigma*dl) {  //reaction takes place
	    has_reacted = true;
	    Q = mat_dict.look_up(id).get_Q(reaction_num);
	    num_new_neutrons = mat_dict.look_up(id).get_num_neutrons(reaction_num);	    
	    break;
	  }
	}  //end loop on reaction number

	if (has_reacted) {
	  break;
	}
      }  //end if n > 0
    }  //end loop on materials present       

    if (has_reacted) {
      //cout << "reaction!  Species = " << id << ", reaction_num = " << reaction_num << ", num neutrons = " << mat_dict.look_up(id).get_num_neutrons(reaction_num) << endl;

      //add new nuclei and remove reacted nuclei
      region_arr[region_num].add_nuclei(id, -neutron_multiplier);  //remove target nuclei

      for (int j=0; j< mat_dict.look_up(id).get_num_products(reaction_num); j++) { //loop on products to add
	region_arr[region_num].add_nuclei(mat_dict.look_up(id).get_product(reaction_num, j), neutron_multiplier);
      }

      //add new neutrons and remove reacted neutron
      for (int j=0; j < mat_dict.look_up(id).get_num_neutrons(reaction_num); j++) {  //loop on neutrons added
	ke = calc_neutron_energy(neutron_arr[i].get_ke());
	add_neutron(x, y, z, ke);
      }

      remove_neutron(i);
      i--;   //so we don't skip neutron that fills in place of removed one

    } // end if(has_reacted)

  } // end loop on i, neutrons
}

//adds n neutrons with energy E at location (x,y,z) (in terms of array indices)
void Reactor::add_neutron(int x, int y, int z, double ke) {
  //add neutron if room
  if (num_neutrons < Max_Num_Neutrons) {
    neutron_arr[num_neutrons].set_x(x*DX);
    neutron_arr[num_neutrons].set_y(y*DX);
    neutron_arr[num_neutrons].set_z(z*DX);
    neutron_arr[num_neutrons].set_ke(ke);

    num_neutrons++;
  }

  //if no room for another, make some room by letting each neutron represent multiple neutrons
  if (num_neutrons >= Max_Num_Neutrons) {
    neutron_multiplier *= 100;  //let each current neutron represent 100

    //keep only every Max_Num_Neutrons/100-th neutron
    for (int i=1; i<Max_Num_Neutrons/100; i++) {
      neutron_arr[i].copy(neutron_arr[100*i]);
    }
    num_neutrons = Max_Num_Neutrons/100;

  }
}

void Reactor::remove_neutron(int i) {
  if (i < num_neutrons) {  //make sure we're in range
    neutron_arr[i].copy(neutron_arr[num_neutrons - 1]);  //copy last neutron to take its place
    num_neutrons--;
  }
}

//calculate energy of neutron emitted in fission given energy of inducing neutron
double Reactor::calc_neutron_energy(double E_in) {
  //use Aziz et. al JNRP vol. 6, No. 1&2
  //for now just use fit parameters based on single incoming neutron energy
  //Will need to run simulations to calculate my own fit parameters and then have a look-up table

  //use 1D arrays for now.  Make 2D with energies.  Then just look
  //up correct energy based on E_in
  double A[3] = {1.450, -1.270, -.150};
  double B[3] = {1.470, 0.890, 0.053};

  int target = floor((100.0*rand())/RAND_MAX); //generate random int between 1 and 100

  //need to solve target/100 = 1 - sum(AiBiexp(-E/Bi)) -- gives 1% tolerance in target
  double E = 10;   //typical neutron energy, using MeV as always
  double p = 1;
  for (int i=0; i<3; i++) {
    p -= A[i]*B[i]*exp(-E/B[i]);
  }
  int int_p = int(100*p);

  int sign; //keep track of direction we need to move

  if (int_p < target) {
    sign = 1;
  } else if (int_p > target) {
    sign = -1;
  } else { //int_p = target
    return E;
  }

  for (double delta_E = 5; int_p != target; ) {
    E += sign*delta_E;

    p = 1;

    for (int i=0; i<3; i++) {
      p -= A[i]*B[i]*exp(-E/B[i]);
    }
    int_p = int(100*p);


    if ((int_p < target && sign < 0) || (int_p > target && sign > 0)) {  //moving wrong way
      delta_E /= 2.0;  //shrink step size
      sign *= -1;  //turn around
    }
  }

  return E;

}

