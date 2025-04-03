#include "cub3d.h"

int skip_whitespace(t_obj_reader *reader)
{
    int16_t c;

    while ((c = obj_reader_peek(reader)) != -1 && (c == ' ' || c == '\t' || c == '\n'))
        obj_reader_next(reader);
    return c;
}
char *read_string(t_obj_reader *reader)
{
    char *str = NULL;
    size_t len = 0;
    int16_t c;
    char temp[1024];

    skip_whitespace(reader);
    while ((c = obj_reader_peek(reader)) != -1 && c != ' ' && c != '\n' && c != '\t')
    {
        if (len < sizeof(temp) - 1)
            temp[len++] = c;
        obj_reader_next(reader);
    }
    if (len == 0)
        return NULL;
    str = malloc(len + 1);
    if (!str)
        return NULL;
    memcpy(str, temp, len);
    str[len] = '\0';
    printf("%s yes\n", str);
    return str;
}



int parse_map_config(t_obj_reader *reader, t_map *map)
{
    int16_t c;
    char *type;
    int found_no = 0, found_so = 0, found_we = 0, found_ea = 0;
    int found_f = 0, found_c = 0;

    while ((c = skip_whitespace(reader)) != -1)
    {
        if (found_no && found_so && found_we && found_ea && found_f && found_c) 
        {
            printf("Everything is found :D\n");
            return 1;
        }
        type = read_string(reader);
        if (!type)
            break;
        printf("%s i see\n", type);
        if (strcmp(type, "NO") == 0)
        {
            if (found_no)
            {
                printf("Error: Duplicate NO texture\n");
                free(type);
                return 0;
            }
            map->no = read_string(reader);
            if (!map->no)
            {
                free(type);
                return 0;
            }
            found_no = 1;
        }
        else if (strcmp(type, "SO") == 0)
        {
            if (found_so)
            {
                printf("Error: Duplicate SO texture\n");
                free(type);
                return 0;
            }
            map->so = read_string(reader);
            if (!map->so)
            {
                free(type);
                return 0;
            }
            found_so = 1;
        }
        else if (strcmp(type, "WE") == 0)
        {
            if (found_we)
            {
                printf("Error: Duplicate WE texture\n");
                free(type);
                return 0;
            }
            map->we = read_string(reader);
            if (!map->we)
            {
                free(type);
                return 0;
            }
            found_we = 1;
        }
        else if (strcmp(type, "EA") == 0)
        {
            if (found_ea)
            {
                printf("Error: Duplicate EA texture\n");
                free(type);
                return 0;
            }
            map->ea = read_string(reader);
            if (!map->ea)
            {
                free(type);
                return 0;
            }
            found_ea = 1;
        }
        else if (strcmp(type, "F") == 0)
        {
            if (found_f)
            {
                printf("Error: Duplicate F color\n");
                free(type);
                return 0;
            }
            if (!parse_color(reader, &map->floor_color))
            {
                free(type);
                printf("AAAAAA\n");
                return 0;
            }
            found_f = 1;
        }
        else if (strcmp(type, "C") == 0)
        {

            if (found_c)
            {
                printf("Error: Duplicate C color\n");
                free(type);
                return 0;
            }
            if (!parse_color(reader, &map->ceiling_color))
            {
                free(type);
                return 0;
            }
            found_c = 1;
        }
        else
        {
            printf("Error: Unknown map element: %s\n", type);
            free(type);
            return 0;
        }
        free(type);
        if (found_no && found_so && found_we && found_ea && found_f && found_c) 
        {
            printf("Everything is found :D\n");
            return 1;
        }
    }
    if (!found_no || !found_so || !found_we || !found_ea || !found_f || !found_c)
    {
        printf("Error: Missing required map elements\n");
        return 0;
    }
    return 1;
}
