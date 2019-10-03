/*
** fill_image.c for rt in /home/hardil_h//Desktop/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Wed May 25 17:13:53 2011 henri hardillier
** Last update Sun Jun  5 15:46:55 2011 henri hardillier
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		<mlx.h>

#include		"main.h"
#include		"mlx_util.h"
#include		"movements.h"
#include		"inter.h"
#include		"effects.h"
#include		"loader.h"

static void		init_coords(t_rt *rt, int x, int y)
{
  rt->eye.eye[X] = 0.0;
  rt->eye.eye[Y] = 0.0;
  rt->eye.eye[Z] = 0.0;
  rt->eye.point[X] = (double)DIST;
  rt->eye.point[Y] = ((double)rt->mlx.win_size[X] / 2.0) - (double)x;
  rt->eye.point[Z] = ((double)rt->mlx.win_size[Y] / 2.0) - (double)y;
  rt->eye.vector[X] = rt->eye.point[X] - rt->eye.eye[X];
  rt->eye.vector[Y] = rt->eye.point[Y] - rt->eye.eye[Y];
  rt->eye.vector[Z] = rt->eye.point[Z] - rt->eye.eye[Z];
  translate(rt->eye.eye, rt->eye.position[X],
	    rt->eye.position[Y], rt->eye.position[Z]);
  rotate(rt->eye.eye, rt->eye.rotation[X],
	 rt->eye.rotation[Y], rt->eye.rotation[Z]);
}

static void		init_loader(t_rt *rt, t_pars *pars)
{
  pars->ww = LW;
  pars->wh = LH;
  pars->xbeg = 0;
  pars->ybeg = 0;
  pars->col1.i = RED;
  pars->col2.i = YELLOW;
  pars->col3.i = LIME;
  pars->t = 4;
  pars->tot = rt->mlx.win_size[X] * rt->mlx.win_size[Y];
  pars->done = 0;
}

static unsigned int    	calculs(t_rt *rt, int x, int y)
{
  init_coords(rt, x, y);
  inter_calculs(rt);
  return (get_color(rt));
}

void			fill_image(t_rt *rt)
{
  int			x;
  int			y;
  t_pars		pars;
  unsigned int		color;

  y = INIT;
  init_loader(rt, &pars);
  while (++y <= rt->mlx.win_size[Y])
    {
      x = INIT;
      while (++x <= rt->mlx.win_size[X])
	{
	  color = mlx_get_color_value(rt->mlx.mlx, calculs(rt, x, y));
	  pixel_put_to_image(rt->mlx.img, x, y, color);
	  ++pars.done;
	}
      if ((rt->mlx.img_load = draw_load(rt->mlx.mlx, &pars)))
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win,
				rt->mlx.img_load, WLOAD, HLOAD);
    }
}
