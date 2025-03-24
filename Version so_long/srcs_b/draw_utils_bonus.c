/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:10:57 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/12 19:05:01 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_b/mlix_bonus.h"

void	xpm_to_mlx_image(t_mlix *mlx, char *path, t_imgs *img)
{
	if (img == &mlx->img_main)
	{
		mlx->img_main.ptr = mlx_new_image(mlx->mlx_ptr, mlx->map.width
				* TILESIZE, mlx->map.height * TILESIZE);
		mlx->img_main.height = mlx->map.height * TILESIZE;
		mlx->img_main.width = mlx->map.width * TILESIZE;
	}
	else
		img->ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &img->width,
				&img->height);
	if (!img->ptr)
		ft_clean(mlx, 0, "Failed to load XPM collectible image\n");
	img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->sizeline,
			&img->endian);
	if (!img->data || img->width <= 0 || img->height <= 0 || img->bpp <= 0
		|| img->sizeline <= 0)
	{
		ft_printf("Invalid properties for image %s\n", path);
		ft_clean(mlx, 0, NULL);
	}
}

void	initialize_xpm_to_mlx_image(t_mlix *mlx)
{
	xpm_to_mlx_image(mlx, NULL, &mlx->img_main);
	xpm_to_mlx_image(mlx, SOL, &mlx->sol);
	xpm_to_mlx_image(mlx, WALL, &mlx->wall);
	xpm_to_mlx_image(mlx, COLLECTIBLE, &mlx->col);
	xpm_to_mlx_image(mlx, EXIT, &mlx->exit);
	xpm_to_mlx_image(mlx, PLAYER_DOWN, &mlx->player);
}
