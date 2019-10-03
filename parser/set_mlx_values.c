/*
** set_mlx_values.c for set_mlx_values in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Thu May 26 16:42:31 2011 anthony joyeux
** Last update Thu Jun  2 23:35:28 2011 henri hardillier
*/

#include	<stdlib.h>
#include	"parser.h"
#include	"my.h"

void		set_mlx_values(t_mlx *mlx, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 3)
    {
      if (param[n])
	mlx->win_size[e] = atoi(param[n]);
      n++;
      e++;
    }
}
