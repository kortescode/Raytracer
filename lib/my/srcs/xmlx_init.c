/*
** xmlx_init.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/lib/srcs
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Jun  3 19:12:45 2011 henri hardillier
** Last update Fri Jun  3 19:23:45 2011 henri hardillier
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>

void		*xmlx_init(void)
{
  void		*mlx;

  if (!(mlx = mlx_init()))
    {
      fprintf(stderr, "error : mlx_init failed.\n");
      exit(EXIT_FAILURE);
    }
  return (mlx);
}
