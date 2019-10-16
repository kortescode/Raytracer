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
