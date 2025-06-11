/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:01:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/11 11:25:31 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	window_init(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		error_to_exit(g, MLX_ERR);
	g->win = mlx_new_window(g->mlx, SCWIDTH, SCHEIGHT, "CONTINENTE");
	if (!g->win)
		error_to_exit(g, MLX_ERR);
	else
		return (SUCCESS);
}

