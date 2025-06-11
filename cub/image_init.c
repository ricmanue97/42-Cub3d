#include "../includes/cube.h"

void	image_init(void *mlx, t_image *i)
{
	i->image = mlx_xpm_file_to_image(mlx, i->path, &i->width, &i->height);
	if (!i->image)
	{
		perror("Error loading XPM file"); //exemplo
		return ;				//exemplo
	}
	i->addr = mlx_get_data_addr(i->image, &i->bpp, &i->size_line, \
	&i->endian);
}

void	sprites_init(t_image img[4])
{
	int	i;
	t_image	*p;

	img[0].path = "./North.xpm";
	img[1].path = "./East.xpm";
	img[2].path = "./South.xpm";
	img[3].path = "./West.xpm";
	i = -1;
	while (++i < 4)
	{
		p = &img[i];
		image_init(cube()->mlx, p);
	}
}

void	cart_init(t_image *cart)
{
	cart->path = "./shopping_cart.xpm";
	image_init(cube()->mlx, cart);
}
