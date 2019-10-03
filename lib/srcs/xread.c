/*
** xread.c for lib in /home/hardil_h//lib
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Wed Apr 13 00:45:26 2011 henri hardillier
** Last update Thu Jun  2 23:42:45 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"my.h"

int		xread(int fd, void *str, int size)
{
  int		ret;

  if ((ret = read(fd, str, size)) == ERROR)
    {
      fprintf(stderr, "error : can't perform read().\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
