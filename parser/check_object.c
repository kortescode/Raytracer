#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"errors.h"
#include		"inter.h"
#include		"parser.h"
#include		"my.h"

t_parseobj		ptr_obj[] =
  {
    {"position", set_position},
    {"color", define_color_obj},
    {"rotation", set_rotation},
    {"radius", set_radius},
    {"constant", set_constant},
    {"gloss", set_gloss},
    {"transparency", set_transparency},
    {"reflection", set_reflection},
    {"index", set_index},
    {"limit_min_x", set_limit_min_x},
    {"limit_min_y", set_limit_min_y},
    {"limit_min_z", set_limit_min_z},
    {"limit_max_x", set_limit_max_x},
    {"limit_max_y", set_limit_max_y},
    {"limit_max_z", set_limit_max_z},
    {NULL, NULL},
  };

t_setobj		ptr_set[] =
  {
    {"SPHERE", SPHERE},
    {"CONE", CONE},
    {"PLAN", PLAN},
    {"CYLINDER", CYLINDER},
    {"PARABOLOID", PARABOLOID},
    {"HYPERBOLOID", HYPERBOLOID},
    {NULL, NOTHING},
  };

static void		set_object_type(char *type, t_obj *obj)
{
  int			n;

  n = 0;
  while (ptr_set[n].str)
    {
      if (!strcmp(type, ptr_set[n].str))
	obj->object = ptr_set[n].value;
      n++;
    }
}

static void		check_arg(t_obj *object, char **tab, char *type)
{
  int			n;
  int			check;

  n = 0;
  check = FAILURE;
  set_object_type(type, object);
  while (ptr_obj[n].str)
    {
      if (tab[0] && !strcmp(tab[0], ptr_obj[n].str))
	{
	  if ((check = ptr_obj[n].func(object, tab)) == FAILURE)
	    {
	      fprintf(stderr, ERRSYN, tab[0]);
	      exit(EXIT_FAILURE);
	    }
	}
      n++;
    }
  if (tab[0] && check == FAILURE)
    {
      fprintf(stderr, ERROPT, tab[0]);
      exit(EXIT_FAILURE);
    }
}

void			check_object(t_obj *object, char **tab)
{
  int			i;
  char			**arg;

  i = 1;
  while (tab[i])
    {
      arg = my_worldtab(tab[i], "=, ");
      if (!arg[1])
	{
	  fprintf(stderr, ERRSYN, arg[0]);
	  exit(EXIT_FAILURE);
	}
      check_arg(object, arg, tab[0]);
      xfree_tab(arg);
      i++;
    }
}
