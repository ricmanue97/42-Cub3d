

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <float.h>
#include <sys/time.h>
#include <math.h>
#include "define.h"
#include "../aux/libft.h"

/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

typedef struct	s_frame
{
	//calculate ray position and direction
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	//which box of the map we're in
	int		map_x;
	int		map_y;
	//length of ray from current position to next x or y-side
	double	side_dist_x;
	double	side_dist_y;
	//length of ray from one x or y-side to next x or y-side
	double	delta_dist_x;
	double	delta_dist_y;
	//what direction to step in x or y-direction (either +1 or -1)
	int		step_x;
	int		step_y;
	int		side; //was a NS or a EW wall hit?
	double	wall_distance;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_direction;
}				t_frame;

typedef struct	s_player
{
	double		pos_x;		// player x position
	double		pos_y;		// "" y position
	double		dir_x;		// player direction vector (x component)
	double		dir_y;		// "" (y component)
	double		plane_x;		// the 2d raycaster version of camera plane (x component)
	double		plane_y;		// "" (y component)
}				t_player;

typedef struct	s_map
{
	char		**coordinates;
	char		*path;			//?? To remove?
	void		*player;
	void		*N_sprite;
	void		*E_sprite;
	void		*S_sprite;
	void		*W_sprite;
	int			map_width;
	int			map_height;
}				t_map;

typedef struct	s_game
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
