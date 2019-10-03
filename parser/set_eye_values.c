/*
** set_eye_values.c for RT in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Thu May 26 16:47:21 2011 anthony joyeux
** Last update Sun Jun  5 23:14:10 2011 henri hardillier
*/

#include	<stdlib.h>
#include	"parser.h"

int		set_eye_rotation(t_eye *eye, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4 && param[n])
    {
      if (param[n])
	eye->rotation[e] = atof(param[n]);
      n++;
      e++;
    }
  return (SUCCESS);
}

int		set_eye_position(t_eye *eye, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4 && param[n])
    {
      if (param[n])
	eye->position[e] = atof(param[n]);
      n++;
      e++;
    }
  return (SUCCESS);
}
