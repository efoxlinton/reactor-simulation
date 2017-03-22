#ifndef MATERIAL_H
#define MATERIAL_H

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "neutron.h"

#define N_ELEMENTS 6  //total number of nuclei with codes
#define NA 6.022e23   //Avogadro's number
#define U235 0         //code for uranium 235      *****NOTE -- IF ANY OF THESE ELEMENT CODES ARE CHANGED
#define U238 1         //code for uranium 238      *****        CONSTRUCTOR FOR REACTOR CLASS IN REACTOR.CXX
#define Ba144 2        //code for Barium 144       *****        MUST BE UPDATED AS WELL
#define Kr89 3         //code for Krypton 89
#define Xe140 4        //code for Xenon 140
#define St94 5         //code for strontium 94 

using std::ofstream;
using std::ostream;
using std::string;



class Material {

 protected:
  int id;              //contans nucleis id of this element.  For inherited classes (U238, U235, etc).  Use element ids above
  double A;            //atomic mass
  double Cv;           //specific heat capacity
  double rho;          //mass density
  int Nr;              //number of reactions
  int *Ne;            //array of the number of (energy,sigma) pairs for each reaction (Nr components)
  double **energies;  //arrays of energies for each reaction (Nr x Ne array)
  double **sigmas;    //arrays of cross-sections for each reaction (Nr x Ne array)
  double *Q;           //array of Q values -- energy released for each reaction (Nr components)
  double *Nneut;       //number of neutrons released in each reaction (Nr components)
  int *Nprod;          //number of daughter nuclei produced in each reaction (Nr components)
  int **products;     //list of product codes for each reaction (Nr X Nprod array)
    
 public:
  //constructor
  Material() {}

  //void react(double *myproducts, , int neutron_index, double dx);  
  //randomly determines if any reactions occur caused by neutron at index neutron_index in array of neutrons
  //neutron_arr.  myproducts is an N_ELEMENTS component array.  myproducts[nucleus_ID]
  //contains density number of nuclei at this location.  react() updates this array
  //react also updates neutron array by adding/deleting neutrons as necessary

  double binomial(int Ntot, int n, double p);  //calculates probability of getting n out of Ntot using binomial distribution

  //access functions
  double get_A() {return A;}
  double get_rho() {return rho;}
  int get_num_react() {return Nr;}
  int get_num_products(int i) {return Nprod[i];}
  double get_cross_section(int react_num, double energy); //return cross section for reaction number react_num with ke energy 
  double get_Q(int i) {return Q[i];}
  double get_num_neutrons(int i) {return Nneut[i];}
  int get_product(int reac_num, int prod_num) {return products[reac_num][prod_num];}

  //destructor
  ~Material() {}
};


#endif  //ifndef MATERIAL_H
