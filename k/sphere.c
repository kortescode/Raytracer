#include	"main.h"
#include	"k.h"

double		k_sphere(double point[], double vector[],
			 t_obj *sphere, int mode)
{
   double       	var[3];

   var[A] = SQR(vector[X]) + SQR(vector[Y]) + SQR(vector[Z]);
   var[B] = 2.0 * (point[X] * vector[X] + point[Y] * vector[Y]
		   + point[Z] * vector[Z]);
   var[C] = SQR(point[X]) + SQR(point[Y])
            + SQR(point[Z]) - SQR(sphere->radius);
   return (delta_calcul(var, mode));
}
