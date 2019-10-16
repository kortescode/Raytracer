#ifndef		SAVE_H_
# define	SAVE_H_

/*
** Macros to draw images
*/
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

/*
** Function prototypes
*/
void		save_img(void *, int, int, char *);

char		*xcolor_change(char *, char *);
char		*xcolor_it(char *, char *, char *, char *);

int		xload_fill_bar_col(int, double);
int		xload_fill_bar_ncol(int, double);
int		xload_fill_bar(int, double, int);
char		*xload_get_word_col(int *, double);
char		*xload_get_word_ncol(int *, double);
char		*xload_get_word(int *, double, int);
int		xload_percent(int, double, int);

#endif		/* !SAVE_H_ */
