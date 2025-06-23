/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:57 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 15:10:21 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	corners_stop(t_map *m, t_minimap *mm, int map_y, int map_x)
{
	if (mm->dir_x < 0 && map_y != (int)cub()->player->pos_y && \
	map_x != (int)cub()->player->pos_x)
	{
		if (mm->dir_y < 0 && \
		m->coord[map_y + 1][map_x] == '1' && m->coord[map_y][map_x + 1] == '1')
			return (STOP);
		if (mm->dir_y > 0 && \
		m->coord[map_y - 1][map_x] == '1' && m->coord[map_y][map_x + 1] == '1')
			return (STOP);
	}
	if (mm->dir_x > 0 && map_y != (int)cub()->player->pos_y && \
	map_x != (int)cub()->player->pos_x)
	{
		if (mm->dir_y < 0 && \
		m->coord[map_y + 1][map_x] == '1' && m->coord[map_y][map_x - 1] == '1')
			return (STOP);
		if (mm->dir_y > 0 && \
		m->coord[map_y - 1][map_x] == '1' && m->coord[map_y][map_x - 1] == '1')
			return (STOP);
	}
	return (CONTINUE);
}

void	draw_map(t_map *m, t_minimap *mm, t_player *p)
{
	mm->start_x = p->pos_x - mm->size;
	mm->start_y = p->pos_y - mm->size;
	mm->end_x = p->pos_x + mm->size;
	mm->end_y = p->pos_y + mm->size;
	if (m->m_height > 10 || m->m_width > 10)
	{
		draw_big_map(m, mm);
		draw_big_player(mm, p);
		draw_big_rays(m, mm, p);
	}
	else
	{
		draw_small_map(m);
		draw_small_player(p);
		draw_small_rays(m, mm, p);
	}
}
