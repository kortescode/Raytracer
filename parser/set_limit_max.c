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
