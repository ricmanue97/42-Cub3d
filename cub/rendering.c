
#include "../includes/cube.h"

int	frame_render()
{
	int		x;
	t_frame	frame;
	t_image	*img;

	img = cube()->cube_image;
	img->image = mlx_new_image(cube()->mlx, SCWIDTH, SCHEIGHT);
	img->addr = mlx_get_data_addr(img->image, &img->bpp, &img->size_line, \
	&img->endian);
	x = -1;
	while(++x < SCWIDTH)
	{
		ray_pos_dir(&frame, x);
		player_dist_axis(&frame);
		side_dist(&frame);
		perform_dda(&frame);
		line_height(&frame);
		draw_line(img, &frame, cube()->sprite_array, x);
	}
	draw_map(cube());
	draw_player(cube());
	draw_rays(cube());
	mlx_clear_window(cube()->mlx, cube()->win);
	mlx_put_image_to_window(cube()->mlx, cube()->win, img->image, 0, 0);
	mlx_destroy_image(cube()->mlx, img->image);
	return (0);
}
