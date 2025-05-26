#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "./mlx_linux/mlx.h"

// ============================ CONSTANTS ============================

#define WIDTH 2048        // screen width
#define HEIGHT 1024        // screen height
#define mapX 8            // map width (in tiles)
#define mapY 8            // map height (in tiles)
#define mapS 64           // tile size (each block is 64x64 pixels)
#define PI 3.1415926535   // constant pi
#define FOV 60            // field of view
#define NUM_RAYS 60       // number of rays to cast
#define DEG2RAD(a) ((a) * PI / 180.0)  // degrees to radians conversion

// ============================ MAP DEFINITION ============================

int map[] = {
    1,1,1,1,1,1,1,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

// ============================ GAME STRUCT ============================

typedef struct s_game {
    void *mlx;          // MLX context
    void *win;          // MLX window
    void *img;          // image buffer
    char *addr;         // pixel data
    int bpp;            // bits per pixel
    int line_len;       // number of bytes in a line
    int endian;         // endian format

    float px, py;       // player x/y position
    float pdx, pdy;     // player direction vector (x/y component)
    float pa;           // player angle (in degrees)
} t_game;

// ============================ UTILS ============================

// Fix angle to stay within 0-359 degrees
int FixAng(int a) {
    if (a > 359) a -= 360;
    if (a < 0) a += 360;
    return a;
}

// Check if a given pixel location is inside a wall
int is_wall(float x, float y) {
    int mx = (int)(x) / mapS;
    int my = (int)(y) / mapS;
    if (mx >= 0 && mx < mapX && my >= 0 && my < mapY)
        return map[my * mapX + mx];
    return 1;  // treat out-of-bounds as wall
}

// Distance between two points
float dist(float ax, float ay, float bx, float by) {
    return sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
}

// Set a pixel color into the image buffer
void img_pixel_put(t_game *g, int x, int y, int color) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
    char *dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
    *(unsigned int *)dst = color;
}

// ============================ DRAW ============================

// Draw a single block (map tile or player square)
void draw_block(t_game *g, int x, int y, int w, int h, int color) {
    int i = 0;
    while (i < h) {
        int j = 0;
        while (j < w) {
            img_pixel_put(g, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

// Draw the 2D map
void draw_map(t_game *g) {
	int y;
	int x;
	int color;

	y = -1;
	while (++y < mapY)
	{
		x = -1;
		while (++x < mapX)
			draw_block(g, x * mapS, y * mapS, mapS, mapS, 0x000000);
	}
	y = -1;
	while (++y < mapY)
	{
		x = -1;
		while (++x < mapX)
		{
			if(map[y * mapX + x])
				color = 0x999999;
			else
				color = 0x000000;
			draw_block(g, x * mapS, y * mapS, mapS - 1, mapS - 1, color);
		}
	}
}

// Draw the player as a small square
void draw_player(t_game *g) {
    draw_block(g, g->px - 4, g->py - 4, 8, 8, 0xFFFF00);
}

// Cast rays and draw lines on 2D map for debug view
void draw_ray(t_game *g, float ra) {
    float rx = g->px;
    float ry = g->py;
    float xo = cos(DEG2RAD(ra));
    float yo = -sin(DEG2RAD(ra));

    int i = 0;
    while (i < 1000) {
        int mx = rx / mapS;
        int my = ry / mapS;
        if (mx >= 0 && mx < mapX && my >= 0 && my < mapY && map[my * mapX + mx] == 1)
            break;
        img_pixel_put(g, rx, ry, 0x00FF00); // green
        rx += xo;
        ry += yo;
        i++;
    }
}

void draw_rays(t_game *g) {
    int r = 0;
    int ra = FixAng((int)g->pa + 30);
    while (r < 60) {
        draw_ray(g, ra);
        ra = FixAng(ra - 1);
        r++;
    }
}

// Cast rays and draw vertical walls for the 3D view
void draw_3D_view(t_game *g) {
	int r = 0;
    float ra; // ray angle
    float rx, ry, xo, yo;
    int i;
    float dist_to_wall;
    int lineH, lineOff;
    float ca; // angle correction

    while (r < WIDTH) {
        // Calculate ray angle for this column
        ra = FixAng((int)g->pa + FOV/2 - r * (FOV / (float)WIDTH));
        float ray_rad = DEG2RAD(ra);

        // Start ray at player position
        rx = g->px;
        ry = g->py;
        xo = cos(ray_rad);
        yo = -sin(ray_rad);

        // Cast the ray until it hits a wall
        i = 0;
        while (i < 5000) {
            int mx = rx / mapS;
            int my = ry / mapS;
            if (mx >= 0 && mx < mapX && my >= 0 && my < mapY && map[my * mapX + mx] == 1)
                break;
            rx += xo;
            ry += yo;
            i++;
        }
        // Distance from player to wall
        dist_to_wall = dist(g->px, g->py, rx, ry);

        // Fix fish-eye effect
        ca = DEG2RAD(FixAng(ra - g->pa));
        dist_to_wall = dist_to_wall * cos(ca);

        // Calculate line height
		lineH = (int)((mapS * 200) / (dist_to_wall + 0.0001f));
		if (lineH < 1)
			lineH = 1;

        if (lineH > HEIGHT) lineH = HEIGHT;

        lineOff = (HEIGHT / 2) - (lineH / 2);

        // Draw vertical line (wall slice)
        int y = -1;
		while (++y < lineH)
			img_pixel_put(g, r, lineOff + y, 0x00FF00);
        r++;
    }
}

void	render_frame(t_game *g)
{
    // Init image buffer
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
    g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_len, &g->endian);
    draw_3D_view(g);
    draw_map(g);
    draw_player(g);
    draw_rays(g);
	mlx_clear_window(g->mlx, g->win);
    mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
    mlx_destroy_image(g->mlx, g->img);
}
// ============================ EVENTS ============================

int	close_window(t_game *g)
{
    exit(0);
    return (0);
}

// Handle key press for movement and rotation
int key_press(int key, t_game *g) {
    float newx, newy;

    if (key == 65307) close_window(g);  // ESC = exit

    if (key == 65361) {         // Left arrow: rotate left
        g->pa += 5;
        g->pa = FixAng(g->pa);
        g->pdx = cos(DEG2RAD(g->pa));
        g->pdy = -sin(DEG2RAD(g->pa));
    }

    if (key == 65363) {         // Right arrow: rotate right
        g->pa -= 5;
        g->pa = FixAng(g->pa);
        g->pdx = cos(DEG2RAD(g->pa));
        g->pdy = -sin(DEG2RAD(g->pa));
    }

    if (key == 'w') {           // Move forward
        newx = g->px + g->pdx * 5;
        newy = g->py + g->pdy * 5;
        if (!is_wall(newx, newy)) { g->px = newx; g->py = newy; }
    }

    if (key == 's') {           // Move backward
        newx = g->px - g->pdx * 5;
        newy = g->py - g->pdy * 5;
        if (!is_wall(newx, newy)) { g->px = newx; g->py = newy; }
    }

    if (key == 'a') {           // Strafe left
        newx = g->px + g->pdy * 5;
        newy = g->py - g->pdx * 5;
        if (!is_wall(newx, newy)) { g->px = newx; g->py = newy; }
    }

    if (key == 'd') {           // Strafe right
        newx = g->px - g->pdy * 5;
        newy = g->py + g->pdx * 5;
        if (!is_wall(newx, newy)) { g->px = newx; g->py = newy; }
    }
    // Redraw frame
	render_frame(g);
    return 0;
}

// ============================ MAIN ============================

int main() {
    t_game g;

    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, WIDTH, HEIGHT, "Raycaster with MLX");

    g.px = 150;
    g.py = 400;
    g.pa = 90;
    g.pdx = cos(DEG2RAD(g.pa));
    g.pdy = -sin(DEG2RAD(g.pa));


    // Draw first frame
	render_frame(&g);

    // Input handling
    mlx_hook(g.win, 2, 1L<<0, key_press, &g);
	mlx_hook(g.win, 17, 0, close_window, &g);
    mlx_loop(g.mlx);
    return 0;
}
