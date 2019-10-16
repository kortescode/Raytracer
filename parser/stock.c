#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"parser.h"
#include		"my.h"

int		stock_eye(t_rt *rt, char **tab)
{
  check_eye(&rt->eye, tab);
  return (SUCCESS);
}

int		stock_mlx(t_rt *rt, char **tab)
{
  check_mlx(&rt->mlx, tab);
  return (SUCCESS);
}

int		stock_spot(t_rt *rt, char **tab)
{
  t_spot	*spot;

  spot = xmalloc(sizeof(*spot));
  init_spot(spot);
  check_spot(spot, tab);
  spot->next = rt->spot;
  rt->spot = spot;
  return (SUCCESS);
}

int		stock_object(t_rt *rt, char **tab)
{
  t_obj		*obj;

  obj = xmalloc(sizeof(*obj));
  init_object(obj);
  check_object(obj, tab);
  obj->next = rt->obj;
  rt->obj = obj;
  return (SUCCESS);
}
