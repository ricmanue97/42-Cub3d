
#include "../includes/cube.h"

void	draw_floor_ceiling(t_image *img, t_frame *f, int x)
{
	unsigned int	ceiling;
	unsigned int	floor;
	int				y;

	ceiling = 0x808080;
	floor = 0x3A1F04;
	y = - 1;
	while (++y < f->draw_start - 1)
		img_pixel_put(img, x, y, ceiling);
	y = f->draw_end;
	while (++y < SCHEIGHT)
		img_pixel_put(img, x, y, floor);
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
	t->texture_x = (int)(t->wall_hit * (double)(TEX_WIDTH));
	if (f->side == 0 && f->ray_dir_x > 0)
		t->texture_x = TEX_WIDTH - t->texture_x - 1;
	if (f->side == 1 && f->ray_dir_y < 0)
		t->texture_x = TEX_WIDTH - t->texture_x - 1;
	t->step = 1.0 * TEX_HEIGHT / f->line_height;
	pitch = 100;
	t->texture_pos = (f->draw_start - pitch - SCHEIGHT / 2 + \
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

void	draw_line(t_image *img, t_frame *f, t_image sprites[4], int x)
{
	t_texture		t;
	int				y;
	int				w_orientation;
	unsigned int	color;

	w_orientation = wall_direction(f);
	wall_hit(f, &t);
	y = f->draw_start - 1;
	draw_floor_ceiling(img, f, x);
	while (++y < f->draw_end)
	{
		t.texture_y = (int)t.texture_pos & (TEX_HEIGHT - 1);
		t.texture_pos += t.step;
		color = get_color(&(sprites[w_orientation]), t.texture_x, t.texture_y);
		img_pixel_put(img, x, y, color);
	}
}
