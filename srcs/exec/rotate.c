/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:04:48 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:04:49 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_game *game, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-speed) - game->player.dir_y
		* sin(-speed);
	game->player.dir_y = old_dir_x * sin(-speed) + game->player.dir_y
		* cos(-speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(-speed)
		- game->player.plane_y * sin(-speed);
	game->player.plane_y = old_plane_x * sin(-speed) + game->player.plane_y
		* cos(-speed);
}

void	rotate_right(t_game *game, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(speed) - game->player.dir_y
		* sin(speed);
	game->player.dir_y = old_dir_x * sin(speed) + game->player.dir_y
		* cos(-speed);
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * cos(speed)
		- game->player.plane_y * sin(speed);
	game->player.plane_y = old_plane_x * sin(speed) + game->player.plane_y
		* cos(speed);
}
