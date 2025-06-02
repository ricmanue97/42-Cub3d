
#include "../includes/cube.h"

// Fix angle to stay within 0-359 degrees
float FixAng(float a)
{
	if (a > 359)
		a -= 360;
	if (a < 0)
		a += 360;
	return a;
}
/*


float	deg_to_rad(float a)
{
	return((a) * PI / 180.0);
}

// Cast rays and draw lines on 2D map for debug view
void draw_ray(t_game *g, float ra)
{
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	float	i;

	rx = g->player->pos_x;
	ry = g->player->pos_y;
	xo = cos(deg_to_rad(ra));
	yo = -sin(deg_to_rad(ra));
	i = 0;
	while (i < 10000)
	{
		if (rx >= 0 && rx < cube()->map->map_width && ry >= 0 && \
		ry < cube()->map->map_height)
			break;
		img_pixel_put(g->cube_image, rx, ry, 0x00FF00); // green
		rx += xo;
		ry += yo;
		i++;
	}
}

// Calculate the player's angle (pa) in degrees
float	get_player_angle(t_player *player)
{
	float angle = atan2(-player->dir_y, player->dir_x) * (180.0 / PI); // Convert radians to degrees
	if (angle < 0)
		angle += 360; // Ensure the angle is within 0-359 degrees
	return angle;
}

void draw_rays(t_game *g)
{
	int		r;
	float	ra;

	r = 0;
	ra = get_player_angle(cube()->player);
	while (r < 60)
	{
		draw_ray(g, ra);
		ra = FixAng(ra - 1);
		r++;
	}
} */

void draw_block(t_game *g, int x, int y, int w, int h, int color)
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

// Draw the player as a small square
 void	draw_player(t_game *g)
{
	draw_block(g, g->player->pos_x - 1.4f, g->player->pos_y - 1.4f, 4, 4, 0xFFFF00);
}

void draw_map(t_game *g)
{
	int y;
	int x;
	int color;

	y = -1;
	while (++y < g->map->map_height)
	{
		x = -1;
		while (g->map->coordinates[y][++x] != '\0')
			draw_block(g, x * tile_size, y * tile_size, tile_size, tile_size, 0x000000);
	}
	y = -1;
	while (++y <= g->map->map_height)
	{
		x = -1;
		while (g->map->coordinates[y][++x] != '\0')
		{
			if(g->map->coordinates[y][x] > '0')
				color = 0x999999;
			else
				color = 0x000000;
			draw_block(g, x * tile_size, y * tile_size, tile_size - 1, tile_size - 1, color);
		}
	}
}

int	frame_render()
{
	int		x;
	t_frame	frame;
	t_image	*img;

	img = cube()->cube_image;
	img->image = mlx_new_image(cube()->mlx, scWIDTH, scHEIGHT);
	img->addr = mlx_get_data_addr(img->image, &img->bpp, &img->size_line, \
	&img->endian);
	x = -1;
	while(++x < scWIDTH)
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
	//draw_rays(cube());
	mlx_clear_window(cube()->mlx, cube()->win);
	mlx_put_image_to_window(cube()->mlx, cube()->win, img->image, 0, 0);
	mlx_destroy_image(cube()->mlx, img->image);
	return (0);
}
