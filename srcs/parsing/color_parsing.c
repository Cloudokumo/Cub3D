#include "cub3d.h"

int parse_color(t_obj_reader *reader, t_color *color)
{
    int values[3];
    int16_t c;
    
    for (int i = 0; i < 3; i++)
    {
        skip_whitespace(reader);
        char *num_str = read_string(reader);
        if (!num_str)
            return 0;
        values[i] = atoi(num_str);
        free(num_str);
        if (i < 2)
        {
            c = obj_reader_peek(reader);
            if (c != ',')
                return 0;
            obj_reader_next(reader);
        }
    }
    color->r = values[0];
    color->g = values[1];
    color->b = values[2];
    return 1;
}