

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
#include "../aux/libft.h"
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"

/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

//Frame Struct
typedef struct	s_frame
{
	double			camera_x;		//X-coordinate in camera space
	double			ray_dir_x;		//Ray position and direction (x vector)
	double			ray_dir_y;		//Ray position and direction (y vector)
	int				map_x;			//Which box of the map the player it's in (x vector)
	int				map_y;			//Which box of the map the player it's in (y vector)
	double			side_dist_x;	//Length of ray from current position to next x-side
	double			side_dist_y;	//Length of ray from current position to next y-side
	double			delta_dist_x;	//Length of ray from one x-side to next x-side
	double			delta_dist_y;	//Length of ray from one y-side to next y-side
	int				step_x;			//What direction to step in x-direction (either +1 or -1)
	int				step_y;			//What direction to step in y-direction (either +1 or -1)
	int				side;			//Was a NS or a EW wall hit?
	double			wall_dist;		//Distance from the wall
	int				line_height;	//Size of the line to draw
	int				draw_start;		//Where to start drawing in the screen
	int				draw_end;		//Where to stop drawing in the screen
}				t_frame;

//Texture to frame Struct
typedef struct	s_texture
{
	int				wall_direction;	//Which texture (direction) to draw
	double			wall_hit;		//Where exactly the wall was hit
	int				texture_x;		//Texture coordinate x
	int				texture_y;		//Texture coordinate y
	double			texture_pos;	//Texture coordinate incrementer with step
	double			step;			//How much to increase the texture coordinate per screen pixel
}				t_texture;

//Image Struct
typedef struct	s_image
{
	void			*image;			//Pointer to the image
	char			*path;			//Image path
	int				size_line;		//Xpm line size
	char			*addr;			//Pixel data
	int				bpp;			//Bits per pixel
	int				endian;			//Endian format
	int				width;			//Image width
	int				height;			//Image height
}				t_image;

//Player Struct
typedef struct	s_player
{
	double			pos_x;			//Player x position
	double			pos_y;			//Player y position
	double			dir_x;			//Player direction vector (x component)
	double			dir_y;			//Player direction vector (y component)
	double			plane_x;		//The 2d raycaster version of camera plane (x component)
	double			plane_y;		//The 2d raycaster version of camera plane (y component)
}				t_player;

//Pressed/Released keys Struct
typedef struct	s_key
{
	int				w;
	int				s;
	int				a;
	int				d;
	int				l_arrow;
	int				r_arrow;
}				t_key;

//Map Struct
typedef struct	s_map
{
	char			**coord;
	char			*path;			//?? To remove?
	void			*player;
	unsigned long	C;
	unsigned long	F;
	int				m_width;
	int				m_height;
}				t_map;

//Mini-map Struct
typedef struct	s_minimap
{
	int				size;				//Mini-map half-size (in all directions)
	double			start_x;			//X map coordenate where to start drawing
	double			start_y;			//Y map coordenate where to start drawing
	double			end_x;				//X map coordenate where to stop drawing
	double			end_y;				//Y map coordenate where to stop drawing
	double			draw_mi_x;			//Last X coordenate drawn
	double			draw_mi_y;			//Last Y coordenate drawn
	double			draw_x;				//X coordenate to draw
	double			draw_y;				//Y coordenate to draw
	double			ray_x;				//X vector ray incrementer
	double			ray_y;				//Y vector ray incrementer
	double			dir_x;				//X vector ray direction
	double			dir_y;				//Y vector ray direction
}				t_minimap;

typedef struct	s_game
{
	void			*mlx;				//MLX initiator
	void			*win;				//MLX window
	t_image			*cube_image;		//Cub image(frame by frame drawing)
	t_image			sprite_array[4];	//Array of all 4 textures(4 directions)
	t_player		*player;			//Player struct
	t_image			*cart_image;		//Cart image
	t_map			*map;				//Map struct
	t_minimap		*mini_map;			//Mini-map struct
	t_key			*keys;				//Keys-to-press struct
	int				player_count;	//?? To remove?
}				t_game;

//Struct caller
t_game			*cube(void);
//Variable initialization
void			var_init(t_game *g);

/* ************************************************************************** */
/*                                   ANGLES                                   */
/* ************************************************************************** */

//Fix angle to stay within 0-359 degrees
float				fix_ang(float a);
//Degrees to radians
float				deg_to_rad(float a);
//Calculate the player's angle in degrees
float				get_player_angle(t_player *player);

/* ************************************************************************** */
/*                               PLAYER MOVEMENT                              */
/* ************************************************************************** */

//Controls the press of keys (player movement)
int				key_press(int key, t_key *k);
//Controls the release of keys (player movement)
int				key_release(int key, t_key *k);
//Calculates if the player hits a wall
int				is_wall(double x, double y, double move_speed);
//Calculates the movement
void			mov_calculation(t_player *p, t_key *k);


/* ************************************************************************** */
/*                          WINDOW RELATED FUNCTIONS                          */
/* ************************************************************************** */

//Window initialization
int				window_init(void);
//Frame renderization
int				frame_render(t_image *img);
//Window closing
int				close_window(t_game *g);
//Sprites initialization
void			sprites_init(t_image img[4]);
//Cart image initialization
void			cart_init(t_image *cart);

/* ************************************************************************** */
/*                                    MAP                                     */
/* ************************************************************************** */

//Main function of mini-map draw
void			draw_map(t_map *m, t_minimap *mi, t_player *p);
//Draw the 2D big map
void			draw_big_map(t_map *m, t_minimap *mi);
//Draw the 2D small map
void			draw_small_map(t_map *m);
//Draw the player as a small square in big map
void			draw_big_player(t_minimap *mi, t_player *p);
//Draw the player as a small square in small map
void			draw_small_player(t_player *p);
//Cast rays and draw lines on 2D big map
void			draw_big_rays(t_map *m, t_minimap *mi, t_player *p);
//Cast rays and draw lines on 2D small map
void			draw_small_rays(t_map *m, t_minimap *mi, t_player *p);

/* ************************************************************************** */
/*                                    DRAW                                    */
/* ************************************************************************** */

//Retrieves a specific color
unsigned int	get_color(t_image *image, int x, int y);
//Set a pixel color into the image buffer
void			img_pixel_put(t_image *img, int x, int y, int color);
//Draw a block of pixels into the frame
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
void			draw_line(t_image *img, t_frame *f, t_image sprites[4], int x);

/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

char			*ft_name_check(char *file);
int				ft_args_validation(char **av);

# endif
