#include "cub3d.h"

int main(int ac, char **av)
{
    t_map maps;

    if (ac != 2)
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
    ft_memset(&maps, 0, sizeof(maps));
    check_map_file(&maps, av);
    return (0);
}
