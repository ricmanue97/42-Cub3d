
#include "../includes/cube.h"

unsigned int	get_color(t_image image, int x, int y)
{
	char	*pixel;
	int		bytes_per_pixel;

	bytes_per_pixel = image.bpp / 8;
	pixel = image.addr + (y * image.size_line + x * bytes_per_pixel);
	return *(unsigned int *)pixel;
}

void	img_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCWIDTH || y < 0 || y >= SCHEIGHT)
		return;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_block(t_game *g, int x, int y, int w, int h, int color)
{
	int i = 0;
	while (i < h)
	{
		int j = 0;
		while (j < w)
		{
			img_pixel_put(g->cube_image, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
