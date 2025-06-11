/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:01:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/11 10:44:23 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	window_init(void)
{
	cub()->mlx = mlx_init();
	if (!cub()->mlx)
		return (UNSUCCESS);
	cub()->win = mlx_new_window(cub()->mlx, SCWIDTH, SCHEIGHT, "CONTINENTE");
	if (!cub()->win)
		return (UNSUCCESS);
	else
		return (SUCCESS);
}

