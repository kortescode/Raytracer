#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_hyperboloid(t_rt *rt, t_obj *hyperboloid)
{
  if (is_hide(hyperboloid))
    {
      hyperboloid->k = k_hyperboloid(rt->eye.eye, rt->eye.vector,
				     hyperboloid, MAX);
      inter_point_calcul(hyperboloid, rt->eye.eye, rt->eye.vector);
      (void)is_hide(hyperboloid);
      hyperboloid->vector[X] = hyperboloid->point[X];
      hyperboloid->vector[Y] = hyperboloid->point[Y];
      hyperboloid->vector[Z] = hyperboloid->point[Z] * -hyperboloid->constant;
      revise_vector(rt, hyperboloid);
    }
}
