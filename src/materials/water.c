

#include "minirt.h"

void	load_wood(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[WOOD].id = WOOD;
	minirt->material[WOOD].texture = \
	mlx_load_png("textures_png/water/wod_tex.png");
	minirt->material[WOOD].norm_map = NULL;
	minirt->material[WOOD].shine = 10000;
	minirt->material[WOOD].reflexion = 0;
	minirt->material[WOOD].specular_factor = 2;
}
