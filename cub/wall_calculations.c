/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_calculations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:42:57 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/04 16:58:50 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_wall(double x, double y, double move_speed)
{
	int		absx;
	int		absy;
	char	**coord;

	absx = (int)(x - move_speed * 3);
	absy = (int)(y - move_speed * 3);
	coord = cub()->map->coord;
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	absx = (int)(x + move_speed * 3);
	absy = (int)(y + move_speed * 3);
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	absx = (int)(x + move_speed * 3);
	absy = (int)(y - move_speed * 3);
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	absx = (int)(x - move_speed * 3);
	absy = (int)(y + move_speed * 3);
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	return (SUCCESS);
}

void	line_height(t_frame *f)
{
	int	pitch;

	pitch = 100;
	if (f->side == 0)
		f->wall_dist = f->side_dist_x - f->delta_dist_x;
	else
		f->wall_dist = f->side_dist_y - f->delta_dist_y;
	f->line_height = (int)(SCHEIGHT / f->wall_dist);
	f->draw_start = -f->line_height / 2 + SCHEIGHT / 2 + pitch;
	if (f->draw_start < 0)
		f->draw_start = 0;
	f->draw_end = f->line_height / 2 + SCHEIGHT / 2 + pitch;
	if (f->draw_end >= SCHEIGHT)
		f->draw_end = SCHEIGHT - 1;
}
