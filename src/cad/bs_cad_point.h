#ifndef BS_CAD_POINT_H 
#define BS_CAD_POINT_H 



struct BsCadPoint
{
  float x_pos;
  float y_pos;
  float z_pos;
};


struct BsCadPoint * bs_cad_point_create(float x, float y, float z);











#endif

