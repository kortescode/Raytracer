/*
** reflexion.c for rt in /home/hardil_h//Desktop/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Jun  3 21:07:37 2011 henri hardillier
** Last update Mon Jun  6 19:55:53 2011 henri hardillier
*/

#include		<stdio.h>
#include		<math.h>

#include		"main.h"
#include		"k.h"
#include		"effects.h"
#include		"movements.h"

t_k			calcul_k[] =
  {
    {k_plan},
    {k_sphere},
    {k_cylinder},
    {k_cone},
    {k_paraboloid},
    {k_hyperboloid},
    {0},
  };

static void		get_value(t_rt *rt, double *value, int mode)
{
  t_obj			*objs;

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

static unsigned int	getcolor(t_rt *rt)
{
  t_obj			*objs;
  double		value;

  value = HIDE;
  get_value(rt, &value, MAX);
  get_value(rt, &value, MIN);
  if (value == HIDE)
    return (BLACK);
  objs = rt->obj;
  while (objs && objs->k != value)
    objs = objs->next;
  if (!objs)
    return (BLACK);
  return (luminosity(rt, objs));
}

static unsigned int	transparency_calcul(t_rt *rt, t_obj *obj,
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
      objs->k = calcul_k[objs->object].func(rt->eye.eye, rt->eye.vector,
					     objs, MIN);
      rotate(rt->eye.vector, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      rotate(rt->eye.eye, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      translate(rt->eye.eye, objs->position[X],
		objs->position[Y], objs->position[Z]);
      objs = objs->next;
    }
  obj->k = HIDE;
  return (modif_color_with_effect(color, getcolor(rt), obj->transparency));
}

unsigned int		transparency(t_rt *rt, t_obj *obj, unsigned int color)
{
  double		n;
  double		scal_vn;
  double		normal_v;
  double		normal_n;
  double		vector[3];
  unsigned int		trans_color;

  n = 1.0 / obj->index;
  normal_v = sqrtf(SQR(rt->eye.vector[X]) + SQR(rt->eye.vector[Y])
		   + SQR(rt->eye.vector[Z]));
  normal_n = sqrtf(SQR(obj->vector[X]) + SQR(obj->vector[Y])
		   + SQR(obj->vector[Z]));
  scal_vn = rt->eye.vector[X] * obj->vector[X] + rt->eye.vector[Y]
            * obj->vector[Y] + rt->eye.vector[Z] * obj->vector[Z];
  vector[X] = (n * (rt->eye.vector[X] / normal_v)) + ((n * scal_vn) - sqrtf(1
	      + (SQR(n) * (SQR(scal_vn) - 1)))) * (obj->vector[X] / normal_n);
  vector[Y] = (n * (rt->eye.vector[Y] / normal_v)) + ((n * scal_vn) - sqrtf(1
	      + (SQR(n) * (SQR(scal_vn) - 1)))) * (obj->vector[Y] / normal_n);
  vector[Z] = (n * (rt->eye.vector[Z] / normal_v)) + ((n * scal_vn) - sqrtf(1
	      + (SQR(n) * (SQR(scal_vn) - 1)))) * (obj->vector[Z] / normal_n);
  save_restore_transparency_values(rt, obj->point, vector, SAVE);
  trans_color = transparency_calcul(rt, obj, color);
  save_restore_transparency_values(rt, obj->point, vector, RESTORE);
  return (trans_color);
}
