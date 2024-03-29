#include		<stdlib.h>
#include		<stdio.h>
#include		<string.h>
#include		"errors.h"
#include		"parser.h"
#include		"my.h"

static void		check_arg(t_spot *spot, char **tab)
{
  int			check;

  if (tab[0] && !strcmp(tab[0], "position"))
    check = set_spot_coords(spot, tab);
  else if (tab[0] && !strcmp(tab[0], "color"))
    check = define_color_spot(spot, tab);
  else if (tab[0] && strcmp(tab[0], "position") && strcmp(tab[0], "color"))
    {
      fprintf(stderr, ERROPT, tab[0]);
      exit(EXIT_FAILURE);
    }
  if (check == FAILURE)
    {
      fprintf(stderr, ERRSYN, tab[0]);
      exit(EXIT_FAILURE);
    }
}

void			check_spot(t_spot *spot, char **tab)
{
  int			i;
  char			**arg;

  i = 1;
  spot->next = NULL;
  while (tab[i])
    {
      arg = my_worldtab(tab[i], "=,");
      check_arg(spot, arg);
      xfree_tab(arg);
      i++;
    }
}
