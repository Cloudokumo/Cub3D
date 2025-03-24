/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:49:01 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/24 18:33:59 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlix.h"

void	init_vars(t_mlix *mlx)
{
	mlx->map.height = 0;
	mlx->map.grid = ft_calloc(sizeof(char *), 1);
	mlx->collect.collect_count_c = 0;
	mlx->collect.collect_count_e = 0;
	mlx->count_check.total_c = 0;
	mlx->count_check.total_p = 0;
	mlx->count_check.total_e = 0;
	mlx->moves = 0;
}

void	ft_init_mlx(t_mlix *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_clean(mlx, 0, "Unable to initialize mlx");
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, mlx->map.width * TILESIZE,
			mlx->map.height * TILESIZE, "So_long");
	if (!mlx->mlx_win)
		ft_clean(mlx, 0, "Unable to initialize window");
	initialize_xpm_to_mlx_image(mlx);
}
