/*
** k_calculs.c for rt in /home/hardil_h//projets/raytracer/rtv42/hardil_h/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Mon May 30 23:41:04 2011 henri hardillier
** Last update Thu Jun  2 23:02:43 2011 henri hardillier
*/

#include	<math.h>

#include	"main.h"
#include	"k.h"

double		delta_calcul(double var[], int mode)
{
  double       	k1;
  double       	k2;
  double       	delta;

  delta = SQR(var[B]) - (4.0 * var[A] * var[C]);
  if (delta < 0.0)
    return (HIDE);
  k1 = (-var[B] + sqrt(delta)) / (2.0 * var[A]);
  k2 = (-var[B] - sqrt(delta)) / (2.0 * var[A]);
  if (k1 > 0.0 && k2 > 0.0)
    {
      if (mode == MIN)
	return (MIN(k1, k2));
      else if (mode == MAX)
	return (MAX(k1, k2));
    }
  else if (k1 > 0.0)
    return (k1);
  else if (k2 > 0.0)
    return (k2);
  return (HIDE);
}
