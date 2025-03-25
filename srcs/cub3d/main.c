#include "cub3d.h"

int main(int ac, char **av)
{
    void *mlx;
    void *window;

    if (ac != 2)
    {
        printf("Wrong number of arguments\n");
        return (EXIT_FAILURE);
    }
    if (check_map_file(av[1]))
    mlx = mlx_init();
    window = mlx_new_window(mlx, 640, 480, "Cub3D");
    mlx_loop(mlx);
    return (EXIT_SUCCESS);
}
