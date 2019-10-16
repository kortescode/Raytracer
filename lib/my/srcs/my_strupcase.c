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
