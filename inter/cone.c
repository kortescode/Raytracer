/*
** cone.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/inter
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:47:47 2011 henri hardillier
** Last update Fri Jun  3 19:47:57 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"inter.h"
#include	"movements.h"
#include	"limits.h"

void		inter_cone(t_rt *rt, t_obj *cone)
{
  cone->k = k_cone(rt->eye.eye, rt->eye.vector, cone, MIN);
  inter_point_calcul(cone, rt->eye.eye, rt->eye.vector);
  cone->vector[X] = cone->point[X];
  cone->vector[Y] = cone->point[Y];
  cone->vector[Z] = cone->point[Z] * -cone->constant;
  limits_cone(rt, cone);
  rotate(cone->vector, cone->rotation[X],
	 cone->rotation[Y], cone->rotation[Z]);
  rotate(cone->point, cone->rotation[X],
	 cone->rotation[Y], cone->rotation[Z]);
  translate(cone->point, cone->position[X],
	    cone->position[Y], cone->position[Z]);
}
