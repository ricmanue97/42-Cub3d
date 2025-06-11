
#include "../includes/cube.h"

int	main(int ac, char **av)
{
	t_game *g;

	(void)ac;
	if (ac == 2)
	{
		ft_args_validation(av);
		g = cube();
		var_init(g);
		ft_args_validation(av);
		var_init();
		window_init();
		sprites_init(g->sprite_array);
		cart_init(g->cart_image);
		mlx_hook(g->win, 17, NoEventMask, close_window, g);
		mlx_hook(g->win, 2, KeyPressMask, key_press, g->keys);
		mlx_hook(g->win, 3, KeyReleaseMask, key_release, g->keys);
		mlx_loop_hook(g->mlx, frame_render, g->cube_image);
		mlx_loop(g->mlx);
	}
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	}
	return (0);
}
