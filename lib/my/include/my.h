#ifndef		MY_H_
# define	MY_H_

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<signal.h>

typedef		void (*sighandler_t)(int);

/*
** Error value
*/
#define		ERROR		-1

/*
** Values for get_next_line
*/
#define			BUFF_SIZE 4096
#define			READ_SIZE 4096

/*
** X function protoypes
*/
int		xopen(const char *, int, mode_t);
void		*xmalloc(int);
void		xclose(int);
int		xread(int, void *, int);
void	       	xfree_tab(char **);
int		xwrite(int, void *, int);
void		*xmlx_init(void);
void		*xmlx_new_image(void *, int, int);
void		*xmlx_new_window(void *, int, int, char *);
sighandler_t	xsignal(int, sighandler_t);

/*
** My function protoypes
*/
char	       	*get_next_line(const int);
char	       	**my_worldtab(char *, char *);
int	       	my_getnbr_base(char *, char *);
char	       	*my_strupcase(char *);
char		*my_strlowcase(char *);
int		my_char(int, char, int);
void		my_char_repeat(int, char, int, int);
int		my_write(int, char *, int);
int		my_putunbr(unsigned int);
void		my_putstr(char *);
int		my_putnbr(int);
char		*my_bufnbr(int);
char		*my_strcpy(char *, char *);
char		*my_strncpy(char *, char *, int);
char		*my_strdup(char *);
char		*my_stradd(char *, char *, int);
char		*my_strnadd(char *, char *, int, int);
int		my_match_exp(char *, char *);

#endif		/* !MY_H_ */
