/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 15:18:57 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	draw_small_ray_to_pixel(t_map *m, t_minimap *mm)
{
	int	map_x;
	int	map_y;

	map_x = mm->ray_x / TILE;
	map_y = mm->ray_y / TILE;
	if ((map_x >= 0 && map_y >= 0 && m->coord[map_y][map_x] == '1'))
		return (STOP);
	if (map_x >= 0 && map_x < m->m_width && map_y >= 0 && \
	map_y < m->m_height && corners_stop(m, mm, map_y, map_x) == STOP)
		return (STOP);
	img_pixel_put(cub()->cub_image, mm->ray_x, mm->ray_y, GN);
	return (CONTINUE);
}

void	draw_small_ray(t_map *m, t_minimap *mm, t_player *p, float ra)
{
	int		i;

	mm->ray_x = p->pos_x * TILE;
	mm->ray_y = p->pos_y * TILE;
	mm->dir_x = cos(deg_to_rad(ra));
	mm->dir_y = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (draw_small_ray_to_pixel(m, mm) == STOP)
			break ;
		mm->ray_x += mm->dir_x;
		mm->ray_y += mm->dir_y;
		i++;
	}
}

void	draw_small_rays(t_map *m, t_minimap *mm, t_player *p)
{
	int		r;
	float	ra;

	r = 0;
	ra = get_player_angle(p);
	while (r < 68)
	{
		draw_small_ray(m, mm, p, ra);
		ra = fix_ang(ra - 1);
		r++;
	}
}

void	draw_small_player(t_player *p)
{
	draw_block(p->pos_x * TILE - 1.3f, \
	p->pos_y * TILE - 1.3f, 4, YE);
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
			draw_block(x * TILE, y * TILE, TILE, BL);
	}
	y = -1;
	while (++y < m->m_height)
	{
		x = -1;
		while (m->coord[y][++x] != '\0')
		{
			if (m->coord[y][x] == '1')
				draw_block(x * TILE, y * TILE, TILE - 1, GR);
		}
	}
}
