/*
** my_getnbr_base.c for hh in /home/hardil_h//Desktop
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Feb 11 10:46:13 2011 henri hardillier
** Last update Wed Jun  1 16:19:07 2011 anthony joyeux
*/

#include	<string.h>

int		my_getnbr_base(char *str, char *base)
{
  unsigned int	n;
  int	pos;
  int	sign;
  int	nbr;

  nbr = 0;
  pos = 0;
  sign = 1;
  if (str[pos] == '-')
    {
      sign *= -1;
      pos++;
    }
  while (str[pos])
    {
      n = 0;
      while (base[n] != str[pos] && n <= strlen(base))
	n++;
      if (base[n] == str[pos])
	nbr = nbr * strlen(base) + n;
      else
	return (0);
      pos++;
    }
  return (nbr * sign);
}
