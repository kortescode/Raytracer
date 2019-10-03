/*
** sphere.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/inter
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:45:41 2011 henri hardillier
** Last update Fri Jun  3 19:47:57 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"inter.h"
#include	"movements.h"
#include	"limits.h"

void		inter_sphere(t_rt *rt, t_obj *sphere)
{
  sphere->k = k_sphere(rt->eye.eye, rt->eye.vector, sphere, MIN);
  inter_point_calcul(sphere, rt->eye.eye, rt->eye.vector);
  sphere->vector[X] = sphere->point[X];
  sphere->vector[Y] = sphere->point[Y];
  sphere->vector[Z] = sphere->point[Z];
  limits_sphere(rt, sphere);
  rotate(sphere->vector, sphere->rotation[X],
	 sphere->rotation[Y], sphere->rotation[Z]);
  rotate(sphere->point, sphere->rotation[X],
	 sphere->rotation[Y], sphere->rotation[Z]);
  translate(sphere->point, sphere->position[X],
	    sphere->position[Y], sphere->position[Z]);
}
