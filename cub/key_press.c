
#include "../includes/cube.h"

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
