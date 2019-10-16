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
