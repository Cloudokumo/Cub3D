#include "cub3d.h"

int main(int ac, char **av)
{
    t_map maps;
    t_game game;
    if (ac != 2)
    {
        printf("Error: Wrong number of arguments\n");
        return (1);
    }
    ft_memset(&maps, 0, sizeof(maps));
    ft_memset(&game, 0, sizeof(t_game));
    if (check_map_file(&maps, av) != 1)
        return (1);
    if (init_game(&game, &maps) != 0)
        return (1);
    printf("CHECKCHC\n");
    run_game(&game);
    cleanup_game(&game);
    cleanup_map(&maps);
    return (0);
}