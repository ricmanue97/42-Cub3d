/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:39:08 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/29 17:52:22 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

void	wall_direction(t_frame *frame)
{

	if (frame->side == 0)
	{
		if (frame->ray_dir_x > 0)
			frame->wall_direction = 2;
		else
			frame->wall_direction = 4;
	}
	else
	{
		if (frame->ray_dir_y > 0)
			frame->wall_direction = 3;
		else
			frame->wall_direction = 1;
	}
}

void	wall_draw(t_frame *frame)
{
	wall_direction(frame);
}

void	line_height(t_frame *frame)
{
	int	pitch;

	pitch = 100;
	if (frame->side == 0)
		frame->wall_distance = frame->side_dist_x - frame->delta_dist_x;
	else
		frame->wall_distance = frame->side_dist_y - frame->delta_dist_y;
	frame->line_height = (int)(scHEIGHT / frame->wall_distance);
	frame->draw_start = -frame->line_height / 2 + scHEIGHT / 2 + pitch;
	if(frame->draw_start < 0)
		frame->draw_start = 0;
	frame->draw_end = frame->line_height / 2 + scHEIGHT / 2 + pitch;
	if (frame->draw_end >= scHEIGHT)
		frame->draw_end = scHEIGHT - 1;
}

void	perform_dda(t_frame *frame)
{
	while (CONTINUE)
	{
		if (frame->side_dist_x < frame->side_dist_y)
		{
			frame->side_dist_x += frame->delta_dist_x;
			frame->map_x += frame->step_x;
			frame->side = 0;
		}
		else
		{
			frame->side_dist_y += frame->side_dist_y;
			frame->map_y += frame->step_y;
			frame->side = 1;
		}
		if ((cube()->map->coordinates)[frame->map_y][frame->map_x] > 0)
			break ;
	}
}

void	side_dist(t_frame *frame)
{
	t_player *player;

	player = cube()->player;
	if(frame->ray_dir_x < 0)
	{
		frame->step_x = -1;
		frame->side_dist_x = (player->pos_x - frame->map_x) \
		* frame->delta_dist_x;
	}
	else
	{
		frame->step_x = 1;
		frame->side_dist_x = (frame->map_x + 1.0 - player->pos_x) \
		* frame->delta_dist_x;
	}
	if(frame->ray_dir_y < 0)
	{
		frame->step_y = -1;
		frame->side_dist_y = (player->pos_y - frame->map_y) \
		* frame->delta_dist_y;
	}
	else
	{
		frame->step_y = 1;
		frame->side_dist_y = (frame->map_y + 1.0 - player->pos_y) \
		* frame->delta_dist_y;
	}
}

void	player_dist_axis(t_frame *frame)
{
	t_player *player;

	player = cube()->player;
	frame->map_x = (int)player->pos_x;
	frame->map_y = (int)player->pos_y;
	if (frame->ray_dir_x == 0)
		frame->delta_dist_x = DBL_MAX;
	else
		frame->delta_dist_x = fabs(1.0 / frame->ray_dir_x);
	if (frame->ray_dir_y == 0)
		frame->delta_dist_y = DBL_MAX;
	else
		frame->delta_dist_y = fabs(1.0 / frame->ray_dir_y);
}

void	ray_pos_dir(t_frame *frame, int i)
{
	t_player *player;

	player = cube()->player;
	frame->camera_x = 2 * i / (double)scWIDTH - 1;
	frame->ray_dir_x = player->dir_x + player->plane_x * frame->camera_x;
	frame->ray_dir_y = player->dir_y + player->plane_y * frame->camera_x;
}

int	game_loop()
{
	int		i;
	t_frame	frame;

	while(CONTINUE)
	{
		i = -1;
		while(++i < scWIDTH)
		{
			ray_pos_dir(&frame, i);
			player_dist_axis(&frame);
			side_dist(&frame);
			perform_dda(&frame);
			line_height(&frame);
			wall_draw(&frame);



		}
	}
}
