
#include "../includes/cub.h"

void	free_pointer(void *pointer)
{
	if (pointer)
		free(pointer);
	pointer = NULL;
}

void	free_double_p(void **pointer)
{
	int	i;

	if (pointer)
	{
		i = -1;
		if (pointer[0])
		{
			while (pointer[++i])
				free_pointer(pointer[i]);
		}
		free(pointer);
		pointer = NULL;
	}
}

void	free_image(t_game *g, t_image *i)
{
	if (i && i->image)
		mlx_destroy_image(g->mlx, i->image);
}

void	free_cub(t_game *g)
{

	free_pointer((void *)g->keys);
	free_pointer((void *)g->mini_map);
	free_pointer((void *)g->player);
	free_pointer((void *)g->map->path);
	free_double_p((void **)g->map->coord);
	free_pointer((void *)g->map);
	free_image(g, g->cart_image);
	if (g->sprite_array[0].image)
	{
		free(g->sprite_array[0].path);
		mlx_destroy_image(g->mlx, g->sprite_array[0].image);
		free(g->sprite_array[1].path);
		mlx_destroy_image(g->mlx, g->sprite_array[1].image);
		free(g->sprite_array[2].path);
		mlx_destroy_image(g->mlx, g->sprite_array[2].image);
		free(g->sprite_array[3].path);
		mlx_destroy_image(g->mlx, g->sprite_array[3].image);
	}
}
void	free_var_init(t_game *g)
{
	if (g->player)
		free(g->player);
	if (g->map)
	{
		if (g->map->coord)
			free_double_p((void **)g->map->coord);
		if (g->map->path)
			free(g->map->path);
		free(g->map);
	}
	free_pointer(g->sprite_array[0].path);
	free_pointer(g->sprite_array[1].path);
	free_pointer(g->sprite_array[2].path);
	free_pointer(g->sprite_array[3].path);
	if (g->mini_map)
		free(g->mini_map);
	if (g->cub_image)
		free(g->cub_image);
	if (g->cart_image)
		free(g->cart_image);
	if (g->keys)
		free(g->keys);
}
