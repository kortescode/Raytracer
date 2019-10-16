#include	<string.h>

#include	"save.h"

char		*xload_get_word_col(int *len, double percent)
{
  static int	i = 0;
  int		j;
  char		*str;
  char		*part[5];

  part[0] = xcolor_it("Working on it : ", TORANGE, BBLACK, TDEF);
  part[1] = xcolor_it("% [", TBLUE, BBLACK, TDEF);
  part[2] = xcolor_it("]", TBLUE, BBLACK, TDEF);
  part[3] = xcolor_it(":X", TRED, BBLACK, TDEF);
  part[4] = xcolor_it(":D", TRED, BBLACK, TBLINK);
  if (i == 4)
    i = 0;
  if (i < 4)
    {
      if (i == 3 && percent == 100)
	j = i + 1;
      else
	j = i;
      str = part[j];
      *len = strlen(part[j]);
      i++;
    }
  return (str);
}

char		*xload_get_word_ncol(int *len, double percent)
{
  static int	i = 0;
  int		j;
  char		*str;
  char		*part[5];

  part[0] = "Working on it : ";
  part[1] = "% [";
  part[2] = "]";
  part[3] = ":X";
  part[4] = ":D";
  if (i == 4)
    i = 0;
  if (i < 4)
    {
      if (i == 3 && percent == 100)
	j = i + 1;
      else
	j = i;
      str = part[j];
      *len = strlen(part[j]);
      i++;
    }
  return (str);
}

char		*xload_get_word(int *len, double percent, int color)
{
  char		*tmp;

  if (color)
    tmp = xload_get_word_col(len, percent);
  else
    tmp = xload_get_word_ncol(len, percent);
  return (tmp);
}
