#include "cub3d.h"


int skip_whitespace(t_obj_reader *reader)
{
    int16_t c;

    while ((c = obj_reader_peek(reader)) != -1 && (c == ' ' || c == '\t'))
        obj_reader_next(reader);
    return c;
}

char *read_string(t_obj_reader *reader)
{
    size_t start = reader->i;
    size_t len = 0;
    int16_t c;
    char *str;

    while ((c = obj_reader_peek(reader)) != -1 && c != ' ' && c != '\n')
    {
        len++;
        obj_reader_next(reader);
    }
    if (len == 0)
        return NULL;

    str = malloc(len + 1);
    if (!str)
        return NULL;
    memcpy(str, reader->buffer + start, len);
    str[len] = '\0';
    return str;
}

int parse_map_config(t_obj_reader *reader, t_map *map)
{
    int16_t c;
    char *type;

    while ((c = skip_whitespace(reader)) != -1 && c != '\n')
    {
        type = read_string(reader);
        if (!type)
            break;
        if (strcmp(type, "NO") == 0)
            map->no = read_string(reader);
        else if (strcmp(type, "SO") == 0)
            map->so = read_string(reader);
        else if (strcmp(type, "WE") == 0)
            map->we = read_string(reader);
        else if (strcmp(type, "EA") == 0)
            map->ea = read_string(reader);
        else if (strcmp(type, "F") == 0)
        {
            if (!parse_color(reader, &map->floor_color))
            {
                free(type);
                return 0;
            }
        }
        else if (strcmp(type, "C") == 0)
        {
            if (!parse_color(reader, &map->ceiling_color))
            {
                free(type);
                return 0;
            }
        }
        else
        {
            free(type);
            return 0;
        }
        free(type);
    }
    return 1;
}