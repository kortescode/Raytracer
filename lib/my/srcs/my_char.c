/*
** xchar.c for xchar in /home/tomase_n//lib/my
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Wed Jan 12 14:52:04 2011 nikola tomasevic
** Last update Sun Jun  5 14:27:04 2011 henri hardillier
*/

#include	<unistd.h>
#include	"my.h"

int		my_char(int out, char c, int ret)
{
  int		w;

  w = xwrite(out, &c, 1);
  if (ret)
    w += xwrite(out, "\n", 1);
  return (w);
}
