/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:01:52 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 15:59:36 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	window_init(t_game *g)
{
	g->mlx = mlx_init();
	if (!g->mlx)
		error_to_exit(g, MLX_ERR);
	if (g->map->m_width <= 20 && g->map->m_height <= 20)
		g->win = mlx_new_window(g->mlx, SCWIDTH, SCHEIGHT, "Meu Super");
	else if (g->map->m_width < 35 && g->map->m_height < 35)
		g->win = mlx_new_window(g->mlx, SCWIDTH, SCHEIGHT, \
		"CONTINENTE Bom Dia");
	else if (g->map->m_width < 48 && g->map->m_height < 48)
		g->win = mlx_new_window(g->mlx, SCWIDTH, SCHEIGHT, "CONTINENTE Modelo");
	else
		g->win = mlx_new_window(g->mlx, SCWIDTH, SCHEIGHT, "CONTINENTE");
	if (!g->win)
		error_to_exit(g, MLX_ERR);
	return (SUCCESS);
}
