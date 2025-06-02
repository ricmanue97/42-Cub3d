#include "../includes/cube.h"

int	is_wall(double x, double y)
{
	int mx;
	int my;

	mx = (int)(x);
	my = (int)(y);
	if (mx >= 0 && mx < cube()->map->map_width && my >= 0 && \
	my < cube()->map->map_height)
		return (cube()->map->coordinates[my][mx]);
	return (1);
}

void	wall_hit(t_frame *f, t_texture *t)
{
	t_player	*p;
	int			pitch;

	p = cube()->player;
	if (f->side == 0)
		t->wall_hit = p->pos_y + f->wall_dist * f->ray_dir_y;
	else
		t->wall_hit = p->pos_x + f->wall_dist * f->ray_dir_x;
	t->wall_hit -= floor(t->wall_hit);
	t->texture_x = (int)(t->wall_hit * (double)(textWIDTH));
	if (f->side == 0 && f->ray_dir_x > 0)
		t->texture_x = textWIDTH - t->texture_x - 1;
	if (f->side == 1 && f->ray_dir_y < 0)
		t->texture_x = textWIDTH - t->texture_x - 1;
	t->step = 1.0 * textHEIGHT / f->line_height;
	pitch = 100;
	t->texture_pos = (f->draw_start - pitch - scHEIGHT / 2 + \
	f->line_height / 2) * t->step;
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
	t_texture		t;
	int				y;
	int				w_orientation;
	unsigned int	color;

	w_orientation = wall_direction(f);
	wall_hit(f, &t);
	y = f->draw_start - 1;
	(void)sprites; ///to test the program
	while (++y < f->draw_end)
	{
		t.texture_y = (int)t.texture_pos & (textHEIGHT - 1);
		t.texture_pos += t.step;
		/* color = get_color(sprites[w_orientation], tileHEIGHT * \
		t.texture_y, t.texture_x); */
		color = 0x00FF00;
		img_pixel_put(img, x, y, color);
	}
}

void	line_height(t_frame *f)
{
	int	pitch;

	pitch = 100;
	if (f->side == 0)
		f->wall_dist = f->side_dist_x - f->delta_dist_x;
	else
		f->wall_dist = f->side_dist_y - f->delta_dist_y;
	f->line_height = (int)(scHEIGHT / f->wall_dist);
	f->draw_start = -f->line_height / 2 + scHEIGHT / 2 + pitch;
	if(f->draw_start < 0)
		f->draw_start = 0;
	f->draw_end = f->line_height / 2 + scHEIGHT / 2 + pitch;
	if (f->draw_end >= scHEIGHT)
		f->draw_end = scHEIGHT - 1;
}
