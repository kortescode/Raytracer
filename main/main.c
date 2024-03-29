#include	<stdlib.h>
#include	<stdio.h>
#include	<mlx.h>

#include	"main.h"
#include	"parser.h"
#include	"mlx_util.h"
#include	"errors.h"
#include	"my.h"

static int	raytracing(char **av)
{
  t_rt		rt;

  if (!get_config(&rt, av))
    return (FAILURE);
  if (!init_mlx(&rt))
    return (FAILURE);
  my_putstr("\033[34mRAYTRACER\n\033[31mWelcome to our raytracer !\n");
  my_putstr("[S] to save the image.\n");
  my_putstr("[ESC] to quit.\n\033[0m");
  fill_image(&rt);
  fix_mlx(&rt);
  return (SUCCESS);
}

int		main(int ac, char **av)
{
  if (ac == 1)
    {
      fprintf(stderr, ERRUSAGE, av[0]);
      return (EXIT_FAILURE);
    }
  if (!raytracing(av))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
