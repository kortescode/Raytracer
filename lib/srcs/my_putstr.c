/*
** my_putstr.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/lib/srcs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Sun Jun  5 14:57:00 2011 henri hardillier
** Last update Sun Jun  5 14:57:51 2011 henri hardillier
*/

#include	<string.h>
#include	"my.h"

void		my_putstr(char *str)
{
  xwrite(1, str, strlen(str));
}
