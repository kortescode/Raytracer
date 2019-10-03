/*
** translation.c for rt in /home/hardil_h//projets/raytracer/rtv42/hardil_h/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Fri May 27 00:24:46 2011 henri hardillier
** Last update Thu Jun  2 23:03:57 2011 henri hardillier
*/

#include	"main.h"

void		translate(double old[], double angle_x,
			  double angle_y, double angle_z)
{
  double       	new[3];

  new[X] = old[X] + angle_x;
  new[Y] = old[Y] + angle_y;
  new[Z] = old[Z] + angle_z;
  old[X] = new[X];
  old[Y] = new[Y];
  old[Z] = new[Z];
}
