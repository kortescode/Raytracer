#include	"main.h"
#include	"k.h"

double		k_hyperboloid(double point[], double vector[],
			      t_obj *hyperboloid, int mode)
{
  double       	var[3];

  var[A] = SQR(vector[X]) + SQR(vector[Y])
           - SQR(vector[Z]) * hyperboloid->constant;
  var[B] = 2.0 * (point[X] * vector[X] + point[Y] * vector[Y] -
		  point[Z] * vector[Z] * hyperboloid->constant);
  var[C] = SQR(point[X]) + SQR(point[Y]) - SQR(point[Z])
           * hyperboloid->constant - 1;
  return (delta_calcul(var, mode));
}
