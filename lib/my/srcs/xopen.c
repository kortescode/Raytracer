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
