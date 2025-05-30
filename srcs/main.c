

#include "../includes/cube.h"

void	var_init()
{
			//definir a direcao do player aqui
}

int	close_window(t_game *g)
{
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game *g;

	if (ac == 2)
	{
		ft_args_validation(av);
		var_init();
		window_init();
		g = cube();
		mlx_hook(g->win, 2, 1L<<0, key_press, g->player);
		mlx_hook(g->win, 17, 0, close_window, g);
		mlx_loop(g->mlx);
	}
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	}
	return (0);
}
