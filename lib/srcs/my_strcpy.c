/*
** xstrcpy.c for xmy in /home/tomase_n//lib
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sun Feb 13 19:47:50 2011 nikola tomasevic
** Last update Sun Jun  5 14:27:04 2011 henri hardillier
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}

char		*my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  if (!src[i] || i == n)
    dest[i] = 0;
  return (dest);
}
