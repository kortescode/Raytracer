#include	<math.h>

#include	"main.h"

static void	rotate_x(double old[], double angle)
{
  double       	new[3];

  new[X] = old[X];
  new[Y] = old[Y] * cos(angle) + old[Z] * -sin(angle);
  new[Z] = old[Y] * sin(angle) + old[Z] * cos(angle);
  old[X] = new[X];
  old[Y] = new[Y];
  old[Z] = new[Z];
}

static void	rotate_y(double old[], double angle)
{
  double       	new[3];

  new[X] = old[X] * cos(angle) + old[Z] * sin(angle);
  new[Y] = old[Y];
  new[Z] = old[X] * -sin(angle) + old[Z] * cos(angle);
  old[X] = new[X];
  old[Y] = new[Y];
  old[Z] = new[Z];
}

static void	rotate_z(double old[], double angle)
{
  double       	new[3];

  new[X] = old[X] * cos(angle) + old[Y] * -sin(angle);
  new[Y] = old[X] * sin(angle) + old[Y] * cos(angle);
  new[Z] = old[Z];
  old[X] = new[X];
  old[Y] = new[Y];
  old[Z] = new[Z];
}

void	rotate(double old[], double angle_x,
	       double angle_y, double angle_z)
{
  rotate_x(old, DEGREE(angle_x));
  rotate_y(old, DEGREE(angle_y));
  rotate_z(old, DEGREE(angle_z));
}

void	rev_rotate(double old[], double angle_x,
		   double angle_y, double angle_z)
{
  rotate_z(old, DEGREE(angle_z));
  rotate_y(old, DEGREE(angle_y));
  rotate_x(old, DEGREE(angle_x));
}
