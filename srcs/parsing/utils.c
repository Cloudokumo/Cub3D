#include "cub3d.h"


int skip_whitespace(t_obj_reader *reader)
{
    int16_t c;

    while ((c = obj_reader_peek(reader)) != -1 && (c == ' ' || c == '\t' || c == '\n'))
        obj_reader_next(reader);
    return c;
}

int skip_whitespace_map(t_obj_reader *reader)
{
    int16_t c;

    while ((c = obj_reader_peek(reader)) != -1 && ( c == '\t' || c == '\n'))
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