#ifndef MATERIAL_DICT_H
#define MATERIAL_DICT_H

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "material.h"
#include "URANIUM235.h"
#include "URANIUM238.h"
#include "BARIUM144.h"
#include "KRYPTON89.h"
#include "XENON140.h"
#include "STRONTIUM94.h"

#define SPHERE 1   //types of shapes we can have
#define RECT_PRISM 2
#define CYLINDER 3

using std::ofstream;
using std::ostream;
using std::string;



class Material_Dictionary {
 private:
  URANIUM235 myu235;
  URANIUM238 myu238;
  BARIUM144 myba144;
  KRYPTON89 mykr89;
  XENON140 myxe140;

 public:
  //constructor
  Material_Dictionary() {}


  //accessor
  Material look_up(int type) {
    if (type == U235) {
      return myu235;
    } else if (type == U238) {
      return myu238;
    } else if (type == Ba144) {
      return myba144;
    } else if (type == Kr89) {
      return mykr89;
    } else {
      return myxe140;
    }
  }

  //destructor
  ~Material_Dictionary() {}
};


#endif  //ifndef MATERIAL_DICT
