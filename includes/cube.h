

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <math.h>
#include "define.h"
#include "../aux/libft.h"
#include "../mlx_linux/mlx.h"

/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

typedef struct s_player
{
	double		pos_x;		// player x position
	double		pos_y;		// "" y position
	double		dir_x;		// player direction vector (x component)
	double		dir_y;		// "" (y component)
	double		planeX;		// the 2d raycaster version of camera plane (x component)
	double		planeY;		// "" (y component)
}			t_player;

typedef struct s_map
{
	char		**map_ber;
	char		*path;			//?? To remove?
	void		*player;
	void		*N_sprite;
	void		*E_sprite;
	void		*S_sprite;
	void		*W_sprite;
	int			map_width;
	int			map_height;
}				t_map;

typedef struct s_game
{
	void		*mlx;		// MLX context
	void		*win;		// MLX window
	t_player	*player;	// player struct
	t_map		*map;		// map struct
	int			player_count;
}				t_game;

t_game	*cube(void);

/* ************************************************************************** */
/*                              HELPER FUNCTIONS                              */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

char	*ft_name_check(char *file);
int		ft_args_validation(char **av);

# endif
