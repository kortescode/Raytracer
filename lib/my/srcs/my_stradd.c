/*
** xstradd.c for xmy in /home/ks13/School/libxmy/libstr
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sat Mar 26 17:11:57 2011 nikola tomasevic
** Last update Sun Jun  5 17:26:05 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

char		*my_stradd(char *str, char *add, int n)
{
  char		*tmp;
  int		slen;
  int		alen;
  int		totlen;

  if (str == NULL)
    str = "";
  else if (add == NULL)
    add = "";
  n = n < 0? 0 : n;
  alen = strlen(add);
  slen = strlen(str);
  if (!(totlen = slen + alen))
    return ("");
  tmp = xmalloc(totlen);
  if (n > totlen)
    return (my_strncpy(tmp, str, slen));
  my_strncpy(tmp, n == 0? add : str, n == 0? alen : n);
  my_strncpy(&(tmp[n == 0? alen : n]), n == 0? str : add, n == 0? slen : alen);
  my_strncpy(&(tmp[n == 0? slen + alen : n + alen]), \
	     n == 0? "\0" : &(str[n]), n == 0? 0 : slen - n);
  return (tmp);
}

char		*my_strnadd(char *str, char *add, int size, int n)
{
  char		*tmp;
  int		slen;
  int		alen;
  int		totlen;

  if (str == NULL)
    str = "";
  else if (add == NULL)
  add = "";
  n = n < 0? 0 : n;
  size = size < 0? 0 : size;
  alen = strlen(add);
  slen = strlen(str);
  if (!(totlen = slen + alen))
    return ("");
  tmp = my_strdup(str);
  if (n < size)
    {
      my_strncpy(str, tmp, n > slen? slen : n);
      my_strncpy(&(str[n]), add, alen + n > size? size - n : alen);
      my_strncpy(&(str[n + alen]), &(tmp[n]), alen + slen > size? \
	       size - n - alen : size - n);
    }
  free(tmp);
  return (str);
}
