#include	"main.h"
#include	"effects.h"

static void    	restore_transparency_values(t_rt *rt, double e_tmp [],
					    double v_tmp [])
{
  rt->eye.eye[X] = e_tmp[X];
  rt->eye.eye[Y] = e_tmp[Y];
  rt->eye.eye[Z] = e_tmp[Z];
  rt->eye.point[X] = v_tmp[X];
  rt->eye.point[Y] = v_tmp[Y];
  rt->eye.point[Z] = v_tmp[Z];
}

void		save_restore_transparency_values(t_rt *rt, double point [],
						 double vector [], int mode)
{
  static double	e_tmp[3];
  static double	v_tmp[3];

  if (mode == SAVE)
    {
      e_tmp[X] = rt->eye.eye[X];
      e_tmp[Y] = rt->eye.eye[Y];
      e_tmp[Z] = rt->eye.eye[Z];
      v_tmp[X] = rt->eye.point[X];
      v_tmp[Y] = rt->eye.point[Y];
      v_tmp[Z] = rt->eye.point[Z];
      rt->eye.eye[X] = point[X];
      rt->eye.eye[Y] = point[Y];
      rt->eye.eye[Z] = point[Z];
      rt->eye.vector[X] = vector[X];
      rt->eye.vector[Y] = vector[Y];
      rt->eye.vector[Z] = vector[Z];
    }
  else if (mode == RESTORE)
    restore_transparency_values(rt, e_tmp, v_tmp);
}

void		save_restore_shadow_values(t_obj *objs, int mode)
{
  static double	k_tmp;
  static double	p_tmp[3];

  if (mode == SAVE)
    {
      k_tmp = objs->k;
      p_tmp[X] = objs->point[X];
      p_tmp[Y] = objs->point[Y];
      p_tmp[Z] = objs->point[Z];
    }
  else if (mode == RESTORE)
    {
      objs->k = k_tmp;
      objs->point[X] = p_tmp[X];
      objs->point[Y] = p_tmp[Y];
      objs->point[Z] = p_tmp[Z];
    }
}
