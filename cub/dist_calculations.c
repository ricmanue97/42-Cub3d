/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:20 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 15:52:30 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	perform_dda(t_frame *f)
{
	while (CONTINUE)
	{
		if (f->side_dist_x < f->side_dist_y)
		{
			f->side_dist_x += f->delta_dist_x;
			f->map_x += f->step_x;
			f->side = 0;
		}
		else
		{
			f->side_dist_y += f->delta_dist_y;
			f->map_y += f->step_y;
			f->side = 1;
		}
		if ((cub()->map->coord)[f->map_y][f->map_x] > '0')
			break ;
	}
}

void	side_dist(t_frame *f)
{
	t_player	*p;

	p = cub()->player;
	if (f->ray_dir_x < 0)
	{
		f->step_x = -1;
		f->side_dist_x = (p->pos_x - f->map_x) * f->delta_dist_x;
	}
	else
	{
		f->step_x = 1;
		f->side_dist_x = (f->map_x + 1.0 - p->pos_x) * f->delta_dist_x;
	}
	if (f->ray_dir_y < 0)
	{
		f->step_y = -1;
		f->side_dist_y = (p->pos_y - f->map_y) * f->delta_dist_y;
	}
	else
	{
		f->step_y = 1;
		f->side_dist_y = (f->map_y + 1.0 - p->pos_y) * f->delta_dist_y;
	}
}

void	player_dist_axis(t_frame *f)
{
	t_player	*p;

	p = cub()->player;
	f->map_x = (int)p->pos_x;
	f->map_y = (int)p->pos_y;
	if (f->ray_dir_x == 0)
		f->delta_dist_x = DBL_MAX;
	else
		f->delta_dist_x = fabs(1 / f->ray_dir_x);
	if (f->ray_dir_y == 0)
		f->delta_dist_y = DBL_MAX;
	else
		f->delta_dist_y = fabs(1 / f->ray_dir_y);
}

void	ray_pos_dir(t_frame *f, int x)
{
	t_player	*p;

	p = cub()->player;
	f->camera_x = 2 * (double)x / (double)SCWIDTH - 1;
	f->ray_dir_x = p->dir_x + p->plane_x * f->camera_x;
	f->ray_dir_y = p->dir_y + p->plane_y * f->camera_x;
}
