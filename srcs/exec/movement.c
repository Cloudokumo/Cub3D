#include "cub3d.h"

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_y * MOVE_SPEED;
	if ((game->key_w && game->key_a) || (game->key_w && game->key_d))
	{
		new_x = game->player.pos_x + game->player.dir_x * (MOVE_SPEED * sqrt(2)
				/ 2);
		new_y = game->player.pos_y + game->player.dir_y * (MOVE_SPEED * sqrt(2)
				/ 2);
	}
	if (game->map->grid[(int)(game->player.pos_y)][(int)new_x] == '0')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)(game->player.pos_x)] == '0')
		game->player.pos_y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_y * MOVE_SPEED;
	if ((game->key_s && game->key_a) || (game->key_s && game->key_d))
	{
		new_x = game->player.pos_x - game->player.dir_x * (MOVE_SPEED * sqrt(2)
				/ 2);
		new_y = game->player.pos_y - game->player.dir_y * (MOVE_SPEED * sqrt(2)
				/ 2);
	}
	if (game->map->grid[(int)(game->player.pos_y)][(int)new_x] == '0')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)(game->player.pos_x)] == '0')
		game->player.pos_y = new_y;
}

void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y + game->player.dir_x * MOVE_SPEED;
	if ((game->key_w && game->key_d) || (game->key_s && game->key_d))
	{
		new_x = game->player.pos_x - game->player.dir_y * (MOVE_SPEED * sqrt(2)
				/ 2);
		new_y = game->player.pos_y + game->player.dir_x * (MOVE_SPEED * sqrt(2)
				/ 2);
	}
	if (game->map->grid[(int)(game->player.pos_y)][(int)new_x] == '0')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)(game->player.pos_x)] == '0')
		game->player.pos_y = new_y;
}

void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.pos_x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.pos_y - game->player.dir_x * MOVE_SPEED;
	if ((game->key_w && game->key_a) || (game->key_s && game->key_a))
	{
		new_x = game->player.pos_x + game->player.dir_y * (MOVE_SPEED * sqrt(2)
				/ 2);
		new_y = game->player.pos_y - game->player.dir_x * (MOVE_SPEED * sqrt(2)
				/ 2);
	}
	if (game->map->grid[(int)(game->player.pos_y)][(int)new_x] == '0')
		game->player.pos_x = new_x;
	if (game->map->grid[(int)new_y][(int)(game->player.pos_x)] == '0')
		game->player.pos_y = new_y;
}

void	handle_movement(t_game *game)
{
	if (game->key_w)
		move_forward(game);
	if (game->key_s)
		move_backward(game);
	if (game->key_d)
		move_right(game);
	if (game->key_a)
		move_left(game);
	if (game->key_right)
		rotate_right(game, ROT_SPEED);
	if (game->key_left)
		rotate_left(game, ROT_SPEED);
}
