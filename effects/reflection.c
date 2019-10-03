/*
** reflexion.c for rt in /home/hardil_h//Desktop/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Jun  3 21:07:37 2011 henri hardillier
** Last update Tue Jun  7 02:37:13 2011 henri hardillier
*/

#include		<math.h>

#include		"k.h"
#include		"main.h"
#include		"inter.h"
#include		"effects.h"
#include		"movements.h"

t_inter			calc_inter[] =
  {
    {inter_plan},
    {inter_sphere},
    {inter_cylinder},
    {inter_cone},
    {inter_paraboloid},
    {inter_hyperboloid},
    {0},
  };

/*static void	get_value(t_rt *rt, double *value, int mode)
{
  t_obj		*objs;

  objs = rt->obj;
  while (objs)
    {
      if (mode == MAX)
	*value = MAX(*value, objs->k);
      else if (mode == MIN && objs->k != HIDE)
	*value = MIN(*value, objs->k);
      objs = objs->next;
    }
}

static int	getcolor(t_rt *rt)
{
  t_obj		*objs;
  double	value;
  unsigned int	color;

  value = HIDE;
  get_value(rt, &value, MAX);
  get_value(rt, &value, MIN);
  if (value == HIDE)
    return (NOTHING);
  objs = rt->obj;
  while (objs && objs->k != value)
    objs = objs->next;
  if (!objs)
    return (NOTHING);
  color = luminosity(rt, objs);
  if (objs->transparency > 0.0)
    color = transparency(rt, objs, color);
  if (objs->reflection > 0.0)
    color = reflection(rt, objs, color);
  return (color);
  }*/

static unsigned int	refected_calcul(t_rt *rt, t_obj *obj,
					unsigned int color)
{
  t_obj			*objs;

  objs = rt->obj;
  while (objs)
    {
      translate(rt->eye.eye, -objs->position[X],
		-objs->position[Y], -objs->position[Z]);
      rev_rotate(rt->eye.eye, -objs->rotation[X],
		 -objs->rotation[Y], -objs->rotation[Z]);
      rev_rotate(rt->eye.vector, -objs->rotation[X],
		 -objs->rotation[Y], -objs->rotation[Z]);
      calc_inter[objs->object].func(rt, objs);
      rotate(rt->eye.vector, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      rotate(rt->eye.eye, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      translate(rt->eye.eye, objs->position[X],
		objs->position[Y], objs->position[Z]);
      objs = objs->next;
    }
  obj->k = HIDE;
  return (modif_color_with_effect(color, get_color(rt), obj->reflection));
}

unsigned int		reflection(t_rt *rt, t_obj *obj, unsigned int color)
{
  double		scal_vn;
  double		normal_v;
  double		normal_n;
  double		vector[3];

  normal_v = sqrtf(SQR(rt->eye.vector[X]) + SQR(rt->eye.vector[Y])
		   + SQR(rt->eye.vector[Z]));
  normal_n = sqrtf(SQR(obj->vector[X]) + SQR(obj->vector[Y])
		   + SQR(obj->vector[Z]));
  scal_vn = rt->eye.vector[X] * obj->vector[X] + rt->eye.vector[Y]
            * obj->vector[Y] + rt->eye.vector[Z] * obj->vector[Z];
  vector[X] = -2.0 * (obj->vector[X] / normal_n) * scal_vn
              + (rt->eye.vector[X] / normal_v);
  vector[Y] = -2.0 * (obj->vector[Y] / normal_n) * scal_vn
              + (rt->eye.vector[Y] / normal_v);
  vector[Z] = -2.0 * (obj->vector[Z] / normal_n) * scal_vn
              + (rt->eye.vector[Z] / normal_v);
  rt->eye.eye[X] = obj->point[X];
  rt->eye.eye[Y] = obj->point[Y];
  rt->eye.eye[Z] = obj->point[Z];
  rt->eye.vector[X] = vector[X];
  rt->eye.vector[Y] = vector[Y];
  rt->eye.vector[Z] = vector[Z];
  return (refected_calcul(rt, obj, color));
}
