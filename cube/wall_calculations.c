#include "../includes/cube.h"

int	is_wall(double x, double y)
{
	int mx;
	int my;

	mx = (int)(x) / tileWIDTH;
	my = (int)(y) / tileWIDTH;
	if (mx >= 0 && mx < cube()->map->map_width && my >= 0 && \
	my < cube()->map->map_height)
		return (0);
	return (1);
}

void	wall_hit(t_frame *f, t_sprite *s)
{
	t_player	*p;
	int			pitch;

	p = cube()->player;
	if (f->side)
		s->wall_hit = p->pos_y + f->wall_distance * f->ray_dir_y;
	else
		s->wall_hit = p->pos_x + f->wall_distance * f->ray_dir_x;
	s->wall_hit -= floor(s->wall_hit);
	s->texture_x = (int)(s->wall_hit * (double)(tileWIDTH));
	if (f->side == 0 && f->ray_dir_x > 0)
		s->texture_x = tileWIDTH - s->texture_x - 1;
	if (f->side == 1 && f->ray_dir_y < 0)
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

void	draw_line(t_image *img, t_frame *f, t_image *sprites, int x)
{
	t_sprite		s;
	int				y;
	int				w_orientation;
	unsigned int	color;

	w_orientation = wall_direction(f);
	wall_hit(f, &s);
	y = f->draw_start - 1;
	while (++y < f->draw_end)
	{
		s.texture_y = (int)s.texture_pos & (tileHEIGHT - 1);
		s.texture_pos += s.step;
		color = get_color(sprites[w_orientation], tileHEIGHT * \
		s.texture_y, s.texture_x);
		color = 0x00FF00;
		img_pixel_put(img, x, y, color);
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
