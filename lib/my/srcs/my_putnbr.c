#include	<stdlib.h>
#include	<string.h>

#include	"my.h"

int		my_putunbr(unsigned int nb)
{
  int		divider;
  int		cpt;

  cpt = 1;
  divider = 1;
  while (nb / divider >= 10)
    {
      divider = divider * 10;
      cpt++;
    }
  while (divider / 1 != 0)
    {
      my_char(1, 48 + (nb / divider), 0);
      nb = nb - (nb / divider) * divider;
      divider = divider / 10;
    }
  return (cpt);
}

int		my_putnbr(int nb)
{
  int		divider;
  int		cpt;
  int		keeper;

  cpt = 1;
  keeper = -1;
  divider = 1;
  if (nb < 0)
      cpt += my_char(1, '-', 0);
  if (nb > 0)
      nb *= keeper;
  while ((nb / divider) < -9)
      divider *= 10;
  while (divider / 1 != 0)
    {
      cpt += my_char(1, '0' + ((nb / divider) * keeper), 0);
      nb %= divider;
      divider = divider / 10;
    }
  return (cpt);
}

char		*my_bufnbr(int nb)
{
  char		*nbr;
  char		c[2];
  int		divider;
  int		cpt;
  int		keeper;

  cpt = 1;
  keeper = -1;
  divider = 1;
  nbr = NULL;
  c[1] = 0;
  if (nb < 0)
      cpt += my_char(1, '-', 0);
  if (nb > 0)
      nb *= keeper;
  while ((nb / divider) < -9)
      divider *= 10;
  while (divider / 1 != 0)
    {
      c[0] = '0' + ((nb / divider) * keeper);
      nbr = my_stradd(nbr, c, strlen(nbr));
      nb %= divider;
      divider = divider / 10;
    }
  return (nbr);
}
