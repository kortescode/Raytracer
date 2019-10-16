#include	<stdlib.h>
#include	"parser.h"

int		set_eye_rotation(t_eye *eye, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4 && param[n])
    {
      if (param[n])
	eye->rotation[e] = atof(param[n]);
      n++;
      e++;
    }
  return (SUCCESS);
}

int		set_eye_position(t_eye *eye, char **param)
{
  int		n;
  int		e;

  e = 0;
  n = 1;
  while (n != 4 && param[n])
    {
      if (param[n])
	eye->position[e] = atof(param[n]);
      n++;
      e++;
    }
  return (SUCCESS);
}
