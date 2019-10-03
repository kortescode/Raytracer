/*
** xwrite.c for lib in /home/hardil_h//my/lib/x
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Tue Apr 12 23:30:27 2011 henri hardillier
** Last update Sun Jun  5 14:35:09 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"my.h"

int		xwrite(int fd, void *str, int size)
{
  int		ret;

  if ((ret = write(fd, str, size)) == ERROR)
    {
      fprintf(stderr, "error : can't perform write().\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
