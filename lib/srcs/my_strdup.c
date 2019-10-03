/*
** xstrdup.c for xmy in /home/tomase_n//lib
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sun Feb 13 19:47:39 2011 nikola tomasevic
** Last update Sun Jun  5 14:27:04 2011 henri hardillier
*/

#include	"my.h"

char		*my_strdup(char *src)
{
  char	*tmp;
  int	i;

  i = 0;
  while (src[i])
    i++;
  tmp = xmalloc(sizeof(*tmp) * (i + 1));
  my_strcpy(tmp, src);
  return (tmp);
}
