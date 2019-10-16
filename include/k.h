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
