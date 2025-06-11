
#include "../includes/cub.h"

int	main(int ac, char **av)
{
	t_game *g;

	if (ac == 2)
	{
		g = cub();
		var_init(g);
		ft_args_validation(av);
		ft_check_map(av);
		player_direction(g->player);
		window_init(g);
		sprites_init(g->sprite_array);
		cart_init(g->cart_image);
		mlx_hook(g->win, 17, NoEventMask, exit_cross, g);
		mlx_hook(g->win, 2, KeyPressMask, key_press, g->keys);
		mlx_hook(g->win, 3, KeyReleaseMask, key_release, g->keys);
		mlx_loop_hook(g->mlx, frame_render, g->cub_image);
		mlx_loop(g->mlx);
	}
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	}
	return (0);
}
