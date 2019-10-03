/*
** check_eye.c for check_eye in /home/joyeux_a//rtv42/scenes
** 
** Made by anthony joyeux
** Login   <joyeux_a@epitech.net>
** 
** Started on  Fri May 27 16:03:52 2011 anthony joyeux
** Last update Sat Jun  4 21:25:46 2011 henri hardillier
*/

#include		<stdlib.h>
#include		<string.h>
#include		<stdio.h>
#include		"errors.h"
#include		"parser.h"
#include		"my.h"

t_parseeye		ptr_eye[] =
  {
    {"position", set_eye_position},
    {"rotation", set_eye_rotation},
    {NULL, NULL},
  };

static void	check_arg(t_eye *eye, char **tab)
{
  int		n;
  int		check;

  n = 0;
  check = FAILURE;
  while (ptr_eye[n].str)
    {
      if (tab[0] && !strcmp(tab[0], ptr_eye[n].str))
	check = ptr_eye[n].func(eye, tab);
      n++;
    }
  if (tab[0] && check == FAILURE)
    {
      fprintf(stderr, ERROPT, tab[0]);
      exit(EXIT_FAILURE);
    }
}

void		check_eye(t_eye *eye, char **tab)
{
  int		i;
  char		**arg;

  i = 1;
  while (tab[i])
    {
      arg = my_worldtab(tab[i], "=,");
      check_is_num(arg);
      check_arg(eye, arg);
      xfree_tab(arg);
      i++;
    }
}
