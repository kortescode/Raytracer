#include	"my.h"

char		*xcolor_change(char *str, char *color)
{
  if (!my_match_exp(color, "00"))
    {
      str = my_stradd(str, "m", 0);
      str = my_stradd(str, color, 0);
      str = my_stradd(str, "\033[", 0);
    }
  else
    {
      str = my_stradd("\033[", str, 0);
      str = my_stradd(color, str, 0);
      str = my_stradd("m", str, 0);
    }
  return (str);
}
