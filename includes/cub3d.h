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
    double pos_x;
    double pos_y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
    double move_speed;
    double rot_speed;
} t_player;

typedef struct s_mlx
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int win_width;
    int win_height;
} t_mlx;

typedef struct s_texture
{
    void *img;
    char *addr;
    int width;
    int height;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_texture;

typedef struct s_ray
{
    double camera_x;
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
char *read_string_map(t_obj_reader *reader/* , int flag */);
int skip_whitespace_map(t_obj_reader *reader);
void check_all_conditions(t_map *maps);
void free_map(t_map *map);
void check_N_S_W_E_elements(t_map *maps);
void call_flood_fill(t_map *maps);
int check_next_step(t_map *maps, int y, int x);

int read_file(t_map *maps, int fd);
// int ft_len(const char *s);

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
int load_textures(t_game *game);
int run_game(t_game *game);
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);
int close_window(t_game *game);
int game_loop(t_game *game);
void handle_movement(t_game *game);
void draw_ceiling_floor(t_game *game);
void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void raycasting(t_game *game);
void draw_textured_line(t_game *game, t_ray *ray, int x);
void cleanup_map(t_map *map);
void cleanup_game(t_game *game);

#endif