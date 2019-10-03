/*
** stock.c for stock in /home/schrey_i//local/work/RT/rtv42/scenes
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Thu May 26 15:48:52 2011 ithyvan schreys
** Last update Sat Jun  4 19:17:33 2011 henri hardillier
*/

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
