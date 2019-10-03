/*
** stock.c for stock in /home/schrey_i//local/work/RT
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Tue May 17 15:51:27 2011 ithyvan schreys
** Last update Tue Jun  7 00:48:15 2011 henri hardillier
*/

#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"errors.h"
#include		"parser.h"
#include		"my.h"

t_conf			ptr_conf[] =
  {
    {"EYE", stock_eye},
    {"SPOT", stock_spot},
    {"WINDOW", stock_mlx},
    {"SPHERE", stock_object},
    {"CONE", stock_object},
    {"CYLINDER", stock_object},
    {"PLAN", stock_object},
    {"PARABOLOID", stock_object},
    {"HYPERBOLOID", stock_object},
    {NULL, NULL},
  };

static void	check_struct(t_rt *rt, char **tab)
{
  int		n;
  int		check;

  n = 0;
  check = FAILURE;
  while (ptr_conf[n].str)
    {
      if (tab[0] && !strcmp(tab[0], ptr_conf[n].str))
	check = ptr_conf[n].func(rt, tab);
      n++;
    }
  if (tab[0] && check == FAILURE)
    {
      fprintf(stderr, ERRTYPE, tab[0]);
      exit(EXIT_FAILURE);
    }
}

int		get_config(t_rt *rt, char **av)
{
  char		*str;
  char		**tab;
  int		fd;

  init_rt(rt);
  fd = xopen(av[1], O_RDONLY, S_IRWXU);
  while ((str = get_next_line(fd)))
    {
      tab = my_worldtab(str, " |");
      if (tab[0] && tab[0][0] != '#')
	check_struct(rt, tab);
      if (str)
	free(str);
      free(tab);
    }
  xclose(fd);
  if (!rt->obj)
    {
      fprintf(stderr, ERRNOOBJ);
      return (FAILURE);
    }
  return (SUCCESS);
}
