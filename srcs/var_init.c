#include "../includes/cube.h"

//Determine the player direction
void	player_direction(t_player *p)
{
	double angle;
	double rad;

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

void	var_init(t_game *g)
{
	g->player = malloc(sizeof(t_player));
	g->player->pos_x = 0;
	g->player->pos_y = 0;
	player_direction(g->player);
	g->map = malloc(sizeof(t_map));
	g->map->m_height = 0;
	g->map->m_width = 0;
	g->map->coord = NULL;
	g->mini_map = malloc(sizeof(t_minimap));
	g->mini_map->size = 5;
	g->cube_image = malloc(sizeof(t_image));
	g->cart_image = malloc(sizeof(t_image));
	g->keys = malloc(sizeof(t_key));
}
