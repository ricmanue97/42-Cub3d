
#include "../includes/cube.h"

int	draw_ray_to_pixel(t_game *g, double rx, double ry)
{
	int	mx;
	int	my;

	mx = rx / tile_size;
	my = ry / tile_size;
	if (mx >= 0 && mx < g->map->map_width && my >= 0 && \
	my < g->map->map_height && g->map->coord[my][mx] == '1')
		return (STOP);
	img_pixel_put(g->cube_image, rx, ry, 0x00FF00);
	return (CONTINUE);
}

// Cast rays and draw lines on 2D map
void draw_ray(t_game *g, float ra)
{
	double	rx;
	double	ry;
	double	xo;
	double	yo;
	int		i;

	rx = g->player->pos_x * tile_size;
	ry = g->player->pos_y * tile_size;
	xo = cos(deg_to_rad(ra));
	yo = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (draw_ray_to_pixel(g, rx, ry) == STOP)
			break ;
		rx += xo;
		ry += yo;
		i++;
	}
}

void	draw_rays(t_game *g)
{
	int		r;
	float	ra;

	r = 0;
	ra = get_player_angle(cube()->player);
	while (r < 60)
	{
		draw_ray(g, ra);
		ra = FixAng(ra - 1);
		r++;
	}
}

void	draw_player(t_game *g)
{
	draw_block(g, g->player->pos_x * tile_size - 1.4f, g->player->pos_y * tile_size - 1.3f, 4, 4, 0xFFFF00);
}

void	draw_map(t_game *g)
{
	int y;
	int x;
	int color;

	y = -1;
	while (++y < g->map->map_height)
	{
		x = -1;
		while (g->map->coord[y][++x] != '\0')
			draw_block(g, x * tile_size, y * tile_size, tile_size, tile_size, 0x000000);
	}
	y = -1;
	while (++y < g->map->map_height)
	{
		x = -1;
		while (g->map->coord[y][++x] != '\0')
		{
			if(g->map->coord[y][x] > '0')
				color = 0x999999;
			else
				color = 0x000000;
			draw_block(g, x * tile_size, y * tile_size, tile_size - 1, tile_size - 1, color);
		}
	}
}
