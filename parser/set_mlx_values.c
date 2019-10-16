#include	<stdlib.h>
#include	"parser.h"
#include	"my.h"

void		set_mlx_values(t_mlx *mlx, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 3)
    {
      if (param[n])
	mlx->win_size[e] = atoi(param[n]);
      n++;
      e++;
    }
}
