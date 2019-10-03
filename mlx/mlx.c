/*
** init_mlx.c for rt in /home/hardil_h//Desktop/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Wed May 25 16:58:37 2011 henri hardillier
** Last update Sun Jun  5 23:29:13 2011 henri hardillier
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<signal.h>

#include	"main.h"
#include	"mlx_util.h"
#include	"my.h"

int		init_mlx(t_rt *rt)
{
  rt->mlx.mlx = xmlx_init();
  rt->mlx.win = xmlx_new_window(rt->mlx.mlx, rt->mlx.win_size[X],
			       rt->mlx.win_size[Y], "Raytracer");
  rt->mlx.img = xmlx_new_image(rt->mlx.mlx, rt->mlx.win_size[X],
			      rt->mlx.win_size[Y]);
  xsignal(SIGPIPE, SIG_IGN);
  return (SUCCESS);
}

void		fix_mlx(t_rt *rt)
{
  mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win, rt->mlx.img, 0, 0);
  mlx_key_hook(rt->mlx.win, gere_key, &rt->mlx);
  mlx_expose_hook(rt->mlx.win, gere_expose, &rt->mlx);
  mlx_loop(rt->mlx.mlx);
}
