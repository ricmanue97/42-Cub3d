#include "../includes/cub.h"

void	player_direction(t_player *p)
{
	float	angle;
	float	rad;

	if (p->dir == 'N')
		angle = 90.0;
	else if (p->dir == 'E')
		angle = 0.0;
	else if (p->dir == 'S')
		angle = 270.0;
	else
		angle = 180.0;
	rad = deg_to_rad(angle);
	p->dir_x = cos(rad);
	p->dir_y = -sin(rad);
	p->plane_x = 0.66 * sin(rad);
	p->plane_y = 0.66 * cos(rad);
}

void	pointer_to_null(t_game *g)
{
	int i;

	i = -1;
	while (++i < 4)
		g->sprite_array[i].image = NULL;
	g->mlx = NULL;
	g->win = NULL;
	g->player = NULL;
	g->map = NULL;
	g->mini_map = NULL;
	g->cub_image = NULL;
	g->cart_image = NULL;
	g->keys = NULL;
}

void keys_init(t_key *keys)
{
	keys->l_arrow = 0;
	keys->r_arrow = 0;
	keys->w = 0;
	keys->d = 0;
	keys->s = 0;
	keys->a = 0;
}

void	map_init(t_game *g)
{
	g->map = malloc(sizeof(t_map));
	if (!g->map)
		error_to_exit(g, MALL_ERR);
	g->map->coord = NULL;
	g->map->path = NULL;
	g->map->F = 0;
	g->map->C = 0;
	g->map->m_height = 0;
	g->map->m_width = 0;
	g->mini_map = malloc(sizeof(t_minimap));
	if (!g->mini_map)
		error_to_exit(g, MALL_ERR);
	g->mini_map->size = 5;
}

void	var_init(t_game *g)
{
	pointer_to_null(g);
	g->player = malloc(sizeof(t_player));
	if (!g->player)
		error_to_exit(g, MALL_ERR);
	g->player->dir = 'A';
	map_init(g);
	g->cub_image = malloc(sizeof(t_image));
	if (!g->cub_image)
		error_to_exit(g, MALL_ERR);
	g->cart_image = malloc(sizeof(t_image));
	if (!g->cart_image)
		error_to_exit(g, MALL_ERR);
	g->cart_image->image = NULL;
	g->keys = malloc(sizeof(t_key));
	if (!g->keys)
		error_to_exit(g, MALL_ERR);
	keys_init(g->keys);
}
