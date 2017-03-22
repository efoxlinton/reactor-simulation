/****************************************
This header file is automatically generated
by ./header_creator using data from Strontium-94.dat
****************************************/

#ifndef STRONTIUM94_h
#define STRONTIUM94_h

#include "Material.h"

class STRONTIUM94: public Material {
	public:
	  //constructor
	  STRONTIUM94() {
		id = St94;
		A = 93.9154;
		Cv = 0.293076;
		rho = 2.6;
		Nr = 0;
	  }  //end of constructor

	  //destructor
	  ~STRONTIUM94() {

	  }
};

#endif
