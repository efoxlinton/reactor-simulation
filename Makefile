CXX=g++

all:	header_creator my_reactor

header_creator: header_creator.o
	$(CXX) -o $@ $^

header_creator.o: header_creator.cxx
	$(CXX) header_creator.cxx -c

my_reactor: my_reactor.o reactor.o material.o neutron.o region.o
	$(CXX) -o $@ $^

my_reactor.o: my_reactor.cxx reactor.o material.o neutron.o region.o
	$(CXX) my_reactor.cxx -c

reactor.o: reactor.cxx material.o reactor.h neutron.o region.o
	$(CXX) reactor.cxx -c

neutron.o: neutron.cxx neutron.h
	$(CXX) neutron.cxx -c

region.o: region.cxx region.h
	$(CXX) region.cxx -c

material.o: material.cxx material.h
	$(CXX) material.cxx -c
