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
