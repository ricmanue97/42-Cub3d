

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
/*                                   Structs                                  */
/* ************************************************************************** */

typedef struct s_player
{
	int		x;
	int		y;
}			t_player;

typedef struct s_map
{
	char		**map_ber;
	char		*path;
	void		*player;
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


# endif