/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:42 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 14:54:43 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	key_release(int key, t_key *k)
{
	if (key == ARROW_LEFT)
		k->l_arrow = 0;
	if (key == ARROW_RIGHT)
		k->r_arrow = 0;
	if (key == 'w')
		k->w = 0;
	if (key == 's')
		k->s = 0;
	if (key == 'a')
		k->a = 0;
	if (key == 'd')
		k->d = 0;
	return (0);
}

int	key_press(int key, t_key *k)
{
	if (key == ESC)
		exit_cub(cub(), SUCCESS);
	if (key == ARROW_LEFT)
		k->l_arrow = 1;
	if (key == ARROW_RIGHT)
		k->r_arrow = 1;
	if (key == 'w')
		k->w = 1;
	if (key == 's')
		k->s = 1;
	if (key == 'a')
		k->a = 1;
	if (key == 'd')
		k->d = 1;
	return (0);
}
