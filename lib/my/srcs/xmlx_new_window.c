/*
** xmlx_new_window.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/lib/srcs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Jun  3 19:15:20 2011 henri hardillier
** Last update Fri Jun  3 19:21:16 2011 henri hardillier
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>

void		*xmlx_new_window(void *mlx, int x, int y, char *name)
{
  void		*win;

  if (!(win = mlx_new_window(mlx, x, y, name)))
    {
      fprintf(stderr, "error : mlx_new_window failed.\n");
      exit(EXIT_FAILURE);
    }
  return (win);
}
