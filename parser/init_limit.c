#include	<stdlib.h>
#include	"main.h"

void		init_limit(t_obj *object)
{
  object->limit_min[X] = -0xFFFFFF;
  object->limit_min[Y] = -0xFFFFFF;
  object->limit_min[Z] = -0xFFFFFF;
  object->limit_max[X] = 0xFFFFFF;
  object->limit_max[Y] = 0xFFFFFF;
  object->limit_max[Z] = 0xFFFFFF;
}
