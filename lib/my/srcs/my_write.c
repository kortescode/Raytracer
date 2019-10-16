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
