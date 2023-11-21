

#include "minirt.h"

bool	first_hit_mouse(bool action)
{
	bool		output;
	static bool	first_hit = TRUE;

	if (action == TRUE)
	{
		output = first_hit;
		first_hit = FALSE;
		return (output);
	}
	else
	{
		first_hit = TRUE;
		return (FALSE);
	}
}

t_vec3	up_guide_mouse(void)
{
	t_vec3	up_guide;

	up_guide.x = 0.0f;
	up_guide.y = 1.0f;
	up_guide.z = 0.0f;
	return (up_guide);
}

void	update_closest_hit_mouse(t_hit *closest_hit, t_hit hit)
{
	closest_hit->obj = hit.obj;
	closest_hit->t = hit.t;
}

void	init_hit_mouse(t_hit *closest_hit, t_hit *hit)
{
	hit->obj = NULL;
	hit->t = 0;
	closest_hit->obj = NULL;
	closest_hit->t = 0;
}

void	object_selected(t_hit hit)
{
	if (hit.obj->type == SPHERE)
	{
		printf("Object selected = sphere\n");
		get_minirt()->selected = SPHERE;
	}
	else if (hit.obj->type == PLAN)
	{
		printf("Object selected = plan\n");
		get_minirt()->selected = PLAN;
	}
	else if (hit.obj->type == CYLINDRE)
	{
		printf("Object selected = cylinder\n");
		get_minirt()->selected = CYLINDRE;
	}
}
