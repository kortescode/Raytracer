/*
** set_values.c for set_values in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Thu May 26 15:39:26 2011 anthony joyeux
** Last update Sat Jun  4 23:12:59 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"main.h"
#include	"errors.h"
#include	"parser.h"
#include	"my.h"

int		set_constant(t_obj *obj, char **param)
{
  if (param[1] && is_num(param[1]))
    {
      obj->constant = atof(param[1]);
      if (obj->constant < 0)
	{
	  fprintf(stderr, "%s%s%s%s", ERRCONSTANT, VALPOS, param[1], END);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRCONSTANT, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}

int		set_radius(t_obj *obj, char **param)
{
  if (param[1] && is_num(param[1]))
    {
      obj->radius = atof(param[1]);
      if (obj->radius < 0)
	{
	  fprintf(stderr, "%s%s%s%s", ERRRADIUS, VALPOS, param[1], END);
	  exit(EXIT_FAILURE);
	}
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRRADIUS, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}

int		set_rotation(t_obj *obj, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4)
    {
      if (param[n] && is_num(param[n]))
	obj->rotation[e] = atof(param[n]);
      else
	{
	  fprintf(stderr, "%s%s%s%s", ERRROTATE, CHAR, param[n], END);
	  exit(EXIT_FAILURE);
	}
      n++;
      e++;
    }
  return (SUCCESS);
}

int		set_position(t_obj *obj, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4)
    {
      if (param[n] && is_num(param[n]))
	obj->position[e] = atof(param[n]);
      else
	{
	  fprintf(stderr, "%s%s%s%s", ERRPOS, CHAR, param[n], END);
	  exit(EXIT_FAILURE);
	}
      n++;
      e++;
    }
  return (SUCCESS);
}

int		set_color(t_obj *obj, char **param)
{
  if (param[1] && is_valid_color(param[1]))
    {
      if (error_color(&(param[1][2])))
	obj->color = my_getnbr_base(my_strupcase(&(param[1][2])), HEX);
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRCOLOR, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
  return (SUCCESS);
}
