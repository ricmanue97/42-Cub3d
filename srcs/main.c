

#include "../includes/cube.h"

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


/* #include "../includes/cube.h"

char worldMap[7][6]=
{
  {'1','1','1','1','1', '\0'},
  {'1','0','0','0','1', '\0'},
  {'1','0','0','0','1', '\0'},
  {'1','0','0','0','1', '\0'},
  {'1','0','0','0','1', '\0'},
  {'1','0','0','0','1', '\0'},
  {'1','1','1','1','1', '\0'}
};

void	var_init()
{
	cube()->player = malloc(sizeof(t_player));
			//TODO: calcular player position
	cube()->player->pos_x = 3;
	cube()->player->pos_y = 3;
			//TODO: calcular player direction
	cube()->player->dir_x = -1.0;
	cube()->player->dir_y = 0.0;
	cube()->player->plane_x = 0.0;
	cube()->player->plane_y = 0.66;
	cube()->map = malloc(sizeof(t_map));
			//TODO: calcular altura e largura do mapa
	cube()->map->map_height = 7;
	cube()->map->map_width = 6;
	cube()->map->coord = NULL;
	cube()->cube_image = malloc(sizeof(t_image));
}

void	copy_world_map_to_coord(char ***coord, int width, int height)
{
    int i;

    *coord = malloc(height * sizeof(char *));
    if (!*coord)
        exit(EXIT_FAILURE); // Handle allocation failure
    for (i = 0; i < height; i++)
    {
        (*coord)[i] = malloc(width * sizeof(char));
        if (!(*coord)[i])
            exit(EXIT_FAILURE); // Handle allocation failure
        memcpy((*coord)[i], worldMap[i], width);
    }
}

int	main(int ac, char **av)
{
	t_game *g;

	(void)av;
	(void)ac;
	if (ac == 2)
	{
		ft_args_validation(av);
		var_init();
		window_init();
		copy_world_map_to_coord(&cube()->map->coord, 6, 7);
		frame_render();
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
} */