/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:54:34 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/14 11:34:34 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

unsigned int	get_color(t_image *img, int x, int y)
{
	char	*pixel;
	int		bytes_per_pixel;

	bytes_per_pixel = img->bpp / 8;
	pixel = img->addr + (y * img->size_line + x * bytes_per_pixel);
	return (*(unsigned int *)pixel);
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCWIDTH || y < 0 || y >= SCHEIGHT)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_block(int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			img_pixel_put(cub()->cub_image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
