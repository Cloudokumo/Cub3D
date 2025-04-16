/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiehl-b <adiehl-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:04:50 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 04:04:51 by adiehl-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_adrr(t_game *game)
{
	game->textures[0].addr = mlx_get_data_addr(game->textures[0].img,
			&game->textures[0].bits_per_pixel, &game->textures[0].line_length,
			&game->textures[0].endian);
	game->textures[1].addr = mlx_get_data_addr(game->textures[1].img,
			&game->textures[1].bits_per_pixel, &game->textures[1].line_length,
			&game->textures[1].endian);
	game->textures[2].addr = mlx_get_data_addr(game->textures[2].img,
			&game->textures[2].bits_per_pixel, &game->textures[2].line_length,
			&game->textures[2].endian);
	game->textures[3].addr = mlx_get_data_addr(game->textures[3].img,
			&game->textures[3].bits_per_pixel, &game->textures[3].line_length,
			&game->textures[3].endian);
	if (!game->textures[0].addr || !game->textures[1].addr
		|| !game->textures[2].addr || !game->textures[3].addr)
	{
		ft_putstr_fd("Image loading failed ^^\n", 2);
		return (1);
	}
	return (0);
}

int	load_textures(t_game *game)
{
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->no,
			&game->textures[0].width, &game->textures[0].height);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->so,
			&game->textures[1].width, &game->textures[1].height);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->ea,
			&game->textures[2].width, &game->textures[2].height);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx.mlx, game->map->we,
			&game->textures[3].width, &game->textures[3].height);
	if (!game->textures[0].img || !game->textures[1].img
		|| !game->textures[2].img || !game->textures[3].img)
	{
		ft_putstr_fd("Texture loading failed \n", 2);
		return (1);
	}
	if (get_adrr(game) != 0)
		return (1);
	return (0);
}
