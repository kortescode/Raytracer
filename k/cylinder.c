#include	"main.h"
#include	"k.h"

double		k_cylinder(double point[], double vector[],
			   t_obj *cylinder, int mode)
{
  double       	var[3];

  var[A] = SQR(vector[X]) + SQR(vector[Y]);
  var[B] = 2.0 * (point[X] * vector[X] + point[Y] * vector[Y]);
  var[C] = SQR(point[X]) + SQR(point[Y]) - SQR(cylinder->radius);
  return (delta_calcul(var, mode));
}
