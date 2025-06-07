

#include "../includes/cube.h"

char worldMap[16][15]=
{
  {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','\0'},
  {'1','0','0','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','0','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','0','1','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','0','0','0','0','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','1','1','1','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','0','1','0','1','1','0','0','0','0','0','0','0','1','\0'},
  {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','\0'},
};

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
		g = cube();
		var_init(g);
		window_init();
		sprites_init(g->sprite_array);
		cart_init(g->cart_image);
		copy_world_map_to_coord(&g->map->coord, 15, 16);
		mlx_hook(g->win, 17, NoEventMask, close_window, g);
		mlx_hook(g->win, 2, KeyPressMask, key_press, g->keys);
		mlx_hook(g->win, 3, KeyReleaseMask, key_release, g->keys);
		mlx_loop_hook(g->mlx, frame_render, g->cube_image);
		mlx_loop(g->mlx);
	/* }
	else
	{
		ft_putstr_fd("Error : amount of arguments", STDERROR, YES);
		return (0);
	} */
	return (0);
}
