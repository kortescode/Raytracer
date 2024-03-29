#include	"main.h"
#include	"k.h"
#include	"inter.h"
#include	"movements.h"
#include	"limits.h"

void		inter_cylinder(t_rt *rt, t_obj *cylinder)
{
  cylinder->k = k_cylinder(rt->eye.eye, rt->eye.vector, cylinder, MIN);
  inter_point_calcul(cylinder, rt->eye.eye, rt->eye.vector);
  cylinder->vector[X] = cylinder->point[X];
  cylinder->vector[Y] = cylinder->point[Y];
  cylinder->vector[Z] = 0.0;
  limits_cylinder(rt, cylinder);
  rotate(cylinder->vector, cylinder->rotation[X],
	 cylinder->rotation[Y], cylinder->rotation[Z]);
  rotate(cylinder->point, cylinder->rotation[X],
	 cylinder->rotation[Y], cylinder->rotation[Z]);
  translate(cylinder->point, cylinder->position[X],
	    cylinder->position[Y], cylinder->position[Z]);
}
