#ifndef BS_CAD_OBJECT_H 
#define BS_CAD_OBJECT_H 


#include "bs_cad_point.h"

struct BsCadObject
{
  char *name;
  struct BsCadPoint anchor; // Reference point for the object
  float rotation_angles[3]; // For x, y, and z axis
};













#endif

