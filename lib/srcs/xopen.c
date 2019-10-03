/*
** xopen.c for lib in /home/hardil_h//lib
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Wed Apr 13 00:44:56 2011 henri hardillier
** Last update Thu Jun  2 23:42:45 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	"my.h"

int		xopen(const char *pathname, int flags, mode_t mode)
{
  int		fd;

  if ((fd = open(pathname, flags, mode)) == ERROR)
    {
      fprintf(stderr, "error : can't perform open().\n");
      exit(EXIT_FAILURE);
    }
  return (fd);
}
