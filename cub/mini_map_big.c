/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:47 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 15:15:41 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	draw_big_ray_to_pixel(t_map *m, t_minimap *mm)
{
	int	map_x;
	int	map_y;

	map_x = mm->ray_x / TILE;
	map_y = mm->ray_y / TILE;
	mm->draw_x = (mm->ray_x - (mm->start_x * TILE));
	mm->draw_y = (mm->ray_y - (mm->start_y * TILE));
	if ((map_x >= 0 && map_y >= 0 && m->coord[map_y][map_x] == '1'))
		return (STOP);
	if (map_x >= 0 && map_x < m->m_width && map_y >= 0 && \
	map_y < m->m_height && corners_stop(m, mm, map_y, map_x) == STOP)
		return (STOP);
	if (mm->draw_x >= 0 && mm->draw_x < (mm->draw_mi_x + 1) * TILE && \
	mm->draw_y >= 0 && mm->draw_y < (mm->draw_mi_y + 1) * TILE)
		img_pixel_put(cub()->cub_image, mm->draw_x, mm->draw_y, GN);
	return (CONTINUE);
}

void	draw_big_ray(t_map *m, t_minimap *mm, t_player *p, float ra)
{
	int		i;

	mm->ray_x = p->pos_x * TILE;
	mm->ray_y = p->pos_y * TILE;
	mm->dir_x = cos(deg_to_rad(ra));
	mm->dir_y = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (draw_big_ray_to_pixel(m, mm) == STOP)
			break ;
		mm->ray_x += mm->dir_x;
		mm->ray_y += mm->dir_y;
		i++;
	}
}

void	draw_big_rays(t_map *m, t_minimap *mm, t_player *p)
{
	int		r;
	double	ra;

	r = 0;
	ra = get_player_angle(p);
	while (r < 68)
	{
		draw_big_ray(m, mm, p, ra);
		ra = fix_ang(ra - 1);
		r++;
	}
}

void	draw_big_player(t_minimap *mm, t_player *p)
{
	mm->draw_x = (p->pos_x - mm->start_x) * TILE;
	mm->draw_y = (p->pos_y - mm->start_y) * TILE;
	draw_block(mm->draw_x - 2, mm->draw_y - 2, 4, YE);
}

void	draw_big_map(t_map *m, t_minimap *mm)
{
	int	y;
	int	x;

	y = mm->start_y - 1;
	while (++y <= mm->end_y)
	{
		x = mm->start_x - 1;
		while (++x <= mm->end_x)
		{
			mm->draw_mi_x = ((double)x - mm->start_x);
			mm->draw_mi_y = ((double)y - mm->start_y);
			if (x >= 0 && x < m->m_width && y >= 0 && y < m->m_height)
			{
				if (m->coord[y][x] == '0')
					draw_block(mm->draw_mi_x * TILE, \
					mm->draw_mi_y * TILE, TILE, BL);
				else
					draw_block(mm->draw_mi_x * TILE, \
					mm->draw_mi_y * TILE, TILE - 1, GR);
			}
			else
				draw_block(mm->draw_mi_x * TILE, \
				mm->draw_mi_y * TILE, TILE - 1, GR);
		}
	}
}
