#include	<stdlib.h>

#include       	"effects.h"

unsigned int	modif_color_with_effect(unsigned int obj_color,
					    unsigned int ref_color,
					    double effect)
{
  unsigned int 	red;
  unsigned int 	green;
  unsigned int 	blue;
  unsigned int 	new_color;

  red = ((obj_color / 256) / 256) * (1 - effect)
        + ((ref_color / 256) / 256) * effect;
  green = ((obj_color / 256) % 256) * (1 - effect)
          + ((ref_color / 256) % 256) * effect;
  blue = (obj_color % 256) * (1 - effect)
         + (ref_color % 256) * effect;
  new_color = 0;
  new_color |= (red << 16);
  new_color |= (green << 8);
  new_color |= blue;
  return (new_color);
}

unsigned int	modif_color_with_spot(unsigned int obj_color,
				      unsigned int spot_color,
				      double gloss, double cos_a)
{
  unsigned int 	red;
  unsigned int 	green;
  unsigned int 	blue;
  unsigned int 	new_color;

  red = ((obj_color / 256) / 256) * cos_a * (1 - gloss)
        + ((spot_color / 256) / 256) * cos_a * gloss;
  green = ((obj_color / 256) % 256) * cos_a * (1 - gloss)
          + ((spot_color / 256) % 256) * cos_a * gloss;
  blue = (obj_color % 256) * cos_a * (1 - gloss)
         + (spot_color % 256) * cos_a * gloss;
  new_color = 0;
  new_color |= (red << 16);
  new_color |= (green << 8);
  new_color |= blue;
  return (new_color);
}

unsigned int	color_addition(unsigned int *color, int spot_nbr)
{
  int	       	n;
  unsigned int 	red;
  unsigned int 	green;
  unsigned int 	blue;
  unsigned int 	new_color;

  n = 0;
  red = 0;
  green = 0;
  blue = 0;
  while (n < spot_nbr)
    {
      red += ((color[n] / 256) / 256);
      green += ((color[n] / 256) % 256);
      blue += (color[n++] % 256);
    }
  red = red / spot_nbr;
  green = green / spot_nbr;
  blue = blue / spot_nbr;
  new_color = 0;
  new_color |= (red << 16);
  new_color |= (green << 8);
  new_color |= blue;
  return (new_color);
}
