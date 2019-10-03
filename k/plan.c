/*
** plan.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/k_calculs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:55:25 2011 henri hardillier
** Last update Thu Jun  2 23:02:59 2011 henri hardillier
*/

#include	"main.h"

double		k_plan(double point[], double vector[],
		       __attribute__((unused))t_obj *plan,
		       __attribute__((unused))int mode)
{
  double	k;

  k = -point[Z] / vector[Z];
  if (k < 0.0)
    return (HIDE);
  return (k);
}
