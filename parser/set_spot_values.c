/*
** set_spot_values.c for RT in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Thu May 26 16:59:44 2011 anthony joyeux
** Last update Sun Jun  5 10:09:54 2011 henri hardillier
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"errors.h"
#include	"parser.h"
#include	"my.h"

void		set_spot_color(t_spot *spot, char **param)
{
  if (param[1] && is_valid_color(param[1]))
    {
      if (error_color(&(param[1][2])))
	spot->color = my_getnbr_base(my_strupcase(&(param[1][2])), HEX);
    }
  else
    {
      fprintf(stderr, "%s%s%s%s", ERRCOLOR, CHAR, param[1], END);
      exit(EXIT_FAILURE);
    }
}

int		set_spot_coords(t_spot *spot, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4)
    {
      if (param[n] && is_num(param[n]))
	spot->position[e] = atof(param[n]);
      else
	{
	  fprintf(stderr, "%s%s%s%s", ERRCOORD, CHAR, param[1], END);
	  exit(EXIT_FAILURE);
	}
      n++;
      e++;
    }
  return (SUCCESS);
}
