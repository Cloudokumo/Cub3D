#include "cub3d.h"

int parse_color(t_obj_reader *reader, t_color *color) {
    int values[3];
    char *num_str;
    int16_t c;
    int i = 0;
    
    while (i < 3) {
        skip_whitespace(reader);
        num_str = read_string(reader);
        if (!num_str) 
            return 0;
        
        printf("%s color\n", num_str);
        values[i] = atoi(num_str);
        free(num_str);
        
        if (i < 2) {
            c = obj_reader_peek(reader);
            if (c != ',') 
                return 0;
            obj_reader_next(reader);
        }
        
        i++;
    }
    
    color->r = values[0];
    printf("%d color\n", values[0]);
    color->g = values[1];
    printf("%d color\n", values[1]);
    color->b = values[2];
    printf("%d color\n", values[2]);
    
    return 1;
}