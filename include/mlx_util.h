/*
** mlx.h for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer/include
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Tue May 31 21:51:27 2011 henri hardillier
** Last update Sun Jun  5 14:56:10 2011 henri hardillier
*/

#ifndef		MLX_UTIL_H_
# define	MLX_UTIL_H_

#include	"main.h"

/*
** Key value
*/
#define		KS		115
#define		ESC		65307

/*
** Function prototypes
*/
int		init_mlx(t_rt *);
void		fix_mlx(t_rt *);
int     	gere_expose(t_mlx *);
int     	gere_key(int, t_mlx *);
void    	pixel_put_to_image(void *, int, int, unsigned int);

#endif		/* !MLX_UTIL_H_ */
