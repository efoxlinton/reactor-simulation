/****************************************************************
my_reactor.cxx -- uses reactor.h to actually construct and run reactor
currently being used to test necessary classes
*****************************************************************/

#include <cstdlib>
#include "reactor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <time.h>


using std::cout;
using std::cerr;
using std::endl;
using std::cin;
using std::ofstream;
using std::ifstream;

int main(int argc, char *argv[]) {

  srand(time(0));  //seed random number generator

  //read in data
  if (argc != 3) {    //incorrect function call, so write instructions to the screen
    cerr << "Usage: " << argv[0] << " input_filename output_filename\n";
    return -1;
  }


  //create reactor
  Reactor myreactor(argv[1]);

  //open output file
  ofstream output(argv[2]);
  output << "time(s)\t" << "neutrons\n";

  //add some neutrons
  for (int i=0; i<10; i++) {
    myreactor.add_neutron(0, 0, 0, 20);  //add 10 20 MeV neutrons in middle of detector
  }

  double dt = 1e-10;  //time step-size in seconds
  double max_t = 5e-8;  //maximum time
  int num_data = 100;  //number of data points recorded to file
  double num_neutrons;

  int write_steps = int(max_t/dt/num_data);  //number of steps taken between writing to file

  for (double time=0; time <= max_t; time += dt) {
    myreactor.react(dt);            //check for reactions

    myreactor.evolve_neutrons(dt);  //move neutrons

    num_neutrons = myreactor.count_neutrons();

    if ((num_neutrons <= 0) || (num_neutrons > 1e8)) {
      cout << "leaving because number of neutrons = " << num_neutrons << endl;
      break;
    }
    
    //see if we need to write to file
    if (int(time/dt)%write_steps == 0) {
      output << time << "\t" << num_neutrons << endl;
    }
  }

  output.close();

  cout << "data written to " << argv[2] << endl;

  //output final coordinates of neutrons to file
  output.open("neutron_xy.csv");

  output << "x,y\n";

  for (int i=0; i<myreactor.get_num_neutrons(); i++) {
    output << myreactor.get_neutron_x(i) << "," << myreactor.get_neutron_y(i) << endl;
  }
    
  output.close();

  return 0;
}


