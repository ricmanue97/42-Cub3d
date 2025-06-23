
#include "../includes/cub.h"

int	corners_stop(t_map *m, t_minimap *mn, int map_y, int map_x)
{
	if (mn->dir_x < 0 && map_y != (int)cub()->player->pos_y && \
	map_x != (int)cub()->player->pos_x)
	{
		if (mn->dir_y < 0 && \
		m->coord[map_y + 1][map_x] == '1' && m->coord[map_y][map_x + 1] == '1')
			return (STOP);
		if (mn->dir_y > 0 && \
		m->coord[map_y - 1][map_x] == '1' && m->coord[map_y][map_x + 1] == '1')
			return (STOP);
	}
	if (mn->dir_x > 0 && map_y != (int)cub()->player->pos_y && \
	map_x != (int)cub()->player->pos_x)
	{
		if (mn->dir_y < 0 && \
		m->coord[map_y + 1][map_x] == '1' && m->coord[map_y][map_x - 1] == '1')
			return (STOP);
		if (mn->dir_y > 0 && \
		m->coord[map_y - 1][map_x] == '1' && m->coord[map_y][map_x - 1] == '1')
			return (STOP);
	}
	return (CONTINUE);
}

int	draw_big_ray_to_pixel(t_map *m, t_minimap *mn)
{
	int	map_x;
	int	map_y;

	map_x = mn->ray_x / TILE;
	map_y = mn->ray_y / TILE;
	mn->draw_x = (mn->ray_x - (mn->start_x * TILE));
	mn->draw_y = (mn->ray_y - (mn->start_y * TILE));
	if ((map_x >= 0 && map_y >= 0 && m->coord[map_y][map_x] == '1'))
		return (STOP);
	if (map_x >= 0 && map_x < m->m_width && map_y >= 0 && \
	map_y < m->m_height && corners_stop(m, mn, map_y, map_x) == STOP)
		return (STOP);
	if (mn->draw_x >= 0 && mn->draw_x < (mn->draw_mi_x + 1) * TILE && \
	mn->draw_y >= 0 && 	mn->draw_y < (mn->draw_mi_y + 1) * TILE)
		img_pixel_put(cub()->cub_image, mn->draw_x, mn->draw_y, GN);
	return (CONTINUE);
}

void	draw_big_ray(t_map *m, t_minimap *mn, t_player *p, float ra)
{
	int		i;

	mn->ray_x = p->pos_x * TILE;
	mn->ray_y = p->pos_y * TILE;
	mn->dir_x = cos(deg_to_rad(ra));
	mn->dir_y = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (draw_big_ray_to_pixel(m, mn) == STOP)
			break ;
		mn->ray_x += mn->dir_x;
		mn->ray_y += mn->dir_y;
		i++;
	}
}

void	draw_big_rays(t_map *m, t_minimap *mn, t_player *p)
{
	int		r;
	double	ra;

	r = 0;
	ra = get_player_angle(p);
	while (r < 68)
	{
		draw_big_ray(m, mn, p, ra);
		ra = fix_ang(ra - 1);
		r++;
	}
}

void	draw_big_player(t_minimap *mn, t_player *p)
{
	mn->draw_x = (p->pos_x - mn->start_x) * TILE;
	mn->draw_y = (p->pos_y - mn->start_y) * TILE;

	draw_block(cub(), mn->draw_x - 2, mn->draw_y - 2, 4, 4, YE);
}

void	draw_big_map(t_map *m, t_minimap *mn)
{
	int	y;
	int	x;

	y = mn->start_y - 1;
	while (++y <= mn->end_y)
	{
		x = mn->start_x - 1;
		while (++x <= mn->end_x)
		{
			mn->draw_mi_x = ((double)x - mn->start_x);
			mn->draw_mi_y = ((double)y - mn->start_y);
			if (x >= 0 && x < m->m_width && y >= 0 && y < m->m_height)
			{
				if (m->coord[y][x] == '0')
					draw_block(cub(), mn->draw_mi_x * TILE, \
					mn->draw_mi_y * TILE, TILE, TILE, BL);
				else
					draw_block(cub(), mn->draw_mi_x * TILE, \
					mn->draw_mi_y * TILE, TILE - 1, TILE - 1, GR);
			}
			else
				draw_block(cub(), mn->draw_mi_x * TILE, \
				mn->draw_mi_y * TILE, TILE - 1, TILE - 1, GR);
		}
	}
}
