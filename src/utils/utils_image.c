

#include "minirt.h"

/* Draw the points of the previous image with the background color */
void	map_erase(t_minirt *minirt)
{
	size_t	screen_size;

	screen_size = minirt->image->width * minirt->image->height * \
		sizeof(uint32_t);
	ft_bzero(minirt->image->pixels, screen_size);
}

void	resize_image(int32_t width, int32_t height, void *param)
{
	t_minirt	*minirt;

	minirt = (t_minirt *)param;
	mlx_resize_image(minirt->image, width, height);
	ray_launcher();
}
