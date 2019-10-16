#include	"save.h"
#include	"my.h"

int		xload_fill_bar_col(int blen, double percent)
{
  int		j;

  j = 0;
  while (j + (percent < 100? 2 : 1) < (percent * (blen / 100.0)))
    {
      my_write(1, xcolor_it(LOADFILL, TGREEN, BBLACK, TDEF), 0);
      j++;
    }
  my_write(1, xcolor_it(LOADPONCT, TSPLEEN, BBLACK, TDEF), 0);
  if (percent < 100.0)
    {
      my_write(1, xcolor_it(LOADWALL, TRED, BBLACK, TDEF), 0);
      j += 2;
    }
  else
    j++;
  while (j < blen)
    {
      my_write(1, xcolor_it(LOADEMPTY, TORANGE, BBLACK, TDEF), 0);
      j++;
    }
  return (blen);
}

int		xload_fill_bar_ncol(int blen, double percent)
{
  int		j;

  j = 0;
  while (j + (percent < 100? 2 : 1) < (percent * (blen / 100.0)))
    {
      my_write(1, LOADFILL, 0);
      j++;
    }
  my_write(1, LOADPONCT, 0);
  if (percent < 100.0)
    {
      my_write(1, LOADWALL, 0);
      j += 2;
    }
  else
    j++;
  while (j < blen)
    {
      my_write(1, LOADEMPTY, 0);
      j++;
    }
  return (blen);
}

int		xload_fill_bar(int blen, double percent, int color)
{
  int		tmp;

  if (color)
    tmp = xload_fill_bar_col(blen, percent);
  else
    tmp = xload_fill_bar_ncol(blen, percent);
  return (tmp);
}
