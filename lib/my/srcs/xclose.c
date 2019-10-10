/*
** x_close.c for lib in /home/hardil_h//projets/corewar/lib
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Sun Mar 27 21:27:05 2011 henri hardillier
** Last update Thu Jun  2 15:01:35 2011 henri hardillier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"my.h"

void		xclose(int fd)
{
  if (close(fd) == ERROR)
    {
      fprintf(stderr, "error : can't perform close().\n");
      exit(EXIT_FAILURE);
    }
}
