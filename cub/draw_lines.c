/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:28 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/04 16:41:08 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	draw_floor_ceiling(t_image *img, t_frame *f, int x)
{
	unsigned int	ceiling;
	unsigned int	floor;
	int				y;

	ceiling = cub()->map->c;
	floor = cub()->map->f;
	y = -1;
	while (++y < f->draw_start - 1)
		img_pixel_put(img, x, y, ceiling);
	y = f->draw_end;
	while (++y < SCHEIGHT)
		img_pixel_put(img, x, y, floor);
}

void	pov_calculations(t_frame *f, t_texture *t)
{
	t_player	*p;
	int			pitch;

	p = cub()->player;
	if (f->side == 0)
		t->wall_hit = p->pos_y + f->wall_dist * f->ray_dir_y;
	else
		t->wall_hit = p->pos_x + f->wall_dist * f->ray_dir_x;
	t->wall_hit -= floor(t->wall_hit);
	t->texture_x = (int)(t->wall_hit * (double)(TEX_WIDTH));
	if (f->side == 0 && f->ray_dir_x > 0)
		t->texture_x = TEX_WIDTH - t->texture_x - 1;
	if (f->side == 1 && f->ray_dir_y < 0)
		t->texture_x = TEX_WIDTH - t->texture_x - 1;
	t->step = 1.0 * TEX_HEIGHT / f->line_height;
	pitch = 100;
	t->texture_pos = (f->draw_start - pitch - SCHEIGHT / 2 + \
	f->line_height / 2) * t->step;
}

int	wall_direction(t_frame *f)
{
	if (f->side == 0)
	{
		if (f->ray_dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (f->ray_dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	draw_line(t_image *img, t_frame *f, t_image sprites[4], int x)
{
	t_texture		t;
	int				y;
	int				wall_direct;
	unsigned int	color;

	wall_direct = wall_direction(f);
	pov_calculations(f, &t);
	y = f->draw_start - 1;
	draw_floor_ceiling(img, f, x);
	while (++y < f->draw_end)
	{
		t.texture_y = (int)t.texture_pos & (TEX_HEIGHT - 1);
		t.texture_pos += t.step;
		color = get_color(&(sprites[wall_direct]), t.texture_x, t.texture_y);
		img_pixel_put(img, x, y, color);
	}
}
