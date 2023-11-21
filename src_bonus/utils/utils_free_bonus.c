

#include "../../include/minirt_bonus.h"

void	ft_free_lights(t_list **lst)
{
	t_list		*ptr;
	t_list		*tmp;
	t_object	*tmpo;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->content)
		{
			tmpo = ptr->content;
			tmpo = ft_freenull(tmpo);
		}
		ptr = ft_freenull(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}

void	ft_free_lst(t_list **lst)
{
	t_list		*ptr;
	t_list		*tmp;
	t_object	*tmpo;

	if (!lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		if (ptr->content)
		{
			tmpo = ptr->content;
			if (tmpo->obj)
				tmpo->obj = ft_freenull(tmpo->obj);
			tmpo = ft_freenull(tmpo);
		}
		ptr = ft_freenull(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}

void	free_textures(void)
{
	int	i;

	i = 0;
	while (i < TEXTURE_COUNT)
	{
		if (get_minirt()->material[i].texture)
			mlx_delete_texture(get_minirt()->material[i].texture);
		if (get_minirt()->material[i].norm_map)
			mlx_delete_texture(get_minirt()->material[i].norm_map);
		i++;
	}
}

void	free_minirt(void)
{
	t_minirt	*minirt;

	minirt = get_minirt();
	if (minirt->objects)
		ft_free_lst(&minirt->objects);
	if (minirt->lights)
		ft_free_lights(&minirt->lights);
	if (minirt->mlx)
		mlx_terminate(minirt->mlx);
	free_textures();
	minirt = ft_freenull(minirt);
}
