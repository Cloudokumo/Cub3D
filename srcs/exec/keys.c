#include "cub3d.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == XK_Escape)
        cleanup_game(game);
    if (keycode == XK_w || keycode == XK_Up)
        game->key_w = 1;
    if (keycode == XK_s || keycode == XK_Down)
        game->key_s = 1;
    if (keycode == XK_a)
        game->key_a = 1;
    if (keycode == XK_d)
        game->key_d = 1;
    if (keycode == XK_Left)
        game->key_left = 1;
    if (keycode == XK_Right)
        game->key_right = 1;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == XK_Escape)
        cleanup_game(game);
    if (keycode == XK_w || keycode == XK_Up)
        game->key_w = 0;
    if (keycode == XK_s || keycode == XK_Down)
        game->key_s = 0;
    if (keycode == XK_a)
        game->key_a = 0;
    if (keycode == XK_d)
        game->key_d = 0;
    if (keycode == XK_Left)
        game->key_left = 0;
    if (keycode == XK_Right)
        game->key_right = 0;
    return (0);
}
