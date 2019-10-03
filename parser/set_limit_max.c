/*
** set_limit_max.c for setlimitmax in /home/schrey_i//local/work/RT/rtv42/hardil_h/raytracer/parser
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Thu Jun  2 14:06:49 2011 ithyvan schreys
** Last update Sat Jun  4 21:26:45 2011 henri hardillier
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"main.h"
#include		"parser.h"

int		set_limit_max_x(t_obj *object, char **tab)
{
  if (is_num(tab[1]))
    object->limit_max[X] = atof(tab[1]);
  return (SUCCESS);
}

int		set_limit_max_y(t_obj *object, char **tab)
{
  if (is_num(tab[1]))
    object->limit_max[Y] = atof(tab[1]);
  return (SUCCESS);
}

int		set_limit_max_z(t_obj *object, char **tab)
{
  if (is_num(tab[1]))
    object->limit_max[Z] = atof(tab[1]);
  return (SUCCESS);
}
