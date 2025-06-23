/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:14 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 15:09:47 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

float	fix_ang(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return (a);
}

float	deg_to_rad(float a)
{
	return ((a) * PI / 180.0);
}

float	get_player_angle(t_player *player)
{
	float	angle;

	angle = atan2(-player->dir_y, player->dir_x) * (180.0 / PI) + 34;
	if (angle < 0)
		angle += 360;
	return (angle);
}
