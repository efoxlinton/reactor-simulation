/****************************************************************
header_creator.cxx

Usage: header_creator filename

creates a header file based on text file with format:

Element name  (header file will be Element_name.h)
element ID  (use code in material.h)
atomic mass
specific heat capacity 
density
number of reaction types (Nr)
number of energies in first reaction
number of new nuclei in first reaction
product 1 (use integer codes)
product 2
etc.
number of neutrons in first reaction
energy released in first reaction in MeV
energy cross-section  (energy in eV, converted to MeV by headercreator.  sigma in barns, converted to m^-2 by headercreator)
(list in two columns, separated by space or tab, one after the other)
number of energies in 2nd reaction
number of new nuclei in 2nd reaction
etc.


creates header file ElementName.h

*****************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <string>

using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;
using std::stringstream;
using std::string;


int main(int argc, char *argv[]) {

  //check for proper function call
  if (argc != 2) {  //improper call, so print out instructions and quit
    cerr << "usage: " << argv[0] << " file_name\n";
    return 1;
  }

  //open input file
  ifstream input(argv[1]);

  //check whether file opened successfully
  if (!input.good()) {
    cerr << "unable to open " << argv[0] << endl;
    return 2;
  }

  //first line contains element name, which will be used to name header file
  char filename[100];   //just set max length at arbitrarily large number
  char objectname[100]; //name of object we're creating
  char productname[25]; //for storing product names further down the line
  char idcode[25];      //for storing constant identifier of material
  int namelength = 0;

  while (input.peek() != '\n') { //read until end of first line
    filename[namelength] = input.get();
    objectname[namelength] = filename[namelength];
    namelength ++;
  }
  input.get();  //read in newline

  //add .h to filename and null character
  filename[namelength] = '.';
  filename[namelength+1] = 'h';
  filename[namelength+2] = '\0';
  objectname[namelength] = '\0';

  //open output file
  ofstream output(filename);

  //write header information to header file
  output << "/****************************************\n";
  output << "This header file is automatically generated\n";
  output << "by " << argv[0] << " using data from " << argv[1] << endl;
  output << "****************************************/\n\n";
  output << "#ifndef " << objectname << "_h\n";
  output << "#define " << objectname << "_h\n\n";
  output << "#include \"Material.h\"\n\n";

  output << "class " << objectname << ": public Material {\n";
  output << "\t" << "public:\n";
  output << "\t  " << "//constructor\n";
  output << "\t  " << objectname << "() {\n";

  //start reading in numbers
  double input_num;
  int Nproducts, Nenergies, Nreact;

  //read in material id -- use constant name defined in material.h
  namelength = 0;   //length of string
  while (input.peek() != '\n') { //read until end of first line
    idcode[namelength] = input.get();
    namelength ++;
  }
  input.get();  //read in newline

  //add '\0' to filename and null character
  idcode[namelength] = '\0';

  output << "\t\t" << "id = " << idcode << ";\n";

  input >> input_num; //atomic mass
  output << "\t\t" << "A = " << input_num << ";\n";

  input >> input_num; //specific heat capacity
  output << "\t\t" << "Cv = " << input_num << ";\n";

  input >> input_num; //density
  output << "\t\t" << "rho = " << input_num << ";\n";

  input >> Nreact; //number of reactions
  output << "\t\t" << "Nr = " << Nreact << ";\n";

  //initialize all the arrays we can now that we know how many reactions there are
  if (Nreact > 0) {
    output << "\t\t" << "//initialize arrays\n";
    output << "\t\t" << "Ne = new int[Nr];            //array of numbers of energies per reaction\n";
    output << "\t\t" << "energies = new double*[Nr];  //array of energies\n";
    output << "\t\t" << "sigmas = new double*[Nr];    //array of cross-sections\n";
    output << "\t\t" << "Q = new double[Nr];          //array of cross-sections\n";
    output << "\t\t" << "Nneut = new double[Nr];      //array of neutrons produced\n";
    output << "\t\t" << "Nprod = new int[Nr];         //array of cross-sections\n";
    output << "\t\t" << "products = new int*[Nr];     //array of integer codes of products\n\n";
  }

  //loop through reactions
  for (int i=0; i<Nreact; i++) {
    output << "\t\t//***** Reaction " << i << " *****\n";
    input >> Nenergies;      //number of energy bins in ith reaction
    output << "\t\t" << "Ne[" << i << "] = " << Nenergies << "; //Number of energy bins in reaction " << i << endl;
    output << "\t\t" << "energies[" << i << "] = new double[" << Nenergies << "]; //initialize energy array for reaction " << i << endl;
    output << "\t\t" << "sigmas[" << i << "] = new double[" << Nenergies << "]; //initialize sigma array for reaction " << i << endl;

    input >> Nproducts; //number of products for ith reaction
    output << "\t\t" << "Nprod[" << i << "] = " << Nproducts <<"; //number of products for reaction " << i << endl;
    output << "\t\t" << "products[" << i << "] = new int[" << Nproducts << "]; //initialize array to store products\n";

    //loop through products of ith reaction
    output << "\n\t\t" << "//products for reaction " << i << " (see material.h for constant definitions)\n";
    input.get();  //read in newline from previous line
    for (int j=0; j < Nproducts; j++) {
      //these will be stored as strings according to constants defined in material.h
      namelength = 0;   //length of string
      while (input.peek() != '\n') { //read until end of first line
	productname[namelength] = input.get();
	namelength ++;
      }
      input.get();  //read in newline

      //add '\0' to filename and null character
      productname[namelength] = '\0';

      output << "\t\t" << "products[" << i << "][" << j << "] = " << productname << ";\n";
    }

    input >> input_num;  //number of neutrons produced
    output << "\n\t\t" << "Nneut[" << i << "] = " << input_num << ";  //number of neutrons in reaction " << i << endl;

    input >> input_num;  //Q value for this reaction (energy released)
    output << "\n\t\t" << "Q[" << i << "] = " << input_num << ";  //Q value for reaction " << i << endl;

    output << endl << "\t\t//***********Cross-section vs energy reaction " << i << " *************\n";
    for (int j = 0; j < Nenergies; j++) {
      input >> input_num;  //energy
      input_num /= 1e6;   //convert from eV to meV
      output << "\t\t" << "energies[" << i << "][" << j << "] = " << input_num << ";\n";
      input >> input_num;  //cross section
      input_num /= 1e28;   //convert from barns to m^-2
      output << "\t\t" << "sigmas[" << i << "][" << j << "] = " << input_num << ";\n";
    }

    output << endl;  //extra endl to put break between next reaction
  } //end loop on i = 0 < Nr (loop on different reactions)

  output << "\t  }  //end of constructor\n\n";
  
  output << "\t  //destructor\n";
  output << "\t  ~" << objectname << "() {\n\n";
  if (Nreact > 0) {
    output << "\t\t" << "//clear double arrays\n";
    output << "\t\t" << "for(int i=0; i<Nr; i++) {  //loop through each reaction\n";
    output << "\t\t  delete [] energies[i];\n";
    output << "\t\t  delete [] sigmas[i];\n";
    output << "\t\t  delete [] products[i];\n";
    output << "\t\t}\n\n";

    output << "\t\t//delete the 1D arrays (and what is left of 2d)\n";
    output << "\t\t" << "delete [] Ne;\n";
    output << "\t\t" << "delete [] energies;\n";
    output << "\t\t" << "delete [] sigmas;\n";
    output << "\t\t" << "delete [] Q;\n";
    output << "\t\t" << "delete [] Nneut;\n";
    output << "\t\t" << "delete [] Nprod;\n";
    output << "\t\t" << "delete [] products;\n";
  }
  output << "\t  }\n";
  output << "};\n\n";


  output << "#endif\n";
    

  //close input and output files
  input.close();
  output.close();

  return 0;
}

