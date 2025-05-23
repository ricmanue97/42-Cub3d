

#include "../includes/cube.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_map		map;
	t_player	player;


	if (ac == 2)
	{
		ft_args_validation(av);
	}
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	}
	return (0);
}
