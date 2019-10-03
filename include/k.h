/*
** k.h for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/include
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Tue May 31 21:43:10 2011 henri hardillier
** Last update Thu Jun  2 22:52:00 2011 henri hardillier
*/

#ifndef		K_H_
# define	K_H_

#include	"main.h"

/*
** For a, b, and c variables
*/
enum		VAR		{A, B, C};

/*
** Function pointers
*/
typedef struct	s_k
{
  double       	(*func)(double [], double [], t_obj *, int);
}		t_k;

/*
** Modes for delta_calcul and for k calcul
*/
enum		MODE		{MIN, MAX};

/*
** Function prototypes
*/
double		delta_calcul(double [], int);
double		k_plan(double [], double [], t_obj *, int);
double		k_sphere(double [], double [], t_obj *, int);
double		k_cylinder(double [], double [], t_obj *, int);
double		k_cone(double [], double [], t_obj *, int);
double		k_paraboloid(double [], double [], t_obj *, int);
double		k_hyperboloid(double [], double [], t_obj *, int);

#endif		/* !K_H_ */
