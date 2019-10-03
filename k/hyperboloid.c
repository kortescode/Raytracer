/*
** hyperboloid.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/k_calculs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:58:10 2011 henri hardillier
** Last update Fri Jun  3 16:37:58 2011 henri hardillier
*/

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
