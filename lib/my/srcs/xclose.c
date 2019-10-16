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
