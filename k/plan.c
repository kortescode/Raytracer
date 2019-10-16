#include	"main.h"

double		k_plan(double point[], double vector[],
		       __attribute__((unused))t_obj *plan,
		       __attribute__((unused))int mode)
{
  double	k;

  k = -point[Z] / vector[Z];
  if (k < 0.0)
    return (HIDE);
  return (k);
}
