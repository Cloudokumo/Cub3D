#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
    if (keycode < 0 || keycode >= 65364)
        return (0);
    game->keys[keycode] = 1;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode < 0 || keycode >= 65364)
        return (0);
    game->keys[keycode] = 0;
    return (0);
}
