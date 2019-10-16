#include	<unistd.h>
#include	"my.h"

void		my_char_repeat(int out, char c, int ret, int n)
{
  while (n > 0)
    {
      xwrite(out, &c, ret);
      n--;
    }
}
