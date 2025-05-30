
#include "../includes/cube.h"

void	sprite_pixel_put(t_frame *f, t_sprite *s)
{
	t_player	*p;
	int			pitch;
	int			y;

	p = cube()->player;
	if (f->side)
		s->wall_hit = p->pos_y + f->wall_distance * f->ray_dir_y;
	else
		s->wall_hit = p->pos_x + f->wall_distance * f->ray_dir_x;
	s->wall_hit -= floor(s->wall_hit);
	s->texture_x = (int)(s->wall_hit * (double)(tileWIDTH));
	if (f->side = 0 && f->ray_dir_x > 0)
		s->texture_x = tileWIDTH - s->texture_x - 1;
	if (f->side = 1 && f->ray_dir_y < 0)
		s->texture_x = tileWIDTH - s->texture_x - 1;
	s->step = 1.0 * tileHEIGHT / f->line_height;
	pitch = 100;
	s->texture_pos = (f->draw_start - pitch - scHEIGHT / 2 + \
	f->line_height / 2) * s->step;
}

int	wall_direction(t_frame *f)
{
	if (f->side == 0)
	{
		if (f->ray_dir_x > 0)
			return (1);
		else
			return (3);
	}
	else
	{
		if (f->ray_dir_y > 0)
			return (2);
		else
			return (0);
	}
}

void	line_draw(t_frame *f, t_image *sprites, int x)
{
	t_sprite		s;
	int				y;
	int				w_orientation;
	unsigned int	color;

	w_orientation = wall_direction(f);
	sprite_pixel_put(f, &s);
	y = f->draw_start - 1;
	while (++y < f->draw_end)
	{
		s.texture_y = (int)s.texture_pos & (tileHEIGHT - 1);
		s.texture_pos += s.step;
		color = get_color(sprites[w_orientation], tileHEIGHT * \
		s.texture_y, s.texture_x);

	}
}

void	line_height(t_frame *f)
{
	int	pitch;

	pitch = 100;
	if (f->side == 0)
		f->wall_distance = f->side_dist_x - f->delta_dist_x;
	else
		f->wall_distance = f->side_dist_y - f->delta_dist_y;
	f->line_height = (int)(scHEIGHT / f->wall_distance);
	f->draw_start = -f->line_height / 2 + scHEIGHT / 2 + pitch;
	if(f->draw_start < 0)
		f->draw_start = 0;
	f->draw_end = f->line_height / 2 + scHEIGHT / 2 + pitch;
	if (f->draw_end >= scHEIGHT)
		f->draw_end = scHEIGHT - 1;
}

void	perform_dda(t_frame *f)
{
	while (CONTINUE)
	{
		if (f->side_dist_x < f->side_dist_y)
		{
			f->side_dist_x += f->delta_dist_x;
			f->map_x += f->step_x;
			f->side = 0;
		}
		else
		{
			f->side_dist_y += f->side_dist_y;
			f->map_y += f->step_y;
			f->side = 1;
		}
		if ((cube()->map->coordinates)[f->map_y][f->map_x] > 0)
			break ;
	}
}

void	side_dist(t_frame *f)
{
	t_player *p;

	p = cube()->player;
	if(f->ray_dir_x < 0)
	{
		f->step_x = -1;
		f->side_dist_x = (p->pos_x - f->map_x) * f->delta_dist_x;
	}
	else
	{
		f->step_x = 1;
		f->side_dist_x = (f->map_x + 1.0 - p->pos_x) * f->delta_dist_x;
	}
	if(f->ray_dir_y < 0)
	{
		f->step_y = -1;
		f->side_dist_y = (p->pos_y - f->map_y) * f->delta_dist_y;
	}
	else
	{
		f->step_y = 1;
		f->side_dist_y = (f->map_y + 1.0 - p->pos_y) * f->delta_dist_y;
	}
}

void	player_dist_axis(t_frame *f)
{
	t_player *p;

	p = cube()->player;
	f->map_x = (int)p->pos_x;
	f->map_y = (int)p->pos_y;
	if (f->ray_dir_x == 0)
		f->delta_dist_x = DBL_MAX;
	else
		f->delta_dist_x = fabs(1.0 / f->ray_dir_x);
	if (f->ray_dir_y == 0)
		f->delta_dist_y = DBL_MAX;
	else
		f->delta_dist_y = fabs(1.0 / f->ray_dir_y);
}

void	ray_pos_dir(t_frame *f, int x)
{
	t_player *p;

	p = cube()->player;
	f->camera_x = 2 * x / (double)scWIDTH - 1;
	f->ray_dir_x = p->dir_x + p->plane_x * f->camera_x;
	f->ray_dir_y = p->dir_y + p->plane_y * f->camera_x;
}

int	game_loop()
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
		line_draw(&frame, cube()->sprite_array, x);
	}
	draw_map(cube());
	draw_player(cube());
	draw_rays(cube());
	mlx_clear_window(cube()->mlx, cube()->win);
	mlx_put_image_to_window(cube()->mlx, cube()->win, img->image, 0, 0);
	mlx_destroy_image(cube()->mlx, img->image);

}
