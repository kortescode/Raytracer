/*
** xcolor_it.c for xmy in /home/ks13/School/libxmy
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Tue Mar 29 02:46:22 2011 nikola tomasevic
** Last update Sun Jun  5 14:08:07 2011 henri hardillier
*/

#include	"save.h"

char		*xcolor_it(char *str, char *txt, char *bg, char *eff)
{
  str = xcolor_change(str, txt);
  str = xcolor_change(str, bg);
  str = xcolor_change(str, eff);
  str = xcolor_change(str, "00");
  return (str);
}
