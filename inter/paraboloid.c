/*
** paraboloid.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/inter
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:48:17 2011 henri hardillier
** Last update Fri Jun  3 19:47:57 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"inter.h"
#include	"movements.h"
#include	"limits.h"

void		inter_paraboloid(t_rt *rt, t_obj *paraboloid)
{
  paraboloid->k = k_paraboloid(rt->eye.eye, rt->eye.vector, paraboloid, MIN);
  inter_point_calcul(paraboloid, rt->eye.eye, rt->eye.vector);
  paraboloid->vector[X] = paraboloid->point[X];
  paraboloid->vector[Y] = paraboloid->point[Y];
  paraboloid->vector[Z] = -paraboloid->constant;
  limits_paraboloid(rt, paraboloid);
  rotate(paraboloid->vector, paraboloid->rotation[X],
	 paraboloid->rotation[Y], paraboloid->rotation[Z]);
  rotate(paraboloid->point, paraboloid->rotation[X],
	 paraboloid->rotation[Y], paraboloid->rotation[Z]);
  translate(paraboloid->point, paraboloid->position[X],
	    paraboloid->position[Y], paraboloid->position[Z]);
}
