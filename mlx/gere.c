#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<mlx.h>

#include	"main.h"
#include	"mlx_util.h"
#include	"loader.h"
#include	"save.h"
#include	"my.h"

int     	gere_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
  return (SUCCESS);
}

int     	gere_key(int keycode, t_mlx *mlx)
{
  char		*file;

  if (keycode == KS && mlx->mlx)
    {
      my_putstr("\033[33mPlease type in where you ");
      my_putstr("want to save the image to :\n\033[0m");
      while (!(file = get_next_line(0)) || !strlen(file))
	fprintf(stderr, "%s%s%s", "\033[33merror : the name must have at ", \
		"least one character !\nPlease enter a ", \
		"valid file name :\n\033[0m");
      save_img(mlx->img, mlx->win_size[X], mlx->win_size[Y], file);
    }
  if (keycode == ESC && mlx->mlx)
    {
      /*mlx_destroy_image(mlx->mlx, mlx->img);
      mlx_destroy_image(mlx->mlx, mlx->img_load);*/
      mlx_destroy_window(mlx->mlx, mlx->win);
      my_putstr("\033[34mThank you for having used our Raytracer\n");
      my_putstr("See You Again :)\n\033[0m");
      exit(EXIT_SUCCESS);
    }
  return (SUCCESS);
}
