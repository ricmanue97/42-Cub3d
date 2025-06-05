#include "../includes/cube.h"

//Figuring the player direction
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
	g->player->dir = 'W';
			//TODO: calcular player direction
	player_direction(g->player);
	g->map = malloc(sizeof(t_map));
			//TODO: calcular altura e largura do mapa
	g->map->map_height = 7;
	g->map->map_width = 6;
	g->map->coord = NULL;
	g->cube_image = malloc(sizeof(t_image));
	g->cart_image = malloc(sizeof(t_image));
}
