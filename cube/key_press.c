
#include "../includes/cube.h"

void	rotate(double rot_speed, t_player *p)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
	p->dir_y = old_dir_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
	old_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
	p->plane_y = old_plane_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
}

void	change_p_pos(t_player *p, double new_x, double new_y)
{
	p->pos_x = new_x;
	p->pos_y = new_y;
}

void	move_side(t_player *p, double new_x, double new_y, double move_speed)
{
	new_x = p->pos_x + p->dir_y * move_speed;
	new_y = p->pos_y - p->dir_x * move_speed;
	if (!is_wall(new_x, new_y))
		change_p_pos(p, new_x, new_y);
}

void	move_front_back(t_player *p, double new_x, double new_y, double move_speed)
{
	new_x = p->pos_x + p->dir_x * move_speed;
	new_y = p->pos_y + p->dir_y * move_speed;
	if (!is_wall(new_x, new_y))
		change_p_pos(p, new_x, new_y);
}

int key_press(int key, t_player *p)
{
	double	new_x;
	double	new_y;
	double	move_speed;
	double	rot_speed;

	frame_render();
	move_speed = 1;
	rot_speed = 0.7;
	if (key == ESC)
		close_window(cube());
	if (key == ARROW_LEFT)
		rotate(rot_speed, p);
	if (key == ARROW_RIGHT)
		rotate(-rot_speed, p);
	if (key == 'w')
		move_front_back(p, new_x, new_y, move_speed);
	if (key == 's')
		move_front_back(p, new_x, new_y, -move_speed);
	if (key == 'a')
		move_side(p, new_x, new_y, move_speed);
	if (key == 'd')
		move_side(p, new_x, new_y, -move_speed);
	return 0;
}
