/*
** sphere.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/limits
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 22:04:07 2011 henri hardillier
** Last update Thu Jun  2 23:11:37 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_sphere(t_rt *rt, t_obj *sphere)
{
  if (is_hide(sphere))
    {
      sphere->k = k_sphere(rt->eye.eye, rt->eye.vector, sphere, MAX);
      inter_point_calcul(sphere, rt->eye.eye, rt->eye.vector);
      (void)is_hide(sphere);
      sphere->vector[X] = sphere->point[X];
      sphere->vector[Y] = sphere->point[Y];
      sphere->vector[Z] = sphere->point[Z];
      revise_vector(rt, sphere);
    }
}
