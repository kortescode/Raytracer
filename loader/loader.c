/*
** draw.c for rtv1 in /home/ks13/School/libxmy/rtv1
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sat Mar 12 17:08:25 2011 nikola tomasevic
** Last update Sun Jun  5 15:49:33 2011 henri hardillier
*/

#include	<mlx.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"main.h"
#include	"loader.h"
#include	"effects.h"
#include	"my.h"

static void	put_pxl(t_img *img, int opos, int c)
{
  int		cpt;
  int		pos;
  int		bypp;

  bypp = img->bpp / (sizeof(char) * 8);
  cpt = 0;
  while (cpt < bypp)
    {
      if (img->end == 1)
        pos = cpt + (opos * bypp);
      else
        pos = (opos * bypp) + (bypp - 1) - cpt;
      img->lidata[pos] = ((c << (cpt * 8)) >> (img->bpp - 8));
      cpt++;
    }
}

static t_img	*new_img(void *mlx, int ww, int wh)
{
  t_img		*tmp;

  tmp = xmalloc(sizeof(*tmp));
  tmp->name = "loader";
  tmp->limg = xmlx_new_image(mlx, ww, wh);
  tmp->lidata = mlx_get_data_addr(tmp->limg, &IBPP, &ISL, &IEND);
  return (tmp);
}

static void	set_color(t_pars *pars, int j, int i, double *col)
{
  if (i < PMIDBAR)
    {
      col[0] = pars->col1.c[j];
      col[1] = pars->col2.c[j];
    }
  else
    {
      col[0] = pars->col2.c[j];
      col[1] = pars->col3.c[j];
    }
}

static int	xcolor_grad(t_pars *pars, int i)
{
  static	t_uic	colr;
  static	double	percent = INIT;
  double	col[2];
  double	len;
  double	part;
  int	j;

  if (percent == i)
    return (colr.i);
  percent = i;
  part = (i < PMIDBAR? 0 : PMIDBAR);
  len = PMIDBAR;
  j = 0;
  while (j < 4)
    {
      set_color(pars, j, i, col);
      colr.c[j] = (int)(col[0] + ((percent - part)
				  * ((col[1] - col[0]) / len)));
      j++;
    }
  return (colr.i);
}

void		*draw_load(void *mlx, t_pars *pars)
{
  int		i;
  static int   	j;
  int		beg;
  static t_img	*img = NULL;

  if (!img && !(img = new_img(mlx, PWIDTH, PHEIGHT)))
    return (NULL);
  beg = PPOSX + (PPOSY * PWIDTH);
  i = (i = CPER(PDONE, PBARLEN, PTOTDONE)) < j? i - 1 : j - 1;
  while (++i < PWIDTH)
    {
      j = INIT;
      while (++j < PHEIGHT)
	{
	  if (!IN(i, PBORDERLEFT, PBORDERRIGHT) || !IN(j, PBORDERUP, PBORDERDOWN))
	    put_pxl(img, beg + CP(i, j, PWIDTH), WHITE);
	  else if (i <= PTCHICK + CPER(PDONE, PBARLEN, PTOTDONE))
	    put_pxl(img, beg + CP(i, j, PWIDTH),
		    xcolor_grad(pars, i - PTCHICK));
	  else
	    put_pxl(img, beg + CP(i, j, PWIDTH), BLACK);
	}
    }
  j = CPER(PDONE, PBARLEN, PTOTDONE);
  return (img->limg);
}
