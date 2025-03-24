/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:20:11 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/12 19:04:54 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_b/mlix_bonus.h"

void	my_mlx_pixel_put(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (y * img->sizeline + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	copy_pixel_to_image(t_mlix *mlx, t_imgs *img_src, int x_start,
		int y_start)
{
	int		x;
	int		y;
	int		color;
	char	*src_pixel;

	y = 0;
	x = 0;
	while (y < TILESIZE && (y + y_start) < mlx->img_main.height)
	{
		x = 0;
		while (x < TILESIZE && (x + x_start) < mlx->img_main.width)
		{
			if (x < img_src->width && y < img_src->height)
			{
				src_pixel = img_src->data + y * img_src->sizeline + x
					* (img_src->bpp / 8);
				color = *(unsigned int *)src_pixel;
				if ((unsigned int)color != 0xFF000000)
					my_mlx_pixel_put(&mlx->img_main, x_start + x, y_start + y,
						color);
			}
			x++;
		}
		y++;
	}
}

void	get_tiles(t_mlix *mlx, int i, int j, char tile)
{
	if (tile == '1')
		copy_pixel_to_image(mlx, &mlx->wall, i, j);
	else if (tile == 'C')
		copy_pixel_to_image(mlx, &mlx->col, i, j);
	else if (tile == 'E')
		copy_pixel_to_image(mlx, &mlx->exit, i, j);
	else if (tile == 'P')
		copy_pixel_to_image(mlx, &mlx->player, i, j);
}

void	fill_main_image_with_differents_tiles(t_imgs *img_dst, t_mlix *mlx)
{
	int	i;
	int	j;

	j = 0;
	while (j < img_dst->height && mlx->map.grid[j])
	{
		i = 0;
		while (i < img_dst->width && mlx->map.grid[j][i])
		{
			if (mlx->map.grid[j][i] == 'P')
			{
				mlx->pos_player.y = j;
				mlx->pos_player.x = i;
				mlx->new_pos_player.y = j;
				mlx->new_pos_player.x = i;
			}
			copy_pixel_to_image(mlx, &mlx->sol, i * TILESIZE, j * TILESIZE);
			get_tiles(mlx, i * TILESIZE, j * TILESIZE, mlx->map.grid[j][i]);
			i++;
		}
		j++;
	}
}
