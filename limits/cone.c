/*
** cone.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/limits
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 22:04:52 2011 henri hardillier
** Last update Fri Jun  3 19:35:55 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_cone(t_rt *rt, t_obj *cone)
{
  if (is_hide(cone))
    {
      cone->k = k_cone(rt->eye.eye, rt->eye.vector, cone, MAX);
      inter_point_calcul(cone, rt->eye.eye, rt->eye.vector);
      (void)is_hide(cone);
      cone->vector[X] = cone->point[X];
      cone->vector[Y] = cone->point[Y];
      cone->vector[Z] = cone->point[Z] * -cone->constant;
      revise_vector(rt, cone);
    }
}
