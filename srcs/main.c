

#include "../includes/cube.h"

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
	/* if (ac == 2)
	{
		ft_args_validation(av); */
		var_init();
		window_init();
		copy_world_map_to_coord(&cube()->map->coord, 6, 7);
		frame_render();
		g = cube();
		mlx_hook(g->win, 2, 1L<<0, key_press, g->player);
		mlx_hook(g->win, 17, 0, close_window, g);
		mlx_loop(g->mlx);
	/* }
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	} */
	return (0);
}
