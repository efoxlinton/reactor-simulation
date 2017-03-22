/****************************************
This header file is automatically generated
by ./header_creator using data from Uranium-235.dat
****************************************/

#ifndef URANIUM235_h
#define URANIUM235_h

#include "Material.h"

class URANIUM235: public Material {
	public:
	  //constructor
	  URANIUM235() {
		id = U235;
		A = 235.044;
		Cv = 27.67;
		rho = 19.05;
		Nr = 2;
		//initialize arrays
		Ne = new int[Nr];            //array of numbers of energies per reaction
		energies = new double*[Nr];  //array of energies
		sigmas = new double*[Nr];    //array of cross-sections
		Q = new double[Nr];          //array of cross-sections
		Nneut = new double[Nr];      //array of neutrons produced
		Nprod = new int[Nr];         //array of cross-sections
		products = new int*[Nr];     //array of integer codes of products

		//***** Reaction 0 *****
		Ne[0] = 43; //Number of energy bins in reaction 0
		energies[0] = new double[43]; //initialize energy array for reaction 0
		sigmas[0] = new double[43]; //initialize sigma array for reaction 0
		Nprod[0] = 2; //number of products for reaction 0
		products[0] = new int[2]; //initialize array to store products

		//products for reaction 0 (see material.h for constant definitions)
		products[0][0] = Ba144;
		products[0][1] = Kr89;

		Nneut[0] = 3;  //number of neutrons in reaction 0

		Q[0] = 173.28;  //Q value for reaction 0

		//***********Cross-section vs energy reaction 0 *************
		energies[0][0] = 12.1671;
		sigmas[0][0] = 6.39423e-33;
		energies[0][1] = 17.6531;
		sigmas[0][1] = 2.40363e-29;
		energies[0][2] = 18.0446;
		sigmas[0][2] = 2.5111e-29;
		energies[0][3] = 18.4914;
		sigmas[0][3] = 2.62897e-29;
		energies[0][4] = 18.9253;
		sigmas[0][4] = 2.78634e-29;
		energies[0][5] = 19.3694;
		sigmas[0][5] = 2.86954e-29;
		energies[0][6] = 19.8239;
		sigmas[0][6] = 2.88338e-29;
		energies[0][7] = 20.2891;
		sigmas[0][7] = 2.88543e-29;
		energies[0][8] = 20.7652;
		sigmas[0][8] = 2.88748e-29;
		energies[0][9] = 21.2525;
		sigmas[0][9] = 2.88953e-29;
		energies[0][10] = 21.7512;
		sigmas[0][10] = 2.77537e-29;
		energies[0][11] = 22.2617;
		sigmas[0][11] = 2.63853e-29;
		energies[0][12] = 22.9045;
		sigmas[0][12] = 2.40702e-29;
		energies[0][13] = 23.4605;
		sigmas[0][13] = 2.17993e-29;
		energies[0][14] = 24.0246;
		sigmas[0][14] = 1.96378e-29;
		energies[0][15] = 24.618;
		sigmas[0][15] = 1.77839e-29;
		energies[0][16] = 25.2261;
		sigmas[0][16] = 1.59501e-29;
		energies[0][17] = 25.8492;
		sigmas[0][17] = 1.43978e-29;
		energies[0][18] = 26.4219;
		sigmas[0][18] = 1.29486e-29;
		energies[0][19] = 27.0676;
		sigmas[0][19] = 1.15955e-29;
		energies[0][20] = 27.7203;
		sigmas[0][20] = 1.04472e-29;
		energies[0][21] = 28.3708;
		sigmas[0][21] = 9.49394e-30;
		energies[0][22] = 28.9754;
		sigmas[0][22] = 8.98011e-30;
		energies[0][23] = 29.7807;
		sigmas[0][23] = 8.25338e-30;
		energies[0][24] = 30.4795;
		sigmas[0][24] = 7.80631e-30;
		energies[0][25] = 31.1619;
		sigmas[0][25] = 7.51767e-30;
		energies[0][26] = 32.2992;
		sigmas[0][26] = 6.90762e-30;
		energies[0][27] = 33.8686;
		sigmas[0][27] = 6.30778e-30;
		energies[0][28] = 34.6268;
		sigmas[0][28] = 6.28236e-30;
		energies[0][29] = 36.6168;
		sigmas[0][29] = 5.81292e-30;
		energies[0][30] = 37.3971;
		sigmas[0][30] = 5.7639e-30;
		energies[0][31] = 39.5881;
		sigmas[0][31] = 5.31312e-30;
		energies[0][32] = 40.4317;
		sigmas[0][32] = 5.26591e-30;
		energies[0][33] = 42.6203;
		sigmas[0][33] = 4.87562e-30;
		energies[0][34] = 43.4827;
		sigmas[0][34] = 4.81771e-30;
		energies[0][35] = 45.8848;
		sigmas[0][35] = 4.45584e-30;
		energies[0][36] = 46.7639;
		sigmas[0][36] = 4.43497e-30;
		energies[0][37] = 49.3993;
		sigmas[0][37] = 4.08893e-30;
		energies[0][38] = 50.452;
		sigmas[0][38] = 4.05444e-30;
		energies[0][39] = 53.4078;
		sigmas[0][39] = 3.73736e-30;
		energies[0][40] = 54.5459;
		sigmas[0][40] = 3.70415e-30;
		energies[0][41] = 57.4985;
		sigmas[0][41] = 3.42961e-30;
		energies[0][42] = 58.7238;
		sigmas[0][42] = 3.39217e-30;

		//***** Reaction 1 *****
		Ne[1] = 67; //Number of energy bins in reaction 1
		energies[1] = new double[67]; //initialize energy array for reaction 1
		sigmas[1] = new double[67]; //initialize sigma array for reaction 1
		Nprod[1] = 2; //number of products for reaction 1
		products[1] = new int[2]; //initialize array to store products

		//products for reaction 1 (see material.h for constant definitions)
		products[1][0] = Xe140;
		products[1][1] = St94;

		Nneut[1] = 2;  //number of neutrons in reaction 1

		Q[1] = 184.677;  //Q value for reaction 1

		//***********Cross-section vs energy reaction 1 *************
		energies[1][0] = 5.2916;
		sigmas[1][0] = 5.81788e-32;
		energies[1][1] = 5.30086;
		sigmas[1][1] = 4.48528e-32;
		energies[1][2] = 5.33636;
		sigmas[1][2] = 1.27504e-31;
		energies[1][3] = 5.32893;
		sigmas[1][3] = 9.09005e-32;
		energies[1][4] = 5.37426;
		sigmas[1][4] = 2.21204e-31;
		energies[1][5] = 5.41551;
		sigmas[1][5] = 3.40538e-31;
		energies[1][6] = 5.46719;
		sigmas[1][6] = 5.10571e-31;
		energies[1][7] = 5.51929;
		sigmas[1][7] = 7.38471e-31;
		energies[1][8] = 5.60317;
		sigmas[1][8] = 1.08747e-30;
		energies[1][9] = 5.68821;
		sigmas[1][9] = 1.53184e-30;
		energies[1][10] = 5.75292;
		sigmas[1][10] = 2.0445e-30;
		energies[1][11] = 5.81858;
		sigmas[1][11] = 2.97277e-30;
		energies[1][12] = 5.90701;
		sigmas[1][12] = 4.37769e-30;
		energies[1][13] = 5.9966;
		sigmas[1][13] = 6.012e-30;
		energies[1][14] = 6.08749;
		sigmas[1][14] = 8.07511e-30;
		energies[1][15] = 6.20291;
		sigmas[1][15] = 1.1125e-29;
		energies[1][16] = 6.36779;
		sigmas[1][16] = 1.51816e-29;
		energies[1][17] = 6.5909;
		sigmas[1][17] = 2.07175e-29;
		energies[1][18] = 6.86778;
		sigmas[1][18] = 2.52207e-29;
		energies[1][19] = 7.21969;
		sigmas[1][19] = 2.92945e-29;
		energies[1][20] = 7.49144;
		sigmas[1][20] = 3.20518e-29;
		energies[1][21] = 7.83785;
		sigmas[1][21] = 3.58789e-29;
		energies[1][22] = 8.1461;
		sigmas[1][22] = 4.01063e-29;
		energies[1][23] = 8.57538;
		sigmas[1][23] = 4.71462e-29;
		energies[1][24] = 8.9134;
		sigmas[1][24] = 5.30966e-29;
		energies[1][25] = 9.29255;
		sigmas[1][25] = 6.00985e-29;
		energies[1][26] = 9.70433;
		sigmas[1][26] = 6.58799e-29;
		energies[1][27] = 10.132;
		sigmas[1][27] = 7.19995e-29;
		energies[1][28] = 10.6399;
		sigmas[1][28] = 7.80247e-29;
		energies[1][29] = 11.0853;
		sigmas[1][29] = 7.80247e-29;
		energies[1][30] = 11.4921;
		sigmas[1][30] = 7.83554e-29;
		energies[1][31] = 12.0372;
		sigmas[1][31] = 7.52056e-29;
		energies[1][32] = 12.5217;
		sigmas[1][32] = 6.57407e-29;
		energies[1][33] = 13.04;
		sigmas[1][33] = 5.53204e-29;
		energies[1][34] = 13.6251;
		sigmas[1][34] = 4.35239e-29;
		energies[1][35] = 14.214;
		sigmas[1][35] = 3.41995e-29;
		energies[1][36] = 14.7757;
		sigmas[1][36] = 2.73891e-29;
		energies[1][37] = 15.4156;
		sigmas[1][37] = 2.13853e-29;
		energies[1][38] = 16.0233;
		sigmas[1][38] = 1.67844e-29;
		energies[1][39] = 16.648;
		sigmas[1][39] = 1.31799e-29;
		energies[1][40] = 17.3891;
		sigmas[1][40] = 1.01151e-29;
		energies[1][41] = 18.1153;
		sigmas[1][41] = 8.1148e-30;
		energies[1][42] = 18.7719;
		sigmas[1][42] = 6.69065e-30;
		energies[1][43] = 19.5688;
		sigmas[1][43] = 5.35465e-30;
		energies[1][44] = 20.4603;
		sigmas[1][44] = 4.68138e-30;
		energies[1][45] = 21.4053;
		sigmas[1][45] = 4.35921e-30;
		energies[1][46] = 22.4098;
		sigmas[1][46] = 4.05676e-30;
		energies[1][47] = 23.4365;
		sigmas[1][47] = 3.77529e-30;
		energies[1][48] = 24.7418;
		sigmas[1][48] = 3.45859e-30;
		energies[1][49] = 25.8869;
		sigmas[1][49] = 3.22836e-30;
		energies[1][50] = 27.1016;
		sigmas[1][50] = 2.97906e-30;
		energies[1][51] = 28.4138;
		sigmas[1][51] = 2.77237e-30;
		energies[1][52] = 29.9093;
		sigmas[1][52] = 2.55287e-30;
		energies[1][53] = 31.304;
		sigmas[1][53] = 2.3851e-30;
		energies[1][54] = 32.6156;
		sigmas[1][54] = 2.22381e-30;
		energies[1][55] = 34.1087;
		sigmas[1][55] = 2.07646e-30;
		energies[1][56] = 35.5724;
		sigmas[1][56] = 1.94743e-30;
		energies[1][57] = 37.3144;
		sigmas[1][57] = 1.78266e-30;
		energies[1][58] = 39.8812;
		sigmas[1][58] = 1.592e-30;
		energies[1][59] = 41.373;
		sigmas[1][59] = 1.49956e-30;
		energies[1][60] = 43.0959;
		sigmas[1][60] = 1.38934e-30;
		energies[1][61] = 44.9127;
		sigmas[1][61] = 1.29889e-30;
		energies[1][62] = 47.1267;
		sigmas[1][62] = 1.1931e-30;
		energies[1][63] = 49.4215;
		sigmas[1][63] = 1.10386e-30;
		energies[1][64] = 53.0864;
		sigmas[1][64] = 1.02062e-30;
		energies[1][65] = 55.8577;
		sigmas[1][65] = 9.22512e-31;
		energies[1][66] = 58.5666;
		sigmas[1][66] = 8.30443e-31;

	  }  //end of constructor

	  //destructor
	  ~URANIUM235() {

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
