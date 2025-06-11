#include "../includes/cub.h"

int	close_window(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	// TODO free_stuff;
	exit(0);
	return (0);
}
