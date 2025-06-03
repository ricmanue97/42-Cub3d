

#include "../includes/cube.h"

void	var_init()
{
			//definir a direcao do player aqui
}

int	main(int ac, char **av)
{
/* 	t_game		*g;
	t_map		*m;
	t_player	*p; */

	cube();
	cube()->map = malloc(sizeof(t_map));
	if (!cube()->map)
	{
		ft_putstr_fd("Error : malloc failed\n", STDERROR, YES);
		return (1);
	}
	ft_bzero(cube()->map, sizeof(t_map));
	cube()->cube_image = malloc(4 * sizeof(t_image));
	if (!cube()->cube_image)
	{
		ft_putstr_fd("Error : malloc failed\n", STDERROR, YES);
		return (1);
	}
ft_bzero(cube()->cube_image, 4 * sizeof(t_image));
	if (ac == 2)
	{
		ft_args_validation(av);
		printf("%s\n", cube()->sprite_array[0].path);
		printf("%s\n", cube()->sprite_array[1].path);
		printf("%s\n", cube()->sprite_array[2].path);
		printf("%s\n", cube()->sprite_array[3].path);
		printf("%06lX\n", cube()->map->C);
		printf("%06lX\n", cube()->map->F);
/* 		var_init();
		window_init();
		g = cube();
		mlx_hook(g->win, 2, 1L<<0, key_press, g->player);
		mlx_hook(g->win, 17, 0, close_window, g);
		mlx_loop(g->mlx); */
	}
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	}
	return (0);
}
