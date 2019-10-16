#include	"main.h"
#include	"k.h"
#include	"effects.h"
#include	"movements.h"
#include	"inter.h"
#include	"limits.h"

t_k		k_calculs[] =
  {
    {k_plan},
    {k_sphere},
    {k_cylinder},
    {k_cone},
    {k_paraboloid},
    {k_hyperboloid},
    {0},
  };

static void	is_shadow(t_obj *obj, t_obj *objs, t_lumin *lumin, int *shadow)
{
  if (objs->k != obj->k)
    {
      save_restore_shadow_values(objs, SAVE);
      objs->k = k_calculs[objs->object].func(obj->point, lumin->vector_l,
					     objs, MIN);
      inter_point_calcul(objs, obj->point, lumin->vector_l);
      if (objs->k > 0.0 && objs->k < 1.0 && !is_hide(objs))
	*shadow = TRUE;
      objs->k = k_calculs[objs->object].func(obj->point, lumin->vector_l,
					     objs, MAX);
      inter_point_calcul(objs, obj->point, lumin->vector_l);
      if (objs->k > 0.0 && objs->k < 1.0 && !is_hide(objs))
	*shadow = TRUE;
      save_restore_shadow_values(objs, RESTORE);
    }
}

unsigned int	shadows(t_rt *rt, t_obj *obj, t_lumin *lumin,
			unsigned int color)
{
  int		shadow;
  t_obj		*objs;

  shadow = FALSE;
  objs = rt->obj;
  while (objs)
    {
      translate(obj->point, -objs->position[X],
		-objs->position[Y], -objs->position[Z]);
      rev_rotate(obj->point, -objs->rotation[X],
		 -objs->rotation[Y], -objs->rotation[Z]);
      rev_rotate(lumin->vector_l, -objs->rotation[X],
		 -objs->rotation[Y], -objs->rotation[Z]);
      is_shadow(obj, objs, lumin, &shadow);
      rotate(lumin->vector_l, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      rotate(obj->point, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      translate(obj->point, objs->position[X],
		objs->position[Y], objs->position[Z]);
      objs = objs->next;
    }
  if (shadow == TRUE)
    return (BLACK);
  return (color);
}
