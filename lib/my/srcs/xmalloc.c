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
