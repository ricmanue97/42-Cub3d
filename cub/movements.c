
#include "../includes/cub.h"

static void	rotate(double rot_speed, t_player *p)
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

static void	change_p_pos(t_player *p, double new_x, double new_y)
{
	p->pos_x = new_x;
	p->pos_y = new_y;
}

static void	move_side(t_player *p, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = p->pos_x + p->dir_y * move_speed;
	new_y = p->pos_y - p->dir_x * move_speed;
	if (is_wall(new_x, new_y, move_speed) == SUCCESS)
		change_p_pos(p, new_x, new_y);
}

static void	move_front_back(t_player *p, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = p->pos_x + p->dir_x * move_speed;
	new_y = p->pos_y + p->dir_y * move_speed;
	if (is_wall(new_x, new_y, move_speed) == SUCCESS)
		change_p_pos(p, new_x, new_y);
}

void	mov_calculation(t_player *p, t_key *k)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.03;
	rot_speed = 0.03;
	if (k->l_arrow)
		rotate(-rot_speed, p);
	if (k->r_arrow)
		rotate(rot_speed, p);
	if (k->w)
		move_front_back(p, move_speed);
	if (k->s)
		move_front_back(p, -move_speed);
	if (k->a)
		move_side(p, move_speed);
	if (k->d)
		move_side(p, -move_speed);
}
