/*
** error.c for corewar in /home/hardil_h//projets/corewar/lib
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri Jan 28 09:10:08 2011 henri hardillier
** Last update Sun Jun  5 23:31:22 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"my.h"

void		*xmalloc(int size)
{
  void		*str;

  if (!(str = malloc(size)) && size != 0)
    {
      fprintf(stderr, "error : can't perform malloc().\n");
      exit(EXIT_FAILURE);
    }
  return (str);
}
