#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"main.h"
#include	"parser.h"

int	        is_valid_color(char *param)
{
  if (strlen(param) == 8)
    {
      if (!strncmp(param, "0x", 2))
	return (TRUE);
    }
  return (FALSE);
}

int		error_color(char *str)
{
  int		n;

  n = 0;
  while (str[n])
    {
      if (!IS_HEXA(str[n]))
	return (FALSE);
      n++;
    }
  return (TRUE);
}
