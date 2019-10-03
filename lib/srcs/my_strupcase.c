/*
** my_strupcase.c for strupcase in /home/joyeux_a//lib/my
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Mon Oct 18 14:54:29 2010 anthony joyeux
** Last update Thu Jun  2 15:01:35 2011 henri hardillier
*/

char   	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] -= 'a' - 'A';
      i++;
    }
  return (str);
}
