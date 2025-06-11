#include "../includes/cub.h"

int	close_window(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	free_pointer(g->win);
	free_pointer(g->mlx);
	return (0);
}
