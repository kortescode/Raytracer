#ifndef		LIMITS_H_
# define	LIMITS_H_

/*
** Function prototypes
*/
int		is_hide(t_obj *);
void		revise_vector(t_rt *, t_obj *);
void		limits_sphere(t_rt *, t_obj *);
void		limits_cylinder(t_rt *, t_obj *);
void		limits_cone(t_rt *, t_obj *);
void		limits_paraboloid(t_rt *, t_obj *);
void		limits_hyperboloid(t_rt *, t_obj *);

#endif		/* !LIMITS_H_ */
