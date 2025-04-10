#ifndef CUB3D_H
#define CUB3D_H

#include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
# include <sys/stat.h>
#include <stdint.h>

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_color
{
    int r;
    int g;
    int b;
} t_color;

typedef struct s_map
{
    char dir_name;
    char *no;
    char *so;
    char *we;
    char *ea;
    char **grid;
    char *is_empty_line;
    int width;
    int height;

    t_color floor_color;
    t_color ceiling_color;

} t_map;

typedef struct s_obj_reader
{
    int fd;
    char *buffer;
    size_t buffer_size;
    size_t len;
    size_t i;
    size_t column;
    size_t line;
} t_obj_reader;


typedef struct s_player
{
    double pos_x;      // Player's x-coordinate
    double pos_y;      // Player's y-coordinate 
    double dir_x;      // Player's x-direction (where they're facing)
    double dir_y;      // Player's y-direction v (where they're facing)
    double plane_x;    // Camera plane x-component (for raycasting field of view)
    double plane_y;    // Camera plane y-component (for raycasting field of view)
} t_player;

typedef struct s_mlx
{
    void *mlx;         // MLX instance pointer (core graphics handle)
    void *win;         // Window pointer (handle to the created window)
    void *img;         // Image pointer (handle to the created image)
    char *addr;        // Image data address (pixel buffer for direct manipulation)
    int bits_per_pixel; // Number of bits in one pixel (color depth)
    int line_length;   // Number of bytes in one row of the image (for pixel addressing)
    int endian;        // Endianness of the pixel color representation (byte order)
} t_mlx;

typedef struct s_texture
{
    void *img;         // Texture image pointer (handle to the loaded texture)
    char *addr;        // Texture image data address (pixel buffer)
    int width;         // Width of the texture in pixels
    int height;        // Height of the texture in pixels
    int bits_per_pixel; // Number of bits in one pixel of the texture
    int line_length;   // Number of bytes in one row of the texture (for pixel addressing)
    int endian;        // Endianness of the texture pixel color representation
} t_texture;

typedef struct s_game
{
    t_mlx mlx;
    t_map *map;
    t_player player;
    t_texture textures[4]; // North, South, East, West
    int key_w;
    int key_s;
    int key_a;
    int key_d;
    int key_left;
    int key_right;
} t_game;

typedef struct s_draw
{
    int y;
    int offset;
    int tex_index;
    int tex_x;
    int tex_y;
    int color;
    double step;
    double wall_x;
    double tex_pos;
} t_draw;


typedef struct s_ray
{
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double side_dist_x;
    double side_dist_y;
    double delta_dist_x;
    double delta_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
} t_ray;

t_obj_reader obj_create_reader(int fd, char *buffer, size_t buffer_size);
int16_t obj_reader_peek(t_obj_reader *self);
int obj_reader_next(t_obj_reader *self);
int check_map_file(t_map *maps, char **av);
char *read_string_map(t_obj_reader *reader);
int skip_whitespace_map(t_obj_reader *reader);
void check_all_conditions(t_map *maps);
void free_map(t_map *map);
void check_N_S_W_E_elements(t_map *maps);
void call_flood_fill(t_map *maps);
int check_next_step(t_map *maps, int y, int x);

int read_file(t_map *maps, int fd);
void ft_clean_up(t_map *maps, int index, char *msg);

int skip_whitespace(t_obj_reader *reader);
char *read_string(t_obj_reader *reader);
int parse_map_config(t_obj_reader *reader, t_map *map);
int parse_color(t_obj_reader *reader, t_color *color);
char *get_color_values(char *str, int j);
int parse_color_element(t_obj_reader *reader, t_color *color, int *found);
int check_values(int value);

int init_game(t_game *game, t_map *map);
void init_player(t_game *game);
int	load_textures(t_game *game);
void	cleanup_game(t_game *game);
void	cleanup_map(t_map *map);
int run_game(t_game *game);
int game_loop(t_game *game);
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);

int close_window(t_game *game);
void draw_ceiling_floor(t_game *game);
void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void raycasting(t_game *game, t_ray *ray);
void dda(t_game *game, t_ray *ray);
void    low_high_pixel(t_ray *ray);
void find_direction(t_game *game, t_ray *ray);
void init_keys(t_game *game);
void draw_line(t_game *game, t_ray *ray, int x);
void rotate_left(t_game *game);
void rotate_right(t_game *game);
void move_forward(t_game *game);
void move_backward(t_game *game);
void move_right(t_game *game);
void move_left(t_game *game);
void handle_movement(t_game *game);


#endif