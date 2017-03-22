/****************************************
This header file is automatically generated
by ./header_creator using data from Xenon-140.dat
****************************************/

#ifndef XENON140_h
#define XENON140_h

#include "Material.h"

class XENON140: public Material {
	public:
	  //constructor
	  XENON140() {
		id = Xe140;
		A = 139.922;
		Cv = 0.15832;
		rho = 0.005894;
		Nr = 0;
	  }  //end of constructor

	  //destructor
	  ~XENON140() {

	  }
};

#endif
