#include	"main.h"

void		translate(double old[], double angle_x, double angle_y, double angle_z)
{
  double       	new[3];

  new[X] = old[X] + angle_x;
  new[Y] = old[Y] + angle_y;
  new[Z] = old[Z] + angle_z;
  old[X] = new[X];
  old[Y] = new[Y];
  old[Z] = new[Z];
}
