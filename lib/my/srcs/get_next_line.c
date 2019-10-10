/*
** get_next_line.c for gnl in /home/schrey_i//local/work/project/lemin
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Tue Apr 19 11:55:51 2011 ithyvan schreys
** Last update Thu Jun  2 23:42:45 2011 henri hardillier
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

static char	*cpy_in_buff(char *tmp, char *buffer, int *pos, int *pos2)
{
  while (*pos2 != BUFF_SIZE && tmp[*pos] != '\n' && tmp[*pos])
    buffer[(*pos2)++] = tmp[(*pos)++];
  buffer[*pos2] = 0;
  if (tmp[*pos] == '\n')
    (*pos)++;
  if (tmp[*pos] == 0)
    *pos = 0;
  return (buffer);
}

char		*get_next_line(const int fd)
{
  static char	tmp[READ_SIZE + 1];
  char		*buffer;
  static int	pos = 0;
  int		pos2;
  static int	ret = 0;

  pos2 = 0;
  buffer = NULL;
  while (pos2 < BUFF_SIZE)
    {
      if (pos == 0)
	{
	  if ((ret = xread(fd, tmp, READ_SIZE)) <= 0)
	    return (NULL);
	  tmp[ret] = 0;
	}
      if (pos2 == 0)
	if ((buffer = xmalloc((BUFF_SIZE + 1) * sizeof(*buffer))) == NULL)
          return (NULL);
      buffer = cpy_in_buff(tmp, buffer, &pos, &pos2);
      if ((pos == 0 && ret != READ_SIZE) || (pos > 0 && tmp[pos - 1] == '\n')
	  || (pos == 0 && tmp[READ_SIZE - 1] == '\n'))
	return (buffer);
    }
  return (buffer);
}
