/*
** paraboloid.c<2> for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/k_calculs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:57:23 2011 henri hardillier
** Last update Fri Jun  3 16:37:02 2011 henri hardillier
*/

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
