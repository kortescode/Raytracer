/*
** rt_load.h for loader in /home/ks13/School/projs/mlx
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Fri Jun  3 02:23:15 2011 nikola tomasevic
** Last update Sun Jun  5 04:32:13 2011 nikola tomasevic
*/

#ifndef		LOADER_H_
# define       	LOADER_H_

#include	"main.h"

/*
** Sizes of loader
*/

#define		LW		500
#define		LH		50

/*
** Macros
*/
#define		WLOAD		rt->mlx.win_size[X] / 2 - LW / 2
#define		HLOAD		rt->mlx.win_size[Y] / 2 - LH / 2
#define		PWIDTH		pars->ww
#define		PHEIGHT		pars->wh
#define		PPOSX		pars->xbeg
#define		PPOSY		pars->ybeg
#define		PTCHICK		pars->t
#define		PDONE		pars->done
#define		PCOL1		pars->col1
#define		PCOL10		pars->col1.c[0]
#define		PCOL11		pars->col1.c[1]
#define		PCOL12		pars->col1.c[2]
#define		PCOL13		pars->col1.c[3]
#define		PCOL2		pars->col2
#define		PCOL20		pars->col2.c[0]
#define		PCOL21		pars->col2.c[1]
#define		PCOL22		pars->col2.c[2]
#define		PCOL23		pars->col2.c[3]
#define		PCOL3		pars->col3
#define		PCOL30		pars->col3.c[0]
#define		PCOL31		pars->col3.c[1]
#define		PCOL32		pars->col3.c[2]
#define		PCOL33		pars->col3.c[3]
#define		PBORDERLEFT	(PTCHICK)
#define		PBORDERRIGHT	(PWIDTH - PTCHICK)
#define		PBORDERUP	(PTCHICK)
#define		PBORDERDOWN	(PHEIGHT - PTCHICK)
#define		PTOTLEN		(PWIDTH * PHEIGHT)
#define		PBARLEN		(PWIDTH - (PTCHICK * 2))
#define		PMIDBAR		(PBARLEN / 2)
#define		PTOTDONE	pars->tot
#define		IBPP		tmp->bpp
#define		ISL		tmp->sl
#define		IEND		tmp->end

/*
** Parametrized macros
*/
#define		CX(x, len)	((x) % (len))
#define		CY(x, len)	((x) / (len))
#define		CP(x, y, len)	((x) + ((y) * (len)))
#define		CPER(x, len, tot) (((x) * (len)) / (tot))
#define		CPOS(x, o)	((x) * (o))
#define		IN(x, b, e)	((x) >= (b) && (x) <= (e)? 1 : 0)

/*
** Structures
*/

typedef	union	s_usc
{
  short	s;
  char	c[2];
}		t_usc;

typedef	union	u_uic
{
  int		i;
  unsigned	char	c[4];
}		t_uic;

typedef struct	s_img
{
  char		*name;
  void		*limg;
  char		*lidata;
  int		bpp;
  int		sl;
  int		end;
}		t_img;

typedef struct	s_pars
{
  int		ww;
  int		wh;
  int		xbeg;
  int		ybeg;
  int		done;
  int		tot;
  int		t;
  t_uic		col1;
  t_uic		col2;
  t_uic		col3;
}		t_pars;

/*
** Function prototypes
*/
void		*draw_load(void *mlx, t_pars *pars);

#endif		/* !LOADER_H_ */
