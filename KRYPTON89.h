/****************************************
This header file is automatically generated
by ./header_creator using data from Krypton-89.dat
****************************************/

#ifndef KRYPTON89_h
#define KRYPTON89_h

#include "Material.h"

class KRYPTON89: public Material {
	public:
	  //constructor
	  KRYPTON89() {
		id = Kr89;
		A = 88.9176;
		Cv = 0.248;
		rho = 0.00374;
		Nr = 0;
	  }  //end of constructor

	  //destructor
	  ~KRYPTON89() {

	  }
};

#endif
