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
			//TODO: calcular player position
	g->player->pos_x = 2;
	g->player->pos_y = 3;
	//g->player->dir = 'W';
	player_direction(g->player);
	g->map = malloc(sizeof(t_map));
			//TODO: calcular altura e largura do mapa
	g->map->m_height = 16;
	g->map->m_width = 14;
	g->map->coord = NULL;
	g->mini_map = malloc(sizeof(t_minimap));
	g->mini_map->size = 5;
	g->cube_image = malloc(sizeof(t_image));
	g->cart_image = malloc(sizeof(t_image));
	g->keys = malloc(sizeof(t_key));
	/* g->keys->w = 0;
	g->keys->s = 0;
	g->keys->a = 0;
	g->keys->d = 0;
	g->keys->l_arrow = 0;
	g->keys->r_arrow = 0; */
}
