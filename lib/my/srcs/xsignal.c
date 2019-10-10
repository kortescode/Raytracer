/*
** xsignal.c for lib in /home/hardil_h//projets/minitalk/lib
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Sun Mar 20 20:22:24 2011 henri hardillier
** Last update Sun Jun  5 23:31:40 2011 henri hardillier
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<signal.h>
#include	"my.h"

sighandler_t	xsignal(int signum, sighandler_t handler)
{
  sighandler_t	error;

  if ((error = signal(signum, handler)) == SIG_ERR)
    {
      fprintf(stderr, "error : can't perform signal().\n");
      exit(EXIT_FAILURE);
    }
  return (error);
}
