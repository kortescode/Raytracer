/*
** limits.h for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 17:26:47 2011 henri hardillier
** Last update Thu Jun  2 22:29:30 2011 henri hardillier
*/

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
