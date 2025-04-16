/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:21:32 by carzhang          #+#    #+#             */
/*   Updated: 2025/04/16 15:39:03 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_img(t_mlx *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_square(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINIMAP_SCALE)
	{
		j = -1;
		while (++j < MINIMAP_SCALE)
			put_pixel_to_img(mlx, x + j, y + i, color);
	}
}

void	draw_tile(t_game *game, int map_x, int map_y, int color)
{
	int	offset_x;
	int	offset_y;
	int	screen_x;
	int	screen_y;

	offset_x = 10;
	offset_y = HEIGHT - game->map->height * MINIMAP_SCALE - 10;
	screen_x = offset_x + map_x * MINIMAP_SCALE;
	screen_y = offset_y + map_y * MINIMAP_SCALE;
	draw_square(&game->mlx, screen_x, screen_y, color);
}

void	draw_player(t_game *game)
{
	int	offset_x;
	int	offset_y;
	int	x;
	int	y;

	offset_x = 10;
	offset_y = HEIGHT - game->map->height * MINIMAP_SCALE - 10;
	x = offset_x + game->player.pos_x * MINIMAP_SCALE;
	y = offset_y + game->player.pos_y * MINIMAP_SCALE;
	draw_square(&game->mlx, x - 2, y - 2, 0xFFBF60);
}

void	draw_minimap(t_game *game)
{
	char	cell;
	int		i;
	int		j;

	i = -1;
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (i < game->map->height && j < (int)ft_strlen(game->map->grid[i]))
			{
				cell = game->map->grid[i][j];
				if (cell == '1')
					draw_tile(game, j, i, 0x805CD4);
				else
					draw_tile(game, j, i, 0xD4C9EC);
			}
		}
	}
	draw_player(game);
}
