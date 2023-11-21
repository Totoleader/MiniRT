

#include "../../include/minirt_bonus.h"

void	load_sun(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	minirt->material[SUN].id = SUN;
	minirt->material[SUN].texture = \
	mlx_load_png("textures_png/sun/8k_sun.png");
	minirt->material[SUN].norm_map = NULL;
	minirt->material[SUN].shine = 1000;
	minirt->material[SUN].reflexion = 0.0000001;
	minirt->material[SUN].specular_factor = 0;
}
