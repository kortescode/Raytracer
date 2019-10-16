#ifndef		INTER_H_
# define	INTER_H_

#include	"main.h"

/*
** Object values
*/
enum		OBJECT
  {
    NOTHING  =	-1,
    PLAN,
    SPHERE,
    CYLINDER,
    CONE,
    PARABOLOID,
    HYPERBOLOID
  };

/*
** Function pointers
*/
typedef struct	s_inter
{
  void		(*func)(t_rt *, t_obj *);
}		t_inter;

/*
** Function prototypes
*/
void		inter_calculs(t_rt *);
void		inter_point_calcul(t_obj *, double [], double []);
void		inter_plan(t_rt *, t_obj *);
void		inter_sphere(t_rt *, t_obj *);
void		inter_cylinder(t_rt *, t_obj *);
void		inter_cone(t_rt *, t_obj *);
void		inter_paraboloid(t_rt *, t_obj *);
void		inter_hyperboloid(t_rt *, t_obj *);

#endif		/* !INTER_H_ */
