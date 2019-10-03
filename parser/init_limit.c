/*
** init_limit.c for limit_init.c in /home/schrey_i//local/work/RT/rtv42/hardil_h/raytracer/parser
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Thu Jun  2 14:12:00 2011 ithyvan schreys
** Last update Thu Jun  2 22:57:58 2011 henri hardillier
*/

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
