#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"errors.h"
#include        "parser.h"
#include        "my.h"

void		check_mlx(t_mlx *mlx, char **tab)
{
  int	       	i;
  char	       	**arg;

  i = 1;
  while (tab[i])
    {
      arg = my_worldtab(tab[i], "=,");
      check_is_num_mlx(arg);
      if (arg[0] && !strcmp(arg[0], "size"))
	set_mlx_values(mlx, arg);
      else if (arg[0] && strcmp(arg[0], "size"))
	{
	  fprintf(stderr, ERROPT, arg[0]);
	  exit(EXIT_FAILURE);
	}
      xfree_tab(arg);
      i++;
    }
}
