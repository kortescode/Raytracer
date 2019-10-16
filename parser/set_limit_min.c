#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"main.h"
#include		"parser.h"

int		set_limit_min_x(t_obj *object, char **tab)
{
  if (is_num(tab[1]))
    object->limit_min[X] = atof(tab[1]);
  return (SUCCESS);
}

int		set_limit_min_y(t_obj *object, char **tab)
{
  if (is_num(tab[1]))
    object->limit_min[Y] = atof(tab[1]);
  return (SUCCESS);
}

int		set_limit_min_z(t_obj *object, char **tab)
{
  if (is_num(tab[1]))
    object->limit_min[Z] = atof(tab[1]);
  return (SUCCESS);
}
