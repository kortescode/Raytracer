#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_paraboloid(t_rt *rt, t_obj *paraboloid)
{
  if (is_hide(paraboloid))
    {
      paraboloid->k = k_paraboloid(rt->eye.eye, rt->eye.vector,
				   paraboloid, MAX);
      inter_point_calcul(paraboloid, rt->eye.eye, rt->eye.vector);
      (void)is_hide(paraboloid);
      paraboloid->vector[X] = paraboloid->point[X];
      paraboloid->vector[Y] = paraboloid->point[Y];
      paraboloid->vector[Z] = -paraboloid->constant;
      revise_vector(rt, paraboloid);
    }
}
