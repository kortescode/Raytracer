/*
** color.h for raytracer in /home/tomase_n//RT/rtv42/hardil_h/raytracer
** 
** Made by nikola tomasevic
** Login   <tomase_n@epitech.net>
** 
** Started on  Sun Jun  5 05:52:42 2011 nikola tomasevic
** Last update Sun Jun  5 06:23:14 2011 nikola tomasevic
*/

#ifndef		COLOR_H_
# define	COLOR_H_

#define		LOADFILL	"="
#define		LOADEMPTY	" "
#define		LOADPONCT	">"
#define		LOADWALL	"|"

#define		TDEF		"0"
#define		TUN1		"1"
#define		TUN2		"2"
#define		TUN3		"3"
#define		TUNDER		"4"
#define		TBLINK		"5"
#define		TUN4		"6"
#define		TINVERT		"7"

#define		TBLACK		"30"
#define		TRED		"31"
#define		TGREEN		"32"
#define		TORANGE		"33"
#define		TBLUE		"34"
#define		TPINK		"35"
#define		TSPLEEN		"36"
#define		TWHITE		"37"

#define		TLBLACK		"90"
#define		TLRED		"91"
#define		TLGREEN		"92"
#define		TLORANGE	"93"
#define		TLBLUE		"94"
#define		TLPINK		"95"
#define		TLSPLEEN	"96"
#define		TLWHITE		"97"

#define		BBLACK		"40"
#define		BRED		"41"
#define		BGREEN		"42"
#define		BORANGE		"43"
#define		BBLUE		"44"
#define		BPINK		"45"
#define		BSPLEEN		"46"
#define		BWHITE		"47"

#define		BLBLACK		"100"
#define		BLRED		"101"
#define		BLGREEN		"102"
#define		BLORANGE	"103"
#define		BLBLUE		"104"
#define		BLPINK		"105"
#define		BLSPLEEN	"106"
#define		BLWHITE		"107"

int		xchar(int out, char c, int ret);
void		xchar_repeat(int out, char c, int ret, int n);
int		xwrite(int out, char *str, int ret);

int		xputunbr(unsigned int nb);
int		xputnbr(int nb);
char		*xbufnbr(int nb);

char		*xstrcpy(char *dest, char *src);
char		*xstrncpy(char *dest, char *src, int n);

char		*xstrdup(char *src);

char		*xstradd(char *str, char *add, int n);
char		*xstrnadd(char *str, char *add, int size, int n);

int		xmatch_exp(char *exp1, char *exp2);

char		*xcolor_change(char *str, char *color);
char		*xcolor_it(char *str, char *txt, char *bg, char *eff);

int		xload_fill_bar_col(int blen, double percent);
int		xload_fill_bar_ncol(int blen, double percent);
int		xload_fill_bar(int blen, double percent, int color);
char		*xload_get_word_col(int *len, double percent);
char		*xload_get_word_ncol(int *len, double percent);
char		*xload_get_word(int *len, double percent, int color);
int		xload_percent(int blen, double percent, int color);

#endif		/* !COLOR_H_ */
