/*
** my_strlowcase.c for my_strlowcase in /home/joyeux_a//rtv42/hardil_h/raytracer/lib/srcs
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Thu Jun  2 15:54:27 2011 anthony joyeux
** Last update Thu Jun  2 15:54:38 2011 anthony joyeux
*/

#include	"my.h"

char		*my_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 65 && str[i] <= 90)
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
