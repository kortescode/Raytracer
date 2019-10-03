/*
** xmlx_new_image.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/lib/srcs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Jun  3 19:17:49 2011 henri hardillier
** Last update Fri Jun  3 19:21:17 2011 henri hardillier
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>

void		*xmlx_new_image(void *mlx, int x, int y)
{
  void		*img;

  if (!(img = mlx_new_image(mlx, x, y)))
    {
      fprintf(stderr, "error : mlx_new_image failed.\n");
      exit(EXIT_FAILURE);
    }
  return (img);
}
