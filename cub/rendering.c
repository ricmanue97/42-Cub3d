
#include "../includes/cub.h"

void draw_cart(t_image *cart, t_image *cub_image)
{
	int				x_screen;
	int				y_screen;
	int				x_cart;
	int				y_cart;
	unsigned int	color;

	x_screen = (SCWIDTH - cart->width) / 2;
	x_cart = -1;
	while (++x_cart < cart->width)
	{
		y_cart = -1;
		y_screen = SCHEIGHT - cart->height;
		while (++y_cart < cart->height)
		{
			color = get_color(cart, x_cart, y_cart);
			if (color != 4278190080)
				img_pixel_put(cub_image, x_screen, y_screen, color);
			y_screen++;
		}
		x_screen++;
	}
}

int	frame_render(t_image *img)
{
	int		x;
	t_frame	frame;

	img->image = mlx_new_image(cub()->mlx, SCWIDTH, SCHEIGHT);
	img->addr = mlx_get_data_addr(img->image, &img->bpp, &img->size_line, \
	&img->endian);
	x = -1;
	mov_calculation(cub()->player, cub()->keys);
	while(++x < SCWIDTH)
	{
		ray_pos_dir(&frame, x);
		player_dist_axis(&frame);
		side_dist(&frame);
		perform_dda(&frame);
		line_height(&frame);
		draw_line(img, &frame, cub()->sprite_array, x);
	}
	draw_cart(cub()->cart_image, cub()->cub_image);
	draw_map(cub()->map, cub()->mini_map, cub()->player);
	mlx_clear_window(cub()->mlx, cub()->win);
	mlx_put_image_to_window(cub()->mlx, cub()->win, img->image, 0, 0);
	mlx_destroy_image(cub()->mlx, img->image);
	return (SUCCESS);
}
