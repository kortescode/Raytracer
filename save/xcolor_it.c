#include	"save.h"

char		*xcolor_it(char *str, char *txt, char *bg, char *eff)
{
  str = xcolor_change(str, txt);
  str = xcolor_change(str, bg);
  str = xcolor_change(str, eff);
  str = xcolor_change(str, "00");
  return (str);
}
