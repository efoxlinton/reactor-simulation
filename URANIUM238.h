/****************************************
This header file is automatically generated
by ./header_creator using data from U-238.dat
****************************************/

#ifndef URANIUM238_h
#define URANIUM238_h

#include "Material.h"

class URANIUM238: public Material {
	public:
	  //constructor
	  URANIUM238() {
		id = U238;
		A = 238.051;
		Cv = 27.67;
		rho = 19.1;
		Nr = 1;
		//initialize arrays
		Ne = new int[Nr];            //array of numbers of energies per reaction
		energies = new double*[Nr];  //array of energies
		sigmas = new double*[Nr];    //array of cross-sections
		Q = new double[Nr];          //array of cross-sections
		Nneut = new double[Nr];      //array of neutrons produced
		Nprod = new int[Nr];         //array of cross-sections
		products = new int*[Nr];     //array of integer codes of products

		//***** Reaction 0 *****
		Ne[0] = 103; //Number of energy bins in reaction 0
		energies[0] = new double[103]; //initialize energy array for reaction 0
		sigmas[0] = new double[103]; //initialize sigma array for reaction 0
		Nprod[0] = 0; //number of products for reaction 0
		products[0] = new int[0]; //initialize array to store products

		//products for reaction 0 (see material.h for constant definitions)

		Nneut[0] = 0;  //number of neutrons in reaction 0

		Q[0] = 0;  //Q value for reaction 0

		//***********Cross-section vs energy reaction 0 *************
		energies[0][0] = 1.94345e-11;
		sigmas[0][0] = 1.78485e-26;
		energies[0][1] = 3.13202e-11;
		sigmas[0][1] = 1.78485e-26;
		energies[0][2] = 4.62801e-11;
		sigmas[0][2] = 1.78485e-26;
		energies[0][3] = 4.73773e-09;
		sigmas[0][3] = 7.61177e-27;
		energies[0][4] = 8.3093e-09;
		sigmas[0][4] = 7.36862e-27;
		energies[0][5] = 1.52195e-08;
		sigmas[0][5] = 7.13324e-27;
		energies[0][6] = 2.78762e-08;
		sigmas[0][6] = 6.90537e-27;
		energies[0][7] = 4.88909e-08;
		sigmas[0][7] = 6.68478e-27;
		energies[0][8] = 8.99767e-08;
		sigmas[0][8] = 6.46541e-27;
		energies[0][9] = 1.56311e-07;
		sigmas[0][9] = 6.27018e-27;
		energies[0][10] = 2.86302e-07;
		sigmas[0][10] = 6.06988e-27;
		energies[0][11] = 5.10168e-07;
		sigmas[0][11] = 5.89456e-27;
		energies[0][12] = 8.34644e-07;
		sigmas[0][12] = 5.78789e-27;
		energies[0][13] = 1.36549e-06;
		sigmas[0][13] = 5.68315e-27;
		energies[0][14] = 2.08784e-06;
		sigmas[0][14] = 5.63721e-27;
		energies[0][15] = 3.89686e-06;
		sigmas[0][15] = 5.91319e-27;
		energies[0][16] = 5.78328e-06;
		sigmas[0][16] = 6.78631e-27;
		energies[0][17] = 7.70925e-06;
		sigmas[0][17] = 8.21079e-27;
		energies[0][18] = 7.75855e-06;
		sigmas[0][18] = 1.55481e-26;
		energies[0][19] = 7.59977e-06;
		sigmas[0][19] = 1.13986e-26;
		energies[0][20] = 9.77924e-06;
		sigmas[0][20] = 6.53281e-27;
		energies[0][21] = 1.23579e-05;
		sigmas[0][21] = 5.59164e-27;
		energies[0][22] = 1.80715e-05;
		sigmas[0][22] = 5.81536e-27;
		energies[0][23] = 2.3605e-05;
		sigmas[0][23] = 7.18165e-27;
		energies[0][24] = 2.44547e-05;
		sigmas[0][24] = 1.51741e-26;
		energies[0][25] = 2.41656e-05;
		sigmas[0][25] = 1.26927e-26;
		energies[0][26] = 2.3764e-05;
		sigmas[0][26] = 9.86922e-27;
		energies[0][27] = 3.18747e-05;
		sigmas[0][27] = 5.8503e-27;
		energies[0][28] = 4.11933e-05;
		sigmas[0][28] = 8.01328e-27;
		energies[0][29] = 4.28901e-05;
		sigmas[0][29] = 1.46894e-26;
		energies[0][30] = 4.2383e-05;
		sigmas[0][30] = 1.22873e-26;
		energies[0][31] = 4.18819e-05;
		sigmas[0][31] = 1.0278e-26;
		energies[0][32] = 5.31024e-05;
		sigmas[0][32] = 5.86275e-27;
		energies[0][33] = 5.8712e-05;
		sigmas[0][33] = 5.0573e-27;
		energies[0][34] = 8.76263e-05;
		sigmas[0][34] = 1.29082e-26;
		energies[0][35] = 8.78006e-05;
		sigmas[0][35] = 1.07037e-26;
		energies[0][36] = 8.67808e-05;
		sigmas[0][36] = 8.98162e-27;
		energies[0][37] = 8.55278e-05;
		sigmas[0][37] = 7.2198e-27;
		energies[0][38] = 9.63516e-05;
		sigmas[0][38] = 5.45714e-27;
		energies[0][39] = 0.000129079;
		sigmas[0][39] = 1.23206e-26;
		energies[0][40] = 0.000143068;
		sigmas[0][40] = 1.01673e-26;
		energies[0][41] = 0.000147544;
		sigmas[0][41] = 8.41773e-27;
		energies[0][42] = 0.000140738;
		sigmas[0][42] = 6.80469e-27;
		energies[0][43] = 0.000166216;
		sigmas[0][43] = 5.74499e-27;
		energies[0][44] = 0.000161523;
		sigmas[0][44] = 4.72127e-27;
		energies[0][45] = 0.000188647;
		sigmas[0][45] = 4.38321e-27;
		energies[0][46] = 0.000232983;
		sigmas[0][46] = 1.01831e-26;
		energies[0][47] = 0.000235056;
		sigmas[0][47] = 7.7238e-27;
		energies[0][48] = 0.000273924;
		sigmas[0][48] = 6.4672e-27;
		energies[0][49] = 0.00027289;
		sigmas[0][49] = 5.07272e-27;
		energies[0][50] = 0.000315613;
		sigmas[0][50] = 4.23173e-27;
		energies[0][51] = 0.000376782;
		sigmas[0][51] = 1.00852e-26;
		energies[0][52] = 0.000378824;
		sigmas[0][52] = 8.18861e-27;
		energies[0][53] = 0.000436999;
		sigmas[0][53] = 6.47433e-27;
		energies[0][54] = 0.00046416;
		sigmas[0][54] = 5.05901e-27;
		energies[0][55] = 0.000489753;
		sigmas[0][55] = 3.94121e-27;
		energies[0][56] = 0.000635632;
		sigmas[0][56] = 8.73795e-27;
		energies[0][57] = 0.000710087;
		sigmas[0][57] = 6.89924e-27;
		energies[0][58] = 0.000763214;
		sigmas[0][58] = 5.54002e-27;
		energies[0][59] = 0.000711543;
		sigmas[0][59] = 4.38558e-27;
		energies[0][60] = 0.00101885;
		sigmas[0][60] = 8.9614e-27;
		energies[0][61] = 0.000966921;
		sigmas[0][61] = 3.99463e-27;
		energies[0][62] = 0.00115237;
		sigmas[0][62] = 7.66136e-27;
		energies[0][63] = 0.00123089;
		sigmas[0][63] = 6.23721e-27;
		energies[0][64] = 0.00117867;
		sigmas[0][64] = 5.10651e-27;
		energies[0][65] = 0.00155839;
		sigmas[0][65] = 4.22757e-27;
		energies[0][66] = 0.00180746;
		sigmas[0][66] = 7.82324e-27;
		energies[0][67] = 0.00174167;
		sigmas[0][67] = 3.55685e-27;
		energies[0][68] = 0.00197599;
		sigmas[0][68] = 5.98293e-27;
		energies[0][69] = 0.00249989;
		sigmas[0][69] = 4.19812e-27;
		energies[0][70] = 0.00288342;
		sigmas[0][70] = 7.65119e-27;
		energies[0][71] = 0.00295021;
		sigmas[0][71] = 3.53289e-27;
		energies[0][72] = 0.00320457;
		sigmas[0][72] = 6.4672e-27;
		energies[0][73] = 0.00306844;
		sigmas[0][73] = 5.29061e-27;
		energies[0][74] = 0.00406019;
		sigmas[0][74] = 4.44691e-27;
		energies[0][75] = 0.00473608;
		sigmas[0][75] = 3.56455e-27;
		energies[0][76] = 0.00504072;
		sigmas[0][76] = 7.05472e-27;
		energies[0][77] = 0.00498113;
		sigmas[0][77] = 5.90109e-27;
		energies[0][78] = 0.0064887;
		sigmas[0][78] = 4.72016e-27;
		energies[0][79] = 0.007156;
		sigmas[0][79] = 3.32733e-27;
		energies[0][80] = 0.00798439;
		sigmas[0][80] = 6.76301e-27;
		energies[0][81] = 0.00816375;
		sigmas[0][81] = 5.68828e-27;
		energies[0][82] = 0.00917938;
		sigmas[0][82] = 4.10765e-27;
		energies[0][83] = 0.0101379;
		sigmas[0][83] = 5.11406e-27;
		energies[0][84] = 0.00967819;
		sigmas[0][84] = 3.12672e-27;
		energies[0][85] = 0.0126869;
		sigmas[0][85] = 6.09731e-27;
		energies[0][86] = 0.0238361;
		sigmas[0][86] = 5.8075e-27;
		energies[0][87] = 0.0391331;
		sigmas[0][87] = 5.49046e-27;
		energies[0][88] = 0.0636744;
		sigmas[0][88] = 5.34029e-27;
		energies[0][89] = 0.106628;
		sigmas[0][89] = 5.0551e-27;
		energies[0][90] = 0.161123;
		sigmas[0][90] = 4.96679e-27;
		energies[0][91] = 0.266125;
		sigmas[0][91] = 4.86021e-27;
		energies[0][92] = 0.632995;
		sigmas[0][92] = 4.7759e-27;
		energies[0][93] = 1.08498;
		sigmas[0][93] = 4.92065e-27;
		energies[0][94] = 1.78569;
		sigmas[0][94] = 4.49125e-27;
		energies[0][95] = 2.89769;
		sigmas[0][95] = 4.00884e-27;
		energies[0][96] = 4.36051;
		sigmas[0][96] = 3.41431e-27;
		energies[0][97] = 6.55724;
		sigmas[0][97] = 2.95688e-27;
		energies[0][98] = 10.7825;
		sigmas[0][98] = 2.88868e-27;
		energies[0][99] = 16.3238;
		sigmas[0][99] = 2.76724e-27;
		energies[0][100] = 25.6209;
		sigmas[0][100] = 2.44122e-27;
		energies[0][101] = 39.2639;
		sigmas[0][101] = 2.32257e-27;
		energies[0][102] = 53.6384;
		sigmas[0][102] = 2.23473e-27;

	  }  //end of constructor

	  //destructor
	  ~URANIUM238() {

		//clear double arrays
		for(int i=0; i<Nr; i++) {  //loop through each reaction
		  delete [] energies[i];
		  delete [] sigmas[i];
		  delete [] products[i];
		}

		//delete the 1D arrays (and what is left of 2d)
		delete [] Ne;
		delete [] energies;
		delete [] sigmas;
		delete [] Q;
		delete [] Nneut;
		delete [] Nprod;
		delete [] products;
	  }
};

#endif
