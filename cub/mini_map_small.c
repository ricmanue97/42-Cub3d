
#include "../includes/cube.h"

int	draw_small_ray_to_pixel(t_map *m, t_minimap *mi)
{
	int	map_x;
	int	map_y;

	map_x = mi->ray_x / TILE;
	map_y = mi->ray_y / TILE;
	if (map_x >= 0 && map_x < m->m_width && map_y >= 0 && \
	map_y < m->m_height && m->coord[map_y][map_x] == '1')
		return (STOP);
	img_pixel_put(cube()->cube_image, mi->ray_x, mi->ray_y, GN);
	return (CONTINUE);
}

void draw_small_ray(t_map *m, t_minimap *mi, t_player *p, float ra)
{
	int		i;

	mi->ray_x = p->pos_x * TILE;
	mi->ray_y = p->pos_y * TILE;
	mi->dir_x = cos(deg_to_rad(ra));
	mi->dir_y = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (draw_small_ray_to_pixel(m, mi) == STOP)
			break ;
		mi->ray_x += mi->dir_x;
		mi->ray_y += mi->dir_y;
		i++;
	}
}

void	draw_small_rays(t_map *m, t_minimap *mi, t_player *p)
{
	int		r;
	float	ra;

	r = 0;
	ra = get_player_angle(p);
	while (r < 68)
	{
		draw_small_ray(m, mi, p, ra);
		ra = fix_ang(ra - 1);
		r++;
	}
}

void	draw_small_player(t_player *p)
{
	draw_block(cube(), p->pos_x * TILE - 1.3f, \
	p->pos_y * TILE - 1.3f, 4, 4, YE);
}

void	draw_small_map(t_map *m)
{
	int	y;
	int	x;

	y = -1;
	while (++y < m->m_height)
	{
		x = -1;
		while (m->coord[y][++x] == '0' || m->coord[y][x] == '1')
			draw_block(cube(), x * TILE, y * TILE, TILE, TILE, BL);
	}
	y = -1;
	while (++y < m->m_height)
	{
		x = -1;
		while (m->coord[y][++x] != '\0')
		{
			if(m->coord[y][x] == '1')
				draw_block(cube(), x * TILE, y * TILE, TILE - 1, TILE - 1, GR);
		}
	}
}
