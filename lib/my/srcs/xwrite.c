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
