#include	"main.h"
#include	"k.h"

double		k_paraboloid(double point[], double vector[],
			     t_obj *paraboloid, int mode)
{
  double       	var[3];

  var[A] = SQR(vector[X]) + SQR(vector[Y]);
  var[B] = 2.0 * (point[X] * vector[X] + point[Y] * vector[Y])
           - vector[Z] * paraboloid->constant;
  var[C] = SQR(point[X]) + SQR(point[Y]) - point[Z] * paraboloid->constant;
  return (delta_calcul(var, mode));
}
