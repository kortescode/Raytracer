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
