#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"inter.h"
#include	"limits.h"

void		limits_cylinder(t_rt *rt, t_obj *cylinder)
{
  if (is_hide(cylinder))
    {
      cylinder->k = k_cylinder(rt->eye.eye, rt->eye.vector, cylinder, MAX);
      inter_point_calcul(cylinder, rt->eye.eye, rt->eye.vector);
      (void)is_hide(cylinder);
      cylinder->vector[X] = cylinder->point[X];
      cylinder->vector[Y] = cylinder->point[Y];
      cylinder->vector[Z] = 0.0;
      revise_vector(rt, cylinder);
    }
}
