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
