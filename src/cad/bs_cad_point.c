#include "bs_cad_point.h"
#include <stdlib.h>


struct BsCadPoint * bs_cad_point_create(float x, float y, float z)
{
  struct BsCadPoint * point ;

  point = (struct BsCadPoint *)malloc(sizeof(struct BsCadPoint));
  if(point == NULL)
    exit(0);

  point->x_pos = x;
  point->y_pos = y;
  point->z_pos = z;

  return point;
}
