
#include "../includes/cube.h"

/* int	key_press(int key, t_player *p)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.05;
	rot_speed = 0.05;
	if (key == ESC)
		close_window(cube());
	if (key == ARROW_LEFT)
		rotate(-rot_speed, p);
	if (key == ARROW_RIGHT)
		rotate(rot_speed, p);
	if (key == 'w')
		move_front_back(p, move_speed);
	if (key == 's')
		move_front_back(p, -move_speed);
	if (key == 'a')
		move_side(p, move_speed);
	if (key == 'd')
		move_side(p, -move_speed);
	frame_render(cube()->cube_image);
	return (0);
} */

int	key_release(int key, t_key *k)
{
	if (key == ARROW_LEFT)
		k->l_arrow = 0;
	if (key == ARROW_RIGHT)
		k->r_arrow = 0;
	if (key == 'w')
		k->w = 0;
	if (key == 's')
		k->s = 0;
	if (key == 'a')
		k->a = 0;
	if (key == 'd')
		k->d = 0;
	return (0);
}

int	key_press(int key, t_key *k)
{
	if (key == ESC)
		close_window(cube());
	if (key == ARROW_LEFT)
		k->l_arrow = 1;
	if (key == ARROW_RIGHT)
		k->r_arrow = 1;
	if (key == 'w')
		k->w = 1;
	if (key == 's')
		k->s = 1;
	if (key == 'a')
		k->a = 1;
	if (key == 'd')
		k->d = 1;
	return (0);
}
