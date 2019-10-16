#include		<mlx.h>
#include		<math.h>
#include		<stdlib.h>

#include		"main.h"
#include		"effects.h"
#include		"my.h"

static int		nbr_spot(t_rt *rt)
{
  int			count;
  t_spot		*spot;

  count = 0;
  spot = rt->spot;
  while (spot)
    {
      ++count;
      spot = spot->next;
    }
  return (count);
}

static void		cos_a_calcul(t_lumin *lumin, t_obj *obj, t_spot *spot)
{
  lumin->vector_l[X] = spot->position[X] - obj->point[X];
  lumin->vector_l[Y] = spot->position[Y] - obj->point[Y];
  lumin->vector_l[Z] = spot->position[Z] - obj->point[Z];
  lumin->normal_l = sqrt(SQR(lumin->vector_l[X]) + SQR(lumin->vector_l[Y])
			+ SQR(lumin->vector_l[Z]));
  lumin->normal_n = sqrt(SQR(obj->vector[X]) + SQR(obj->vector[Y])
			+ SQR(obj->vector[Z]));
  lumin->cos_a = ((lumin->vector_l[X] * obj->vector[X])
		 + (lumin->vector_l[Y] * obj->vector[Y])
		 + (lumin->vector_l[Z] * obj->vector[Z]))
    / (lumin->normal_l * lumin->normal_n);
  if (lumin->cos_a < 0)
    lumin->cos_a = 0;
}

unsigned int		luminosity(t_rt *rt, t_obj *obj)
{
  int			n;
  int			spot_nbr;
  t_lumin		lumin;
  t_spot		*spot;
  unsigned int		color;
  unsigned int		*color_tab;

  n = 0;
  if ((spot_nbr = nbr_spot(rt)) == 0)
    return (obj->color);
  color_tab = xmalloc(sizeof(*color_tab) * spot_nbr);
  spot = rt->spot;
  while (spot)
    {
      cos_a_calcul(&lumin, obj, spot);
      color_tab[n] = modif_color_with_spot(obj->color, spot->color,
				       obj->gloss, lumin.cos_a);
      color_tab[n] = shadows(rt, obj, &lumin, color_tab[n]);
      n++;
      spot = spot->next;
    }
  color = color_addition(color_tab, spot_nbr);
  free(color_tab);
  return (color);
}
