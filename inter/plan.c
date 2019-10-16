#include	"main.h"
#include	"k.h"
#include	"inter.h"
#include	"movements.h"
#include	"limits.h"

void		inter_plan(t_rt *rt, t_obj *plan)
{
  plan->k = k_plan(rt->eye.eye, rt->eye.vector, plan, MIN);
  inter_point_calcul(plan, rt->eye.eye, rt->eye.vector);
  plan->vector[X] = 0.0;
  plan->vector[Y] = 0.0;
  plan->vector[Z] = 100.0;
  (void)is_hide(plan);
  rotate(plan->vector, plan->rotation[X],
	 plan->rotation[Y], plan->rotation[Z]);
  rotate(plan->point, plan->rotation[X],
	 plan->rotation[Y], plan->rotation[Z]);
  translate(plan->point, plan->position[X],
	    plan->position[Y], plan->position[Z]);
}
