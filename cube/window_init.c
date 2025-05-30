/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:01:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/05/30 14:14:42 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube.h"

int	window_init(void)
{
	cube()->mlx = mlx_init();
	if (!cube()->mlx)
		return (UNSUCCESS);
	cube()->win = mlx_new_window(cube()->mlx, scWIDTH, scHEIGHT, "CONTINENTE");
	if (!cube()->win)
		return (UNSUCCESS);
	else
		return (SUCCESS);
}

