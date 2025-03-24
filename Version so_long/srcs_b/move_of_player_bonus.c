/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_of_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:09:15 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 11:51:55 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_b/mlix_bonus.h"

void	player_movements(t_mlix *mlx, int new_y, int new_x)
{
	if (new_x < 0 || new_x >= mlx->map.width || new_y < 0
		|| new_y >= mlx->map.height)
		return ;
	if (mlx->map.grid[new_y][new_x] == '1')
		return ;
	if (mlx->map.grid[new_y][new_x] == 'C')
	{
		mlx->collect.collect_count_c++;
		mlx->map.grid[new_y][new_x] = '0';
		ft_printf("Collectible picked up: %d\n", mlx->collect.collect_count_c);
	}
	if (mlx->map.grid[new_y][new_x] == 'E')
	{
		if (mlx->collect.collect_count_c == mlx->count_check.total_c)
			ft_clean(mlx, 1, "Victory");
		else
			return ;
	}
	mlx->new_pos_player.x = new_x;
	mlx->new_pos_player.y = new_y;
	mlx->moves++;
	ft_printf("Moves: %d\n", mlx->moves);
}

void	render_map(t_mlix *mlx)
{
	if (mlx->pos_player.x >= 0 && mlx->pos_player.x < mlx->map.width
		&& mlx->pos_player.y >= 0 && mlx->pos_player.y < mlx->map.height)
	{
		mlx->map.grid[mlx->pos_player.y][mlx->pos_player.x] = '0';
		copy_pixel_to_image(mlx, &mlx->sol, mlx->pos_player.x * TILESIZE,
			mlx->pos_player.y * TILESIZE);
	}
	mlx->pos_player.x = mlx->new_pos_player.x;
	mlx->pos_player.y = mlx->new_pos_player.y;
	if (mlx->new_pos_player.x >= 0 && mlx->new_pos_player.x < mlx->map.width
		&& mlx->new_pos_player.y >= 0
		&& mlx->new_pos_player.y < mlx->map.height)
	{
		mlx->map.grid[mlx->new_pos_player.y][mlx->new_pos_player.x] = 'P';
		copy_pixel_to_image(mlx, &mlx->player, mlx->new_pos_player.x * TILESIZE,
			mlx->new_pos_player.y * TILESIZE);
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img_main.ptr, 0,
		0);
}

void	display_moves_on_screen(t_mlix *mlx)
{
	char	*move_count;

	move_count = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 10, 20, 255, "Moves:");
	mlx_string_put(mlx->mlx_ptr, mlx->mlx_win, 50, 21, 255, move_count);
	if (move_count)
		free(move_count);
}
