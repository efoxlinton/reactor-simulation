/****************************************
This header file is automatically generated
by ./header_creator using data from Barium-144.dat
****************************************/

#ifndef BARIUM144_h
#define BARIUM144_h

#include "Material.h"

class BARIUM144: public Material {
	public:
	  //constructor
	  BARIUM144() {
		id = Ba144;
		A = 143.923;
		Cv = 0.205;
		rho = 3.51;
		Nr = 0;
	  }  //end of constructor

	  //destructor
	  ~BARIUM144() {

	  }
};

#endif
