/*
** error_mlx_spot.c for error in /home/schrey_i//local/work/RT/rtv42/scenes
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Tue May 31 17:46:55 2011 ithyvan schreys
** Last update Sat Jun  4 23:12:11 2011 henri hardillier
*/

#include       	<stdlib.h>
#include       	<stdio.h>
#include       	<string.h>
#include       	"errors.h"
#include       	"parser.h"

int	       	is_num_mlx(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
	return (FALSE);
      i++;
    }
  return (TRUE);
}

int	       	is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] != '-' && (str[i] < '0' || str[i] > '9') && str[i] != '.')
	return (FALSE);
      i++;
    }
  return (TRUE);
}

void	       	check_is_num(char **tab)
{
  int	       	i;

  i = 1;
  while (tab[i])
    {
      if (!is_num(tab[i]))
	{
	  fprintf(stderr, "%s%s%s%s", ERRNUM, CHAR, tab[i], END);
	  exit(EXIT_FAILURE);
	}
      i++;
    }
}

void	       	check_is_num_mlx(char **tab)
{
  int	       	i;

  i = 1;
  while (tab[i])
    {
      if (!is_num_mlx(tab[i]))
	{
	  fprintf(stderr, "%s%s%s%s", ERRNUM, CHAR, tab[i], END);
	  exit(EXIT_FAILURE);
	}
      i++;
    }
}
