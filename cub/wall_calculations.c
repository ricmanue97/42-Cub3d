#include "../includes/cube.h"

int	is_wall(double x, double y, double move_speed)
{
	int		absx;
	int		absy;
	char	**coord;

	absx = (int)(x - move_speed);
	absy = (int)(y - move_speed);
	coord = cube()->map->coord;
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	absx = (int)(x + move_speed);
	absy = (int)(y + move_speed);
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	absx = (int)(x + move_speed);
	absy = (int)(y - move_speed);
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	absx = (int)(x - move_speed);
	absy = (int)(y + move_speed);
	if (coord[absy][absx] != '0')
		return (UNSUCCESS);
	return (SUCCESS);
}

void	line_height(t_frame *f)
{
	int	pitch;

	pitch = 100;
	if (f->side == 0)
		f->wall_dist = f->side_dist_x - f->delta_dist_x;
	else
		f->wall_dist = f->side_dist_y - f->delta_dist_y;
	f->line_height = (int)(SCHEIGHT / f->wall_dist);
	f->draw_start = -f->line_height / 2 + SCHEIGHT / 2 + pitch;
	if(f->draw_start < 0)
		f->draw_start = 0;
	f->draw_end = f->line_height / 2 + SCHEIGHT / 2 + pitch;
	if (f->draw_end >= SCHEIGHT)
		f->draw_end = SCHEIGHT - 1;
}
