/*
** hyperboloid.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/inter
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 21:48:46 2011 henri hardillier
** Last update Fri Jun  3 19:47:57 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"inter.h"
#include	"movements.h"
#include	"limits.h"

void		inter_hyperboloid(t_rt *rt, t_obj *hyperboloid)
{
  hyperboloid->k = k_hyperboloid(rt->eye.eye, rt->eye.vector,
				 hyperboloid, MIN);
  inter_point_calcul(hyperboloid, rt->eye.eye, rt->eye.vector);
  hyperboloid->vector[X] = hyperboloid->point[X];
  hyperboloid->vector[Y] = hyperboloid->point[Y];
  hyperboloid->vector[Z] = hyperboloid->point[Z] * -hyperboloid->constant;
  limits_hyperboloid(rt, hyperboloid);
  rotate(hyperboloid->vector, hyperboloid->rotation[X],
	 hyperboloid->rotation[Y], hyperboloid->rotation[Z]);
  rotate(hyperboloid->point, hyperboloid->rotation[X],
	 hyperboloid->rotation[Y], hyperboloid->rotation[Z]);
  translate(hyperboloid->point, hyperboloid->position[X],
	    hyperboloid->position[Y], hyperboloid->position[Z]);
}
