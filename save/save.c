/*
** save.c for raytracer in /home/tomase_n//RT/rtv42/hardil_h/raytracer
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sun Jun  5 04:20:50 2011 nikola tomasevic
** Last update Sun Jun  5 16:17:35 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<mlx.h>

#include	"loader.h"
#include	"my.h"
#include	"save.h"

static void	write_int_to_fd(int fd, int nbr)
{
  int		i;
  t_uic		n;
  unsigned char	c;

  i = -1;
  n.i = nbr;
  while (++i < 4)
    {
      c = n.c[i];
      xwrite(fd, &c, 1);
    }
}

static void	write_short_to_fd(int fd, short nbr)
{
  int		i;
  t_usc		n;
  unsigned char	c;

  i = -1;
  n.s = nbr;
  while (++i < 2)
    {
      c = n.c[i];
      xwrite(fd, &c, 1);
    }
}

static void    	write_img(int fd, char *data, int x, int y)
{
  int		i;
  int		*ptr;
  int		n;
  double	percent;

  i = x * y;
  ptr = (int*)data;
  while (--i >= 0)
    {
      percent = ((((x * y) - i) * 100) / (x * y));
      (void)percent;
      n = ptr[CP(x - CX(i, x), CY(i, x), x)];
      write_int_to_fd(fd, n);
    }
}

static int     	write_file_header(int fd, int x, int y)
{
  xwrite(fd, "BM", 2);
  write_int_to_fd(fd, ((x * y) * 4) + 14 + 40);
  write_int_to_fd(fd, 0);
  write_int_to_fd(fd, 54);
  write_int_to_fd(fd, 40);
  write_int_to_fd(fd, x);
  write_int_to_fd(fd, y);
  write_short_to_fd(fd, 1);
  write_short_to_fd(fd, 32);
  write_int_to_fd(fd, 0);
  write_int_to_fd(fd, ((x * y) * 4));
  write_int_to_fd(fd, 2048);
  write_int_to_fd(fd, 2048);
  write_int_to_fd(fd, 32);
  write_int_to_fd(fd, 0);
  return (EXIT_SUCCESS);
}

void		save_img(void *img, int x, int y, char *file)
{
  int		fd;
  char		*data;
  int		pars[3];

  if ((fd = xopen(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRWXG)) >= 0)
    {
      data = mlx_get_data_addr(img, &(pars[0]), &(pars[1]), &(pars[2]));
      my_putstr("\033[32mWriting Header...\n\033[0m");
      write_file_header(fd, x, y);
      my_putstr("\033[32mWriting Pixels...\n\033[0m");
      write_img(fd, data, x, y);
      my_putstr("\033[32mImage Saven in file \033[36m\"");
      my_putstr(file);
      my_putstr("\"\n\033[0m");
      xclose(fd);
    }
}
