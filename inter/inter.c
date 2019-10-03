/*
** inter.c for rt in /home/hardil_h//projets/rtv42/hardil_h/raytracer
** 
** Made by henri hardillier
** Login   <hardil_h@epitech.net>
** 
** Started on  Thu Jun  2 22:09:14 2011 henri hardillier
** Last update Sun Jun  5 01:04:35 2011 henri hardillier
*/

#include	"main.h"
#include	"inter.h"
#include	"movements.h"

t_inter		inter[] =
  {
    {inter_plan},
    {inter_sphere},
    {inter_cylinder},
    {inter_cone},
    {inter_paraboloid},
    {inter_hyperboloid},
    {0},
  };

void		inter_calculs(t_rt *rt)
{
  t_obj		*objs;

  objs = rt->obj;
  while (objs)
    {
      translate(rt->eye.eye, -objs->position[X],
		-objs->position[Y], -objs->position[Z]);
      rev_rotate(rt->eye.eye, -objs->rotation[X],
		 -objs->rotation[Y], -objs->rotation[Z]);
      rev_rotate(rt->eye.vector, -objs->rotation[X],
		 -objs->rotation[Y], -objs->rotation[Z]);
      inter[objs->object].func(rt, objs);
      rotate(rt->eye.vector, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      rotate(rt->eye.eye, objs->rotation[X],
	     objs->rotation[Y], objs->rotation[Z]);
      translate(rt->eye.eye, objs->position[X],
		objs->position[Y], objs->position[Z]);
      objs = objs->next;
    }
}

void		inter_point_calcul(t_obj *object, double point[], double vector[])
{
  object->point[X] = point[X] + (object->k * vector[X]);
  object->point[Y] = point[Y] + (object->k * vector[Y]);
  object->point[Z] = point[Z] + (object->k * vector[Z]);
}
