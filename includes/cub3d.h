#ifndef CUB3D_H
# define CUB3D_H

#include "../Libft/libft.h"
// # include "../minilibx-linux/mlx.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
// # include <sys/stat.h>
#include <stdint.h>
#define BUFFER_SIZE 1

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
}               t_obj_reader;

t_obj_reader obj_create_reader(int fd, char *buffer, size_t buffer_size);
int16_t obj_reader_peek(t_obj_reader *self);
int obj_reader_next(t_obj_reader *self);
int check_map_file(t_map *maps, char **av);

void	free_map(t_map *map);


int     skip_whitespace(t_obj_reader *reader);
char *read_string(t_obj_reader *reader);
int parse_map_config(t_obj_reader *reader, t_map *map);
int parse_color(t_obj_reader *reader, t_color *color);
char   *get_color_values(char *str, int j);
int check_values(int value);

#endif