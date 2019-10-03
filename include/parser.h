/*
** RT.h for rt in /home/schrey_i//local/work/RT
** 
** Made by ithyvan schreys
** Login   <schrey_i@epitech.net>
** 
** Started on  Tue May 17 15:46:18 2011 ithyvan schreys
** Last update Sun Jun  5 21:30:44 2011 henri hardillier
*/

#ifndef			PARSER_H_
# define		PARSER_H_

#include		"main.h"

/*
** Recognition of types
*/
typedef struct		s_conf
{
  char			*str;
  int			(*func)(t_rt *, char **);
}			t_conf;

int			stock_eye(t_rt *, char **);
int			stock_mlx(t_rt *, char **);
int			stock_spot(t_rt *, char **);
int			stock_object(t_rt *, char **);

/*
** Recognition of object type
*/
typedef struct		s_setobj
{
  char			*str;
  int			value;
}			t_setobj;

/*
** Recognition of the object options
*/
typedef struct		s_parseobj
{
  char			*str;
  int			(*func)(t_obj *, char **);
}			t_parseobj;

int			set_transparency(t_obj *, char **);
int			set_gloss(t_obj *, char **);
int			set_reflection(t_obj *, char **);
int			set_index(t_obj *, char **);
int			set_constant(t_obj *, char **);
int			set_radius(t_obj *, char **);
int			set_rotation(t_obj *, char **);
int			set_position(t_obj *, char **);
int			set_limit_min_x(t_obj *, char **);
int			set_limit_min_y(t_obj *, char **);
int			set_limit_min_z(t_obj *, char **);
int			set_limit_max_x(t_obj *, char **);
int			set_limit_max_y(t_obj *, char **);
int			set_limit_max_z(t_obj *, char **);
int			define_color_obj(t_obj *, char **);

/*
** Recognition of the eye options
*/
typedef struct		s_parseeye
{
  char			*str;
  int			(*func)(t_eye *, char **);
}			t_parseeye;

int			set_eye_rotation(t_eye *, char **);
int			set_eye_position(t_eye *, char **);

/*
** Recognition of colors
*/
typedef struct		s_parsecolor
{
  char			*str;
  int			value;
}			t_parsecolor;

/*
** Recognition of indexes
*/
typedef struct		s_parseindex
{
  char			*str;
  double       		value;
}			t_parseindex;

/*
** Hexadecimal code
*/
#define			HEX		"0123456789ABCDEF"

/*
** Functions prototypes
*/
int		        get_config(t_rt *, char **);

void			add_object(t_rt *, t_obj *);
void			add_spot(t_rt *, t_spot *);

void			check_spot(t_spot *, char **);
void			check_object(t_obj *, char **);
void			check_eye(t_eye *, char **);
void			check_mlx(t_mlx *, char **);

void			init_rt(t_rt *);
void			init_object(t_obj *);
void			init_mlx_values(t_mlx *);
void			init_eye(t_eye *);
void			init_spot(t_spot *);
int			init_limit(t_obj *);

int			set_color(t_obj *, char **);
void			set_mlx_values(t_mlx *, char **);
int			set_spot_coords(t_spot *, char **);
void			set_spot_color(t_spot *, char **);
int			define_color_spot(t_spot *, char **);

int			is_num(char *);
int			is_num_mlx(char *);
int			is_valid_color(char *);
void			check_is_num(char **);
void			check_is_num_mlx(char **);
int			error_color(char *);

#endif			/* !PARSER_H_ */
