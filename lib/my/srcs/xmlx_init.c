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
