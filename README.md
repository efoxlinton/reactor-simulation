# reactor-simulation
purpose of this program is to simulate nuclear reactions by evolving individual neutrons through time
header_creator.cxx -- reads data files and creates a header file for each element (e.g. created URANIUM235.h from Uranium-235.dat)
    format for data file given in comments at top of header_creator.cxx
my_reactor.cxx tests the classes developed for this simultor.  Currently creates file for number of neutrons as a function of time and a
    separate file for x,y coordinates of all neutrons at end of simulation
classes are:
  material.h --parent class for all the element classes created by header_creator.cxx.  Element classes contain infromation such as
      atomic mass, cross-section vs energy curves for allowed reactions, products created, etc.
  neutron.h -- keeps track of neutron position, velocity, energy, etc.
  region.h -- pieces from which a reactor can be made.  Currently allows you to create spheres, cylinders, and rectangular prisms.  
      Can also specify density of each element in region (densities uniform throughout)
  reactor.h -- contains array of regions and array of neutrons.  Also carries out process of evolving neutrons and checking for reactions,
      updating element densities and neutron number/energies if reactions take place
  material_dictionary.h -- class that contains one copy of each type of element.  Essentially an array of elements that allows easy access 
    to element properties.
