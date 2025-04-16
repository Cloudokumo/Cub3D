/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:04:39 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:04:40 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		cleanup_game(game);
		cleanup_map(game->map);
		exit(0);
	}
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

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
	{
		cleanup_game(game);
		cleanup_map(game->map);
		exit(0);
	}
	else if (keycode == XK_w || keycode == XK_Up)
		game->key_w = 0;
	else if (keycode == XK_s || keycode == XK_Down)
		game->key_s = 0;
	else if (keycode == XK_a)
		game->key_a = 0;
	else if (keycode == XK_d)
		game->key_d = 0;
	else if (keycode == XK_Left)
		game->key_left = 0;
	else if (keycode == XK_Right)
		game->key_right = 0;
	return (0);
}
