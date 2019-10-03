/*
** cylinder.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/k_calculs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:56:15 2011 henri hardillier
** Last update Fri Jun  3 16:38:13 2011 henri hardillier
*/

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
