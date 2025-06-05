
#include "../includes/cube.h"

int	draw_ray_to_pixel(t_game *g, double rx, double ry)
{
	int	mx;
	int	my;

	mx = rx / TI_SIZE;
	my = ry / TI_SIZE;
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

	rx = g->player->pos_x * TI_SIZE;
	ry = g->player->pos_y * TI_SIZE;
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
		ra = fix_ang(ra - 1);
		r++;
	}
}

void	draw_player(t_game *g)
{
	draw_block(g, g->player->pos_x * TI_SIZE - 1.4f, \
	g->player->pos_y * TI_SIZE - 1.3f, 4, 4, 0xFFFF00);
}

void	draw_map(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (++y < map->map_height)
	{
		x = -1;
		while (map->coord[y][++x] == '0' || map->coord[y][x] == '1')
			draw_block(cube(), x * TI_SIZE, y * TI_SIZE, TI_SIZE, TI_SIZE, \
			0x000000);
	}
	y = -1;
	while (++y < map->map_height)
	{
		x = -1;
		while (map->coord[y][++x] != '\0')
		{
			if(map->coord[y][x] == '1')
				draw_block(cube(), x * TI_SIZE, y * TI_SIZE, TI_SIZE - 1, \
				TI_SIZE - 1, 0x999999);
			/* else if(g->map->coord[y][x] == '0')
				color = 0x000000; */
		}
	}
}
