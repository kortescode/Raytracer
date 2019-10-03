/*
** hyperboloid.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/limits
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 22:06:24 2011 henri hardillier
** Last update Fri Jun  3 16:38:41 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_hyperboloid(t_rt *rt, t_obj *hyperboloid)
{
  if (is_hide(hyperboloid))
    {
      hyperboloid->k = k_hyperboloid(rt->eye.eye, rt->eye.vector,
				     hyperboloid, MAX);
      inter_point_calcul(hyperboloid, rt->eye.eye, rt->eye.vector);
      (void)is_hide(hyperboloid);
      hyperboloid->vector[X] = hyperboloid->point[X];
      hyperboloid->vector[Y] = hyperboloid->point[Y];
      hyperboloid->vector[Z] = hyperboloid->point[Z] * -hyperboloid->constant;
      revise_vector(rt, hyperboloid);
    }
}
