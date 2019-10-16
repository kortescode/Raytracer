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
