/*
** cylinder.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/limits
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 22:04:32 2011 henri hardillier
** Last update Thu Jun  2 23:11:37 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_cylinder(t_rt *rt, t_obj *cylinder)
{
  if (is_hide(cylinder))
    {
      cylinder->k = k_cylinder(rt->eye.eye, rt->eye.vector, cylinder, MAX);
      inter_point_calcul(cylinder, rt->eye.eye, rt->eye.vector);
      (void)is_hide(cylinder);
      cylinder->vector[X] = cylinder->point[X];
      cylinder->vector[Y] = cylinder->point[Y];
      cylinder->vector[Z] = 0.0;
      revise_vector(rt, cylinder);
    }
}
