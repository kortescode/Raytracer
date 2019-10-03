/*
** get_obj_color.c for rt in /home/hardil_h//projets/raytracer/rtv42/hardil_h/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu May 26 20:13:49 2011 henri hardillier
** Last update Mon Jun  6 20:00:06 2011 henri hardillier
*/

#include	"main.h"
#include	"k.h"
#include	"effects.h"

static void	get_value(t_rt *rt, double *value, int mode)
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

unsigned int	get_color(t_rt *rt)
{
  t_obj		*objs;
  double	value;
  unsigned int	color;

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
  color = luminosity(rt, objs);
  if (objs->transparency > 0.0)
    color = transparency(rt, objs, color);
  if (objs->reflection > 0.0)
    color = reflection(rt, objs, color);
  return (color);
}
