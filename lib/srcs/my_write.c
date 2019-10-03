/*
** xwrite.c for xwrite in /home/tomase_n//lib/my
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Wed Jan 12 14:02:22 2011 nikola tomasevic
** Last update Sun Jun  5 14:36:36 2011 henri hardillier
*/

#include	<unistd.h>
#include	"my.h"

int		my_write(int out, char *str, int ret)
{
  int		i;
  int		w;

  i = 0;
  while (str[i])
    i++;
  w = xwrite(out, str, i);
  if (ret)
    w += xwrite(out, "\n", 1);
  return (w);
}
