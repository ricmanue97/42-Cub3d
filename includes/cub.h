/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:56:22 by dicarval          #+#    #+#             */
/*   Updated: 2025/07/14 11:25:03 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <sys/time.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "define.h"
# include "../aux/libft.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"

/* ************************************************************************** */
/*                                   STRUCTS                                  */
/* ************************************************************************** */

//Frame Struct
typedef struct s_frame
{
	double		camera_x;		//X-coordinate in camera space
	double		ray_dir_x;		//Ray position and direction (x vector)
	double		ray_dir_y;		//Ray position and direction (y vector)
	int			map_x;			//Which box of the map the player it's in
	int			map_y;			//Which box of the map the player it's in
	double		side_dist_x;	//Ray length from current pos to next x-side
	double		side_dist_y;	//Ray length from current pos to next y-side
	double		delta_dist_x;	//Ray length from one x-side to next x-side
	double		delta_dist_y;	//Ray length from one y-side to next y-side
	int			step_x;			//What direction to step in x-direction
	int			step_y;			//What direction to step in y-direction
	int			side;			//Was a NS or a EW wall hit?
	double		wall_dist;		//Distance from the wall
	int			line_height;	//Size of the line to draw
	int			draw_start;		//Where to start drawing in the screen
	int			draw_end;		//Where to stop drawing in the screen
}				t_frame;

//Texture to frame Struct
typedef struct s_texture
{
	int			wall_direction;	//Which texture (direction) to draw
	double		wall_hit;		//Where exactly the wall was hit
	int			texture_x;		//Texture coordinate x
	int			texture_y;		//Texture coordinate y
	double		texture_pos;	//Texture coordinate incrementer with step
	double		step;			//How much increase the texture per screen pixel
}				t_texture;

//Image Struct
typedef struct s_image
{
	void		*image;			//Pointer to the image
	char		*path;			//Image path
	int			size_line;		//Xpm line size
	char		*addr;			//Pixel data
	int			bpp;			//Bits per pixel
	int			endian;			//Endian format
	int			width;			//Image width
	int			height;			//Image height
}				t_image;

//Player Struct
typedef struct s_player
{
	double		pos_x;			//Player x position
	double		pos_y;			//Player y position
	double		dir_x;			//Player direction vector (x component)
	double		dir_y;			//Player direction vector (y component)
	char		dir;			//Direction on the map
	double		plane_x;		//The 2d raycaster version of camera plane (x)
	double		plane_y;		//The 2d raycaster version of camera plane (y)
}				t_player;

//Pressed/Released keys Struct
typedef struct s_key
{
	int			w;
	int			s;
	int			a;
	int			d;
	int			l_arrow;
	int			r_arrow;
}				t_key;

//Map Struct
typedef struct s_map
{
	char		**coord;		//Map coordenates
	char		*path;			//Map path
	unsigned	c;				//Ceiling color
	unsigned	f;				//Floor color
	int			m_width;		//Map width
	int			m_height;		//Map height
}				t_map;

//Mini-map Struct
typedef struct s_minimap
{
	int			size;			//Mini-map half-size (in all directions)
	double		start_x;		//X map coordenate where to start drawing
	double		start_y;		//Y map coordenate where to start drawing
	double		end_x;			//X map coordenate where to stop drawing
	double		end_y;			//Y map coordenate where to stop drawing
	double		draw_mm_x;		//Last X coordenate drawn
	double		draw_mm_y;		//Last Y coordenate drawn
	double		draw_x;			//X coordenate to draw
	double		draw_y;			//Y coordenate to draw
	double		ray_x;			//X vector ray incrementer
	double		ray_y;			//Y vector ray incrementer
	double		dir_x;			//X vector ray direction
	double		dir_y;			//Y vector ray direction
}				t_minimap;

//Main Struct
typedef struct s_game
{
	void		*mlx;				//MLX initiator
	void		*win;				//MLX window
	t_image		*cub_image;			//Cub image(frame by frame drawing)
	t_image		sprite_array[4];	//Array of all 4 textures(4 directions)
	t_player	*player;			//Player struct
	t_image		*cart_image;		//Cart image
	t_map		*map;				//Map struct
	t_minimap	*mini_map;			//Mini-map struct
	t_key		*keys;				//Keys-to-press struct
}				t_game;

//Struct caller
t_game			*cub(void);
//Cub variable initialization
void			var_init(t_game *g);

/* ************************************************************************** */
/*                                   ANGLES                                   */
/* ************************************************************************** */

//Fix angle to stay within 0-359 degrees
float			fix_ang(float a);
//Degrees to radians
float			deg_to_rad(float a);
//Calculate the player's angle in degrees
float			get_player_angle(t_player *player);
//Determine the player direction
void			player_direction(t_player *p);

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
int				window_init(t_game *g);
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
void			draw_map(t_map *m, t_minimap *mn, t_player *p);
//Draw the 2D big map
void			draw_big_map(t_map *m, t_minimap *mn);
//Draw the 2D small map
void			draw_small_map(t_map *m);
//Draw the player as a small square in big map
void			draw_big_player(t_minimap *mn, t_player *p);
//Draw the player as a small square in small map
void			draw_small_player(t_player *p);
//Cast rays and draw lines on 2D big map
void			draw_big_rays(t_map *m, t_minimap *mn, t_player *p);
//Cast rays and draw lines on 2D small map
void			draw_small_rays(t_map *m, t_minimap *mn, t_player *p);
//Check if the rays are crossing the walls in the corners
int				corners_stop(t_map *m, t_minimap *mm, int map_y, int map_x);

/* ************************************************************************** */
/*                                    DRAW                                    */
/* ************************************************************************** */

//Retrieves a specific color
unsigned int	get_color(t_image *image, int x, int y);
//Set a pixel color into the image buffer
void			img_pixel_put(t_image *img, int x, int y, int color);
//Draw a block of pixels into the frame
void			draw_block(int x, int y, int size, int color);

/* ************************************************************************** */
/*                               ALGO FUNCTIONS                               */
/* ************************************************************************** */

//Calculate ray position and direction
void			ray_pos_dir(t_frame *f, int x);
//Player position and distance calculation from one x or y-side to next x or y
void			player_dist_axis(t_frame *f);
//Calculate step a inital side distance
void			side_dist(t_frame *f);
//Perform DDA algorythm
void			perform_dda(t_frame *f);
//Calculate height of line to draw on screen
void			line_height(t_frame *f);
//Disposition of the wall hit
int				wall_direction(t_frame *f);
//Point-of-view calculations
void			pov_calculations(t_frame *f, t_texture *s);
//Draw of the line in the buffer
void			draw_line(t_image *img, t_frame *f, t_image sprites[4], int x);

/* ************************************************************************** */
/*                                  PARSING                                   */
/* ************************************************************************** */

// Checks if the given file name is valid and ends with ".cub"
char			*ft_name_check(char *file, int flag);
// Reads and concatenates all map elements from the .cub file
char			*ft_get_elements(char **av);
// Validates and stores a texture or color path from the configuration line
int				ft_validate_path(int i, char *path);
// Checks if a line from the .cub file is a valid configuration or map line
int				ft_check_line(char *line);
// Validates the program arguments and checks the .cub file
int				ft_args_validation(char **av);
// Reads, parses, and validates the map from the .cub file
int				ft_check_map(char **av);
// Checks if a map line starts correctly (with '1' or space)
int				ft_line_start(char *line);
// Calculates the map's width and height, and validates map characters
int				ft_map_size(char **map);
// Checks if a map cell at (i, j) is properly surrounded by valid characters
int				ft_check_surround(char **map, int i, int j);
// Validates that the map is properly surrounded by walls and valid characters
int				ft_validate_map_surroundings(char **map);
// Checks for a valid player position and sets player data in the map
int				ft_validate_map_player(char **map);
// Validates the overall map structure and player position
int				ft_validate_map(char **map);
// Stores the map data from a string into the game structure
int				ft_store_map(char *map);
// Reads lines from a file descriptor and appends them to the map string
int				ft_read_and_append_lines(int fd, char **map);
// Checks if the RGB color values are valid and converts them to a code
int				ft_check_rgbnum(char **conversion, char flag, int *code);
// Parses and validates an RGB color code from a string
int				ft_check_rgbcode(char *color, char flag);
// Stores a texture or color path from a configuration line
int				ft_store_path(char *path);
// Checks if all required elements are present in the configuration
int				ft_check_elements(char **elements);
// Fills the map rows with 'X' to ensure all rows have the same width
void			ft_fill_map(char **map);
// Converts RGB values to a hexadecimal color and stores it in the map
void			ft_convert_hexadecimal(int *code, char c);

/* ************************************************************************** */
/*                                 FREE_ERROR                                 */
/* ************************************************************************** */

void			free_image(t_game *g, t_image *i);
void			free_pointer(void *pointer);
void			free_double_p(void **pointer);
void			free_cub(t_game *g);
void			exit_cub(t_game *g, int error);
int				exit_cross(t_game *g);
void			error_to_exit(t_game *g, int error);
void			img_error_to_exit(t_image *i, int error);
void			free_var_init(t_game *g);

#endif
