#include "cub3d.h"
// void get_map_dimensions(t_map *maps, const char *file_path);
// void free_map(t_map *maps);

// void init_vars(t_map *maps)
// {
//     maps->height = 0;
//     maps->grid = ft_calloc(sizeof(char *), 1);
// }
int main(int ac, char **av)
{
    t_map maps;

    if (ac != 2)
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
    ft_memset(&maps, 0, sizeof(maps));
    // init_vars(&maps);
    // get_map_dimensions(&maps, av[1]);
    check_map_file(&maps, av);
    // free_map(&maps);


    return (0);
}
