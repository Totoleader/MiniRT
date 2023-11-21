

#include "../include/minirt_bonus.h"

t_minirt	*get_minirt(void)
{
	static t_minirt	*minirt;

	if (!minirt)
	{
		minirt = ft_calloc(1, sizeof(t_minirt));
		minirt->selected = CAMERA;
		printf("Object selected = camera\n");
		minirt->mode = NORMAL;
		printf("Mode selected = normal sampling\n");
	}
	return (minirt);
}

bool	init_mlx(t_minirt *minirt)
{
	minirt->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	minirt->image = mlx_new_image(minirt->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(minirt->mlx, minirt->image, 0, 0);
	if (!minirt->mlx || !minirt->image
		|| (mlx_image_to_window(minirt->mlx, minirt->image, 0, 0) == 0))
	{
		ft_putstr_fd("MLX initialization failed\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

void	minirt(int fd)
{
	t_minirt	*minirt;

	parse(fd);
	minirt = get_minirt();
	load_materials();
	if (init_mlx(minirt) == true)
	{
		mlx_mouse_hook(minirt->mlx, &minirt_mouse, minirt);
		mlx_key_hook(minirt->mlx, &minirt_keys, minirt);
		mlx_resize_hook(minirt->mlx, &resize_image, minirt);
		ray_launcher();
		mlx_loop(minirt->mlx);
	}
	free_minirt();
}

int	main(int argc, char **argv)
{
	int	fd;

	check_args_validity(argc);
	check_file_validity(argv[1]);
	fd = open(argv[1], O_RDONLY);
	minirt(fd);
	close(fd);
	return (0);
}
