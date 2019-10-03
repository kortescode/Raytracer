/*
** errors.h for errors in /home/joyeux_a//rtv42/scenes/include
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Wed Jun  1 10:44:01 2011 anthony joyeux
** Last update Sat Jun  4 23:14:10 2011 henri hardillier
*/

#ifndef			ERRORS_H_
# define	       	ERRORS_H_

/*
** General errors
*/
#define			ERRUSAGE	"usage : %s [scene_config].\n"
#define			ERRNOOBJ	"error : no objects detected.\n"
#define			ERRTYPE		"error : \"%s\" isn't a valid type.\n"
#define			ERROPT		"error : \"%s\" isn't a valid option.\n"
#define			ERRSYN		"error : syntax error : \"%s\".\n"

/*
** Error for all options
*/
#define			ERRROTATE      	"error : rotation values "
#define			ERRPOS		"error : position values "
#define			ERRNUM		"error : numerical value "
#define			ERRGLOSS	"error : gloss value "
#define			ERRRADIUS	"error : radius value "
#define			ERRCONSTANT	"error : constant value "
#define			ERRTRANS	"error : transparency value "
#define			ERRINDEX	"error : index value "
#define			ERRCOORD	"error : coords value "
#define			ERRREFLECT	"error : reflection value "
#define			ERRCOLOR	"error : color value is invalid or "

/*
** Error types
*/
#define			CHAR		"contains invalid characters : \""
#define			VALBET      	"must be between 0 and 1 : \""
#define			VALPOS		"a positive value : \""

/*
** To close the verbose string
*/
#define			END		"\".\n"

#endif			/* !ERRORS_H_ */
