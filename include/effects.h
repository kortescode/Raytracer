/*
** effects.h for raytracer in /home/tomase_n//RT/rtv42/hardil_h/raytracer
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sun Jun  5 02:15:43 2011 nikola tomasevic
** Last update Sun Jun  5 17:24:50 2011 henri hardillier
*/

#ifndef		EFFECTS_H_
# define	EFFECTS_H_

#include	"main.h"

/*
** Luminosity structure
*/
typedef struct	s_lumin
{
  double	cos_a;
  double	normal_l;
  double	normal_n;
  double	vector_l[3];
}		t_lumin;

/*
** Mode for save_and_restore_values
*/
enum		MEMMODE		{SAVE, RESTORE};

/*
** Colors hex code
*/
enum		COLOR
  {
    RED	    =	0xFF0000,
    LIME    =	0x00FF00,
    NAVY    =	0x000080,
    TEAL    =	0x008080,
    GREY    =	0x808080,
    BLUE    =	0x0000FF,
    PINK    =	0xFF00FF,
    AQUA    =	0x00FFFF,
    BLACK   =	0x000000,
    GREEN   =	0x008000,
    OLIVE   =	0x808000,
    WHITE   =	0xFFFFFF,
    SILVER  =	0xC0C0C0,
    MAROON  =	0x800000,
    PURPLE  =	0x800080,
    ORANGE  =	0xFF8000,
    YELLOW  =	0xFFFF00,
    FUCHSIA =	0xFF00FF
  };

/*
** Function prototypes
*/
unsigned int   	luminosity(t_rt *, t_obj *);
unsigned int	shadows(t_rt *, t_obj *, t_lumin *, unsigned int);
unsigned int	modif_color_with_spot(unsigned int, unsigned int,
				      double, double);
unsigned int	modif_color_with_effect(unsigned int, unsigned int, double);
unsigned int	color_addition(unsigned int *, int);
unsigned int	reflection(t_rt *, t_obj *, unsigned int);
unsigned int	transparency(t_rt *, t_obj *, unsigned int);
void		save_restore_shadow_values(t_obj *, int);
void		save_restore_transparency_values(t_rt *, double [],
						 double [], int);

#endif		/* !EFFECTS_H_ */
