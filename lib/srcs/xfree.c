/*
** free.c for free in /home/schrey_i//local/work/RT
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Tue May 17 16:09:58 2011 ithyvan schreys
** Last update Thu Jun  2 15:01:34 2011 henri hardillier
*/

#include       	<stdlib.h>
#include       	"my.h"

void	       	xfree_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
