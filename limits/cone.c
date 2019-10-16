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
