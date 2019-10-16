#include       	<stdlib.h>
#include       	"my.h"

void	       	xfree_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}
