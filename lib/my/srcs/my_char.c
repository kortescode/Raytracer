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
