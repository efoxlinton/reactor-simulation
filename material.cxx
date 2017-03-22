/*******************************************
material.cxx -- implementation of material.h
********************************************/

#include <math.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "material.h"

using std::ofstream;
using std::ostream;
using std::string;
using std::endl;
using std::cout;
using std::cerr;


double Material::get_cross_section(int react_num, double energy) {
  int N = Ne[react_num];
  int min_ind = 0;
  int max_ind = N-1;

  //check for border cases first
  if (energy <= energies[react_num][0]) {
    return sigmas[react_num][0];
  } else if (energy >= energies[react_num][max_ind]) {
    return sigmas[react_num][max_ind];
  }

  //perform binary search for right index
  for (int i = N/2; max_ind - min_ind > 1; i = (max_ind + min_ind)/2) {
    if (energies[react_num][i] > energy) {
      max_ind = i;
    } else if (energies[react_num][i] < energy) {
      min_ind = i;
    } else {  //hit the energy on the nose
      max_ind = min_ind = i;
    }

  }


  //use linear interpolation to find sigma
  double E1 = energies[react_num][min_ind];
  double E2 = energies[react_num][max_ind];
  double sigma1 = sigmas[react_num][min_ind];
  double sigma2 = sigmas[react_num][max_ind];

  return ((energy-E1)/(E2-E1))*(sigma2-sigma1)+sigma1;

}

/**
void Material::react(double *myproducts, int *neutrons, double *neutr_energy, double dx) {
  //randomly determines if any reactions occur caused by neutron of
  //energy E.  Products is an N_ELEMENTS component array.  myproducts[nucleus_ID]
  //contains number of  of nucleus_ID at this location.  react() updates this array
  //neutrons contains the number of neutrons at this location  and neutr_energy contains their average energy
  //react() updates both of these.  
  //For technical reasons, these are pointers rather than regular variables.  So when used, you need to place an * before
  //the variable name.  e.g. *neutrons = 5;  or *neutron_energy += 22;


  double randp;
  randp = double(rand())/RAND_MAX;

  double Mnuc = (A/6.022E23);  //Mass of Nucleus
  double n  = myproducts[id]/dx/dx/dx;  //number density of nuclei


  double prob, sigma, randnum, cumprob;
  int num_react;

  //record initial values for numbers of neutrons and their energies so that we use the same values for
  //all reactions rather than the updated ones
  int current_neutrons = *neutrons;  //number of neutrons available to react (initial - number reacted)
  int initial_neutrons = *neutrons;  //initial number of neutrons
  double current_energy = *neutr_energy;

  //loop through possible reactions
  for (int i=0; i<Nr; i++) { //i = reaction number
    //find cross section, sigma
    sigma = find_sigma(current_energy, energies[i], sigmas[i], Ne[i]);
	
    prob=sigma*n*dx;   //probability of reaction
	
    //calculate number of reaction that take place
    randnum = double(rand())/RAND_MAX;
    cumprob = 0;

    for (num_react = 0; num_react < current_neutrons; num_react++) {
      cumprob += binomial(current_neutrons, num_react, prob);

      if (randnum < cumprob) {
	break;
      }
    }

    //update products, number and energy of neutrons
    if (num_react > 0) { 	

      //loop on products, j = 0 to Nprod[i]-1
      for (int j=0; j<Nprod[i]; j++) {
	myproducts[products[i][j]] += num_react;		
      }
		
      //update average neutron energy
      *neutr_energy =	(*neutr_energy * *neutrons + Q[i]*num_react)/(*neutrons+(Nneut[i]-1)*num_react);

      //adjusting number of neutrons
      *neutrons+=(Nneut[i]-1)*num_react;   //Nneut gives total released, so need to subtract incoming neutron

      current_neutrons -= num_react;   //update number of neutrons still available to react
    } else {
      //No reaction
    }
  }
}
*/

double Material::binomial(int Ntot, int n, double p) {
  double norm = 1;

  if (p >= 1) {
    if (n == Ntot) {
      return 1;
    } else {
      return 0;
    }
  }

  //Ntot factorial
  for (int i=2; i<=Ntot; i++) {
    norm *= i;
  }

  //divide by n!
  for (int i=2; i<=n; i++) {
    norm /= i;
  }

  //divide by (Ntot-n)!
  for (int i=2; i<(Ntot-n); i++) {
    norm /= i;
  }

  return norm*exp(n*log(p) + (Ntot-n)*log(1-p));
}

  

