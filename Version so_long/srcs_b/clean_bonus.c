/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:59:28 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 12:37:49 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_b/mlix_bonus.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		map->grid[i] = NULL;
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	xpm_to_mlx_image2_for_destroy(t_mlix *mlx, t_imgs *img)
{
	if (img->ptr)
		mlx_destroy_image(mlx->mlx_ptr, img->ptr);
	img->ptr = NULL;
}

void	xpm_to_mlx_image1_for_destroy(t_mlix *mlx)
{
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->img_main);
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->sol);
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->wall);
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->col);
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->exit);
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->player);
}

void	ft_clean(t_mlix *mlx, int index, char *msg)
{
	if (mlx)
	{
		if (mlx->mlx_ptr)
		{
			xpm_to_mlx_image1_for_destroy(mlx);
			if (mlx->mlx_win)
				mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
			mlx_destroy_display(mlx->mlx_ptr);
			free(mlx->mlx_ptr);
			mlx->mlx_ptr = NULL;
		}
		if (mlx->map.grid)
			free_map(&mlx->map);
	}
	if (index == 1)
	{
		ft_printf("%s\n", msg);
		exit(EXIT_SUCCESS);
	}
	ft_printf("%s%s\n", ERROR, msg);
	exit(EXIT_FAILURE);
}
