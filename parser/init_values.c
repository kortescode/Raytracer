#include	<stdlib.h>
#include	"main.h"
#include	"parser.h"

void		init_rt(t_rt *rt)
{
  init_eye(&rt->eye);
  init_mlx_values(&rt->mlx);
  rt->obj = NULL;
  rt->spot = NULL;
}

void		init_object(t_obj *obj)
{
  int		n;

  n = 0;
  obj->color = 0xFFFFFF;
  while (n <= 2)
    {
      obj->position[n] = 0;
      obj->rotation[n++] = 0;
    }
  obj->radius = 0;
  obj->constant = 0;
  obj->gloss = 0;
  obj->transparency = 0;
  obj->reflection = 0;
  obj->index = 1;
  obj->k = 0;
  obj->next = NULL;
  init_limit(obj);
}

void		init_spot(t_spot *spot)
{
  spot->color = 0xFFFFFF;
}

void		init_mlx_values(t_mlx *mlx)
{
  mlx->win_size[X] = 800;
  mlx->win_size[Y] = 600;
}

void		init_eye(t_eye *eye)
{
  eye->position[X] = -300;
  eye->position[Y] = 0;
  eye->position[Z] = 50;
  eye->rotation[X] = 0;
  eye->rotation[Y] = 0;
  eye->rotation[Z] = 0;
}
