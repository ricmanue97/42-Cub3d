

#ifndef CUBE_H
# define CUBE_H

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
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"

/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

//Frame Struct
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
	double	wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		wall_direction;
}				t_frame;

//Texture Struct
typedef struct	s_texture
{
	double		wall_hit;
	int			texture_x;
	int			texture_y;
	double		texture_pos;
	double		step;
}				t_texture;

//Image Struct
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

//Player Struct
typedef struct	s_player
{
	double		pos_x;		// player x position
	double		pos_y;		// "" y position
	double		dir_x;		// player direction vector (x component)
	double		dir_y;		// "" (y component)
	double		plane_x;		// the 2d raycaster version of camera plane (x component)
	double		plane_y;		// "" (y component)
}				t_player;

//Map Struct
typedef struct	s_map
{
	char		**coord;
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
	void		*mlx;				// MLX context
	void		*win;				// MLX window
	t_image		*cube_image;		// cube image var
	t_image		sprite_array[3];	// sprite direction (N, E, S, W)
	t_player	*player;			// player struct
	t_map		*map;				// map struct
	int			player_count;	//?? To remove?

}				t_game;

//Struct caller
t_game			*cube(void);

/* ************************************************************************** */
/*                                   ANGLES                                   */
/* ************************************************************************** */

//Fix angle to stay within 0-359 degrees
float FixAng(float a);
//Degrees to radians
float	deg_to_rad(float a);
//Calculate the player's angle in degrees
float	get_player_angle(t_player *player);

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
/*                                    MAP                                     */
/* ************************************************************************** */

int	draw_ray_to_pixel(t_game *g, double rx, double ry);
// Cast rays and draw lines on 2D map
void	draw_ray(t_game *g, float ra);
void	draw_rays(t_game *g);
void	draw_map(t_game *g);
//Draw the player as a small square
void	draw_player(t_game *g);

/* ************************************************************************** */
/*                                    DRAW                                    */
/* ************************************************************************** */

//Retrieves a specific color
unsigned int	get_color(t_image image, int x, int y);
//Set a pixel color into the image buffer
void			img_pixel_put(t_image *img, int x, int y, int color);
void			draw_block(t_game *g, int x, int y, int w, int h, int color);

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
void			wall_hit(t_frame *f, t_texture *s);
//Draw of the line in the buffer
void			draw_line(t_image *img, t_frame *f, t_image *sprites, int x);

/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

char			*ft_name_check(char *file);
int				ft_args_validation(char **av);

# endif
