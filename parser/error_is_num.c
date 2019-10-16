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
