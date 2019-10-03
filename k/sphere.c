/*
** sphere.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/k_calculs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:55:52 2011 henri hardillier
** Last update Fri Jun  3 16:35:28 2011 henri hardillier
*/

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
