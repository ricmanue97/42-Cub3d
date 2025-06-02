
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

	if (x < 0 || x >= scWIDTH || y < 0 || y >= scHEIGHT)
		return;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
