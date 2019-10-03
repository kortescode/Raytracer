/*
** error_object.c for error_object in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Tue May 31 17:53:48 2011 anthony joyeux
** Last update Sat Jun  4 22:46:29 2011 henri hardillier
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"main.h"
#include	"parser.h"

int	        is_valid_color(char *param)
{
  if (strlen(param) == 8)
    {
      if (!strncmp(param, "0x", 2))
	return (TRUE);
    }
  return (FALSE);
}

int		error_color(char *str)
{
  int		n;

  n = 0;
  while (str[n])
    {
      if (!IS_HEXA(str[n]))
	return (FALSE);
      n++;
    }
  return (TRUE);
}
