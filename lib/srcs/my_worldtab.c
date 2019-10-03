/*
** my_universtab.c for universal in /home/schrey_i//local/work/tp/unix/minishell
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Mon Feb 21 13:28:43 2011 ithyvan schreys
** Last update Sun Jun  5 14:47:00 2011 henri hardillier
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	"my.h"

static	int	test_car(char c, char *del)
{
  int	i;

  i = 0;
  while (del[i])
    {
      if (del[i] == c )
	return (-1);
      i++;
    }
  return (0);
}

static	int	nb_world(char *str, char *del)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] && test_car(str[i], del) == 0)
	{
	  while (str[i] && test_car(str[i], del) == 0)
	    i++;
	  nb++;
	}
     if (str[i])
	i++;
    }
  return (nb);
}

static	int	nb_w_letter(char *str, char *del)
{
  int	i;

  i = 0;
  while (str[i] && test_car(str[i], del) == 0)
    i++;
  return (i);
}

static	char	**loop(char **tab, char *str, char *del)
{
  int	i;
  int	e;
  int	j;

  i = 0;
  e = 0;
  while (str[i])
    {
      j = 0;
      if (str[i] && test_car(str[i], del) == 0)
	{
	  while (str[i] && str[i] == ' ')
	    i++;
	  tab[e] = malloc((nb_w_letter(str + i, del) + 1) * sizeof(**tab));
	  while (str[i] && test_car(str[i], del) == 0)
	    tab[e][j++] = str[i++];
	  tab[e][j] = '\0';
	  e++;
	}
      if (str[i])
	i++;
    }
  tab[e] = NULL;
  return (tab);
}

char		**my_worldtab(char *str, char *del)
{
  char		**tab;

  if (str == NULL)
    return (NULL);
  tab = xmalloc((nb_world(str, del) + 1) * sizeof(*tab));
  return (loop(tab, str, del));
}
