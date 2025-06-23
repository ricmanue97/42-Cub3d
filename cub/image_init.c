/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:38 by dicarval          #+#    #+#             */
/*   Updated: 2025/06/23 14:54:39 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	image_init(void *mlx, t_image *i)
{
	i->image = mlx_xpm_file_to_image(mlx, i->path, &i->width, &i->height);
	if (!i->image)
		img_error_to_exit(i, IMAGE_ERR);
	i->addr = mlx_get_data_addr(i->image, &i->bpp, &i->size_line, \
	&i->endian);
}

void	sprites_init(t_image img[4])
{
	t_image	*texture;
	int		i;

	i = -1;
	while (++i < 4)
	{
		texture = &img[i];
		image_init(cub()->mlx, texture);
	}
}

void	cart_init(t_image *cart)
{
	cart->path = "./shopping_cart.xpm";
	image_init(cub()->mlx, cart);
}
