/*
** xload_percent.c for xmy in /home/ks13/School/libxmy
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Tue Mar 29 01:48:25 2011 nikola tomasevic
** Last update Mon Jun  6 18:49:23 2011 henri hardillier
*/

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

