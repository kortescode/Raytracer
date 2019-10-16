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
