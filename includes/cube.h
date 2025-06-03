

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <sys/time.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "define.h"
#include "../aux/libft.h"
#include "../aux/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"

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

typedef struct	s_sprite
{
	double		wall_hit;
	int			texture_x;
	int			texture_y;
	double		texture_pos;
	double		step;
}				t_sprite;

typedef struct	s_image
{
	void			*image;
	char			*path;
	int				size_line;
	char			*addr;		// pixel data
	int				bpp;		// bits per pixel
	int				endian;		// endian format
	int				width;
	int				height;
	char			*data;
}				t_image;

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
	char			**coordinates;
	char			*path;			//?? To remove?
	void			*player;
	int				map_width;
	int				map_height;
	unsigned long	C;
	unsigned long	F;
}				t_map;

typedef struct	s_game
{
	void		*mlx;				// MLX context
	void		*win;				// MLX window
	t_image		*cube_image;		// cube image var
	t_image		sprite_array[4];
	t_player	*player;			// player struct
	t_map		*map;				// map struct
	int			player_count;	//?? To remove?

}				t_game;

//Struct caller
t_game			*cube(void);

/* ************************************************************************** */
/*                               PLAYER MOVEMENT                              */
/* ************************************************************************** */

//Controls the press of keys (player movement)
int				key_press(int key, t_player *p);
//Calculates if the movements hits a wall
int				is_wall(double x, double y);

/* ************************************************************************** */
/*                          WINDOW RELATED FUNCTIONS                          */
/* ************************************************************************** */

//Window initialization
int				window_init(void);
//Frame renderization
int				frame_render(void);
//Window closing
int				close_window(t_game *g);

/* ************************************************************************** */
/*                                    DRAW                                    */
/* ************************************************************************** */

//Retrieves a specific color
unsigned int	get_color(t_image image, int x, int y);
//Set a pixel color into the image buffer
void			img_pixel_put(t_image *img, int x, int y, int color);

/* ************************************************************************** */
/*                               ALGO FUNCTIONS                               */
/* ************************************************************************** */

//Calculate ray position and direction
void			ray_pos_dir(t_frame *f, int x);
//Player position and distance calculation from one x or y-side to next x or y-side
void			player_dist_axis(t_frame *f);
//Calculate step a inital side distance
void			side_dist(t_frame *f);
//Perform DDA
void			perform_dda(t_frame *f);
//Calculate height of line to draw on screen
void			line_height(t_frame *f);
//Disposition of wall hit
int				wall_direction(t_frame *f);
//Point-of-view calculations
void			wall_hit(t_frame *f, t_sprite *s);
//Draw of the line in the buffer
void			draw_line(t_image *img, t_frame *f, t_image *sprites, int x);

/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

char			*ft_name_check(char *file);
int				ft_args_validation(char **av);

# endif
