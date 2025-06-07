
#include "../includes/cube.h"

int	draw_big_ray_to_pixel(t_map *m, t_minimap *mi)
{
	int	map_x;
	int	map_y;

	map_x = mi->ray_x / TILE;
	map_y = mi->ray_y / TILE;
	mi->draw_x = (mi->ray_x - (mi->start_x * TILE));
	mi->draw_y = (mi->ray_y - (mi->start_y * TILE));
	if ((map_x >= 0 && map_x < m->m_width && map_y >= 0 && \
	map_y < m->m_height && m->coord[map_y][map_x] == '1'))
		return (STOP);
	if (mi->draw_x >= 0 && mi->draw_x < (mi->draw_mi_x + 1) * TILE && \
	mi->draw_y >= 0 && 	mi->draw_y < (mi->draw_mi_y + 1) * TILE)
		img_pixel_put(cube()->cube_image, mi->draw_x, mi->draw_y, GN);
	return (CONTINUE);
}

void	draw_big_ray(t_map *m, t_minimap *mi, t_player *p, float ra)
{
	int		i;

	mi->ray_x = p->pos_x * TILE;
	mi->ray_y = p->pos_y * TILE;
	mi->dir_x = cos(deg_to_rad(ra));
	mi->dir_y = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (draw_big_ray_to_pixel(m, mi) == STOP)
			break ;
		mi->ray_x += mi->dir_x;
		mi->ray_y += mi->dir_y;
		i++;
	}
}

void	draw_big_rays(t_map *m, t_minimap *mi, t_player *p)
{
	int		r;
	double	ra;

	r = 0;
	ra = get_player_angle(p);
	while (r < 68)
	{
		draw_big_ray(m, mi, p, ra);
		ra = fix_ang(ra - 1);
		r++;
	}
}

void	draw_big_player(t_minimap *mi, t_player *p)
{
	mi->draw_x = (p->pos_x - mi->start_x) * TILE;
	mi->draw_y = (p->pos_y - mi->start_y) * TILE;

	draw_block(cube(), mi->draw_x - 2, mi->draw_y - 2, 4, 4, 0xFFFF00);
}

void	draw_big_map(t_map *m, t_minimap *mi)
{
	int	y;
	int	x;

	// Draw a 10x10 grid around the player
	y = mi->start_y - 1;
	while (++y <= mi->end_y)
	{
		x = mi->start_x - 1;
		while (++x <= mi->end_x)
		{
			// Calculate the position to draw on the mini-map
			mi->draw_mi_x = ((double)x - mi->start_x);
			mi->draw_mi_y = ((double)y - mi->start_y);
			// Check if the current coordinates are within the actual map bounds
			if (x >= 0 && x < m->m_width && y >= 0 && y < m->m_height)
			{
				if (m->coord[y][x] == '0')
					draw_block(cube(), mi->draw_mi_x * TILE, mi->draw_mi_y * TILE, TILE, TILE, BL);
				else
					draw_block(cube(), mi->draw_mi_x * TILE, mi->draw_mi_y * TILE, TILE - 1, TILE - 1, GR);
			}
			else
				//If out of bounds, draw a black block
				draw_block(cube(), mi->draw_mi_x * TILE, mi->draw_mi_y * TILE, TILE - 1, TILE - 1, GR);
		}
	}
}
