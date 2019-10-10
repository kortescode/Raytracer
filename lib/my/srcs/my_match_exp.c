/*
** xmatch_exp.c for xmy in /home/tomase_n//libxmy
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sat May 28 16:55:36 2011 nikola tomasevic
** Last update Sun Jun  5 14:33:14 2011 henri hardillier
*/

int		my_match_exp(char *exp1, char *exp2)
{
  int		i;

  i = 0;
  while (exp1[i] && exp2[i] && exp1[i] == exp2[i])
      i++;
  if (exp1[i] != exp2[i])
    return (0);
  return (1);
}
