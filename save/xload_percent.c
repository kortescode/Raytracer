#include	"save.h"
#include	"my.h"

int		xload_percent(int blen, double percent, int color)
{
  int		len;
  static int	total = 0;

  my_char(1, '\r', 0);
  my_char_repeat(1, 127, 0, total);
  total = 0;
  total += my_write(1, xload_get_word(&len, percent, color), 0);
  total += my_putnbr((int)percent);
  total += my_write(1, xload_get_word(&len, percent, color), 0);
  total += xload_fill_bar(blen, percent, color);
  total += my_write(1, xload_get_word(&len, percent, color), 0);
  total += my_write(1, xload_get_word(&len, percent, color), 0);
  return (0);
}

