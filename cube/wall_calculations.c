#include "../includes/cube.h"

int	is_wall(double x, double y)
{
	int mx;
	int my;

	mx = (int)(x);
	my = (int)(y);
	if (mx >= 0 && mx < cube()->map->map_width && my >= 0 && \
	my < cube()->map->map_height)
		return (cube()->map->coord[my][mx]);
	return (1);
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
