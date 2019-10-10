/*
** xchar_repeat.c for xmy in /home/tomase_n//lib
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sun Feb 13 19:35:56 2011 nikola tomasevic
** Last update Sun Jun  5 14:27:04 2011 henri hardillier
*/

#include	<unistd.h>
#include	"my.h"

void		my_char_repeat(int out, char c, int ret, int n)
{
  while (n > 0)
    {
      xwrite(out, &c, ret);
      n--;
    }
}
