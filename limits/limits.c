#include	"main.h"

int		is_hide(t_obj *object)
{
  if (object->point[X] > object->limit_max[X] ||
      object->point[X] < object->limit_min[X] ||
      object->point[Y] > object->limit_max[Y] ||
      object->point[Y] < object->limit_min[Y] ||
      object->point[Z] > object->limit_max[Z] ||
      object->point[Z] < object->limit_min[Z])
    {
      object->k = HIDE;
      return (TRUE);
    }
  return (FALSE);
}

void		revise_vector(t_rt *rt, t_obj *object)
{
  double	scal;

  scal = (rt->eye.vector[X] * object->vector[X])
         + (rt->eye.vector[Y] * object->vector[Y])
         + (rt->eye.vector[Z] * object->vector[Z]);
  if (scal > 0)
    {
      object->vector[X] *= -1;
      object->vector[Y] *= -1;
      object->vector[Z] *= -1;
    }
}

