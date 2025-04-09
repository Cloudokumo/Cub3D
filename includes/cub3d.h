#ifndef CUB3D_H
#define CUB3D_H

#include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
// # include <sys/stat.h>
#include "../X11/keysym.h"
#include <stdint.h>

// with keysym of X11
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

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
    double move_speed; // Player's movement speed (units per frame/update)
    double rot_speed;  // Player's rotation speed (radians per frame/update)
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
    int win_width;     // Width of the window in pixels
    int win_height;    // Height of the window in pixels
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
    int keys[256];
} t_game;

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

#endif