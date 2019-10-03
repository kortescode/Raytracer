/*
** paraboloid.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/limits
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 22:05:20 2011 henri hardillier
** Last update Fri Jun  3 16:38:29 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_paraboloid(t_rt *rt, t_obj *paraboloid)
{
  if (is_hide(paraboloid))
    {
      paraboloid->k = k_paraboloid(rt->eye.eye, rt->eye.vector,
				   paraboloid, MAX);
      inter_point_calcul(paraboloid, rt->eye.eye, rt->eye.vector);
      (void)is_hide(paraboloid);
      paraboloid->vector[X] = paraboloid->point[X];
      paraboloid->vector[Y] = paraboloid->point[Y];
      paraboloid->vector[Z] = -paraboloid->constant;
      revise_vector(rt, paraboloid);
    }
}
