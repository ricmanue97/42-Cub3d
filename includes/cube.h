

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


/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_a;
}			t_player;

typedef struct s_map
{
	char		**map_ber;
	char		*path;
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
	void		*mlx;
	void		*win;
	t_player	*player;
	t_map		*map;
	int			player_count;
}				t_game;

/* ************************************************************************** */
/*                              HELPER FUNCTIONS                              */
/* ************************************************************************** */


/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

char	*ft_name_check(char *file);
int		ft_args_validation(char **av);

# endif
