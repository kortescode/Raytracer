/*
** define_color.c for rt in /home/joyeux_a//rtv42/hardil_h/raytracer/parser
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Thu Jun  2 14:17:39 2011 anthony joyeux
** Last update Sun Jun  5 10:10:16 2011 henri hardillier
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"my.h"
#include	"effects.h"
#include	"main.h"
#include	"parser.h"

t_parsecolor		ptr_color[] =
  {
    {"BLACK", BLACK},
    {"GREY", GREY},
    {"SILVER", SILVER},
    {"MAROON", MAROON},
    {"PURPLE", PURPLE},
    {"FUCHSIA", FUCHSIA},
    {"RED", RED},
    {"PINK", PINK},
    {"LIME", LIME},
    {"GREEN", GREEN},
    {"OLIVE", OLIVE},
    {"NAVY", NAVY},
    {"BLUE", BLUE},
    {"TEAL", TEAL},
    {"AQUA", AQUA},
    {"YELLOW", YELLOW},
    {"ORANGE", ORANGE},
    {"WHITE", WHITE},
    {NULL, ERROR},
  };

int		define_color_obj(t_obj *obj, char **param)
{
  int		n;

  n = 0;
  if (!param[1])
    return (FAILURE);
  param[1] = my_strupcase(param[1]);
  while (ptr_color[n].str)
    {
      if (param[1] && !strcmp(param[1], ptr_color[n].str))
	{
	  obj->color = ptr_color[n].value;
	  return (SUCCESS);
	}
      n++;
    }
  param[1] = my_strlowcase(param[1]);
  set_color(obj, param);
  return (SUCCESS);
}

int		define_color_spot(t_spot *spot, char **param)
{
  int		n;

  n = 0;
  if (!param[1])
    return (FAILURE);
  param[1] = my_strupcase(param[1]);
  while (ptr_color[n].str)
    {
      if (param[1] && !strcmp(param[1], ptr_color[n].str))
	{
	  spot->color = ptr_color[n].value;
	  return (SUCCESS);
	}
        n++;
    }
  param[1] = my_strlowcase(param[1]);
  set_spot_color(spot, param);
  return (SUCCESS);
}
