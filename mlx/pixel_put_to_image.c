#include	<mlx.h>

#include	"main.h"

void    	pixel_put_to_image(void *img, int x, int y,
				   unsigned int color)
{
  static int   	pos;
  static int   	bpp;
  static int   	sizeline;
  static int   	endian;
  static char  	*data;
  unsigned int	red;
  unsigned int	green;
  unsigned int	blue;

  pos = 0;
  if (x == 0 && y == 0)
    data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
  red = (color / 256) / 256;
  green = (color / 256) % 256;
  blue = color % 256;
  data[x * (bpp / 8) + y * sizeline + pos++] = blue;
  data[x * (bpp / 8) + y * sizeline + pos++] = green;
  data[x * (bpp / 8) + y * sizeline + pos++] = red;
  data[x * (bpp / 8) + y * sizeline + pos] = 0;
}
