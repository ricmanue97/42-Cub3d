/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_to_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:55:19 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/24 13:19:41 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	exit_cub(t_game *g, int error)
{
	free_cub(g);
	close_window(g);
	exit(error);
}

void	error_to_exit(t_game *g, int error)
{
	if (error == MLX_ERR)
		ft_putstr_fd("Malloc Error", 2, YES);
	if (error == WIND_ERR)
		ft_putstr_fd("Window initialization Error", 2, YES);
	exit_cub(g, error);
}

void	img_error_to_exit(t_image *i, int error)
{
	char	*error_msg;

	error_msg = ft_strjoin(i->path, " - initialization Error");
	ft_putstr_fd(error_msg, 2, YES);
	free_pointer((void *)error_msg);
	exit_cub(cub(), error);
}

int	exit_cross(t_game *g)
{
	exit_cub(g, SUCCESS);
	return (SUCCESS);
}
