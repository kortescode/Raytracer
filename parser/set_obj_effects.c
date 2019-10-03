/*
** set_obj_effects.c for rt in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Wed Jun  1 10:58:23 2011 anthony joyeux
** Last update Sun Jun  5 23:21:29 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"inter.h"
#include	"errors.h"
#include	"parser.h"
#include	"my.h"

t_parseindex		ptr_index[] =
  {
    {"EMPTY", 1.0},
    {"ICE", 1.309},
    {"ALCOHOL", 1.329},
    {"CRYSTAL", 1.329},
    {"WATER", 1.33},
    {"PYREX", 1.470},
    {"GLASS", 1.5},
    {"AGATE", 1.544},
    {"QUARTZ", 1.544},
    {"EMERALD", 1.576},
    {"RUBY", 1.760},
    {"SAPPHIRE", 1.760},
    {"DIAMOND", 2.417},
    {NULL, NOTHING},
  };

int		set_transparency(t_obj *obj, char **param)
{
  if (param[1] && is_num_mlx(param[1]))
    {
      obj->transparency = atof(param[1]);
      if (obj->transparency < 0 || obj->transparency > 1)
	{
	  fprintf(stderr, "%s%s%s%s", ERRTRANS, VALBET, param[1], END);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRTRANS, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}

int		set_gloss(t_obj *obj, char **param)
{
  if (param[1] && is_num_mlx(param[1]))
    {
      obj->gloss = atof(param[1]);
      if (obj->gloss < 0 || obj->gloss > 1)
	{
	  fprintf(stderr, "%s%s%s%s", ERRGLOSS, VALBET, param[1], END);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRGLOSS, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}

int		set_reflection(t_obj *obj, char **param)
{
  if (param[1] && is_num_mlx(param[1]))
    {
      obj->reflection = atof(param[1]);
      if (obj->reflection < 0 || obj->reflection > 1)
	{
	  fprintf(stderr, "%s%s%s%s", ERRREFLECT, VALBET, param[1], END);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRREFLECT, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}

int		set_index(t_obj *obj, char **param)
{
  int		n;

  n = INIT;
  if (!param[1])
    return (FAILURE);
  param[1] = my_strupcase(param[1]);
  while (ptr_index[++n].str)
    if (param[1] && !strcmp(param[1], ptr_index[n].str))
      {
	obj->index = ptr_index[n].value;
	return (SUCCESS);
      }
  if (param[1] && is_num_mlx(param[1]) && (obj->index = atof(param[1])) < 0)
    {
      fprintf(stderr, "%s%s%s%s", ERRINDEX, VALPOS, param[1], END);
      exit(EXIT_FAILURE);
    }
  else if (!param[1] || !is_num_mlx(param[1]))
    {
      fprintf(stderr, "%s%s%s%s", ERRINDEX, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}
