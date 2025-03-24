#include "cub3d.h"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Wrong number of arguments");
        return (0);
    }
    if (strrchr(av[1], ".cub") != 1)
    {
        printf("it works");
    }
    return (0);
}