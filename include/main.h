#ifndef		MAIN_H_
# define	MAIN_H_

#include	<math.h>

/*
** Inititalisation value
*/
#define		INIT		-1

/*
** Boolean values
*/
enum		BOOLEAN		{FALSE, TRUE};

/*
** Function return values
*/
enum		RETURN		{FAILURE, SUCCESS};

/*
** Coord values
*/
enum		COORD		{X, Y, Z};

/*
** Hide object value
*/
#define		HIDE		-1

/*
** Distance to the X axis of eye
*/
#define		DIST		100

/*
** Parametrized macros
*/
#define		SQR(x)	       	(x) * (x)
#define		DEGREE(x)     	(x) * M_PI / 180
#define		MIN(x1, x2)	(x1) < (x2) ? (x1) : (x2)
#define		MAX(x1, x2)	(x1) > (x2) ? (x1) : (x2)
#define		TO_UP(x)	(x) >='a' && (x) <='z' ? ((x)-('a'-'A')) : (x)
#define		IS_NUM(x)	(TO_UP(x)) >= '0' && (TO_UP(x)) <= '9' ? 1 : 0
#define		IS_ALPHA_HEX(x) (TO_UP(x)) >= 'A' && (TO_UP(x)) <= 'F' ? 1 : 0
#define		IS_HEXA(x)	(IS_NUM(x)) || (IS_ALPHA_HEX(x)) ? 1 : 0

/*
** Mlx structure
*/
typedef struct  s_mlx
{
  void		*mlx;
  void		*img;
  void		*win;
  void		*mlx_load;
  void		*img_load;
  void		*win_load;
  int		win_size[2];
}		t_mlx;

/*
** Eye structure
*/
typedef struct  s_eye
{
  double       	eye[3];
  double       	position[3];
  double       	rotation[3];
  double       	vector[3];
  double       	point[3];
}		t_eye;

/*
** Objects structure
*/
typedef struct	s_obj
{
  unsigned int 	object;
  unsigned int 	color;
  double       	position[3];
  double       	rotation[3];
  double	reflexion;
  double	limit_min[3];
  double	limit_max[3];
  double       	radius;
  double       	constant;
  double	gloss;
  double	reflection;
  double	transparency;
  double	index;
  double       	k;
  double       	point[3];
  double       	vector[3];
  struct s_obj	*next;
}		t_obj;

/*
** Spots structure
*/
typedef struct  s_spot
{
  double       	position[3];
  unsigned int	color;
  struct s_spot	*next;
}		t_spot;

/*
** Final raytracing structure
*/
typedef struct  s_rt
{
  t_mlx		mlx;
  t_eye		eye;
  t_obj		*obj;
  t_spot	*spot;
}		t_rt;

/*
** Function prototypes
*/
void		fill_image(t_rt *);
unsigned int	get_color(t_rt *);

#endif		/* !MAIN_H_ */
