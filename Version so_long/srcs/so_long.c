/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 13:35:04 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/23 13:41:59 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlix.h"

void	change_direction_player(t_mlix *mlx, int key)
{
	char	*player;

	if (key == KEY_UP || key == KEY_W)
		player = PLAYER_UP;
	else if (key == KEY_DOWN || key == KEY_S)
		player = PLAYER_DOWN;
	else if (key == KEY_LEFT || key == KEY_A)
		player = PLAYER_LEFT;
	else if (key == KEY_RIGHT || key == KEY_D)
		player = PLAYER_RIGHT;
	xpm_to_mlx_image2_for_destroy(mlx, &mlx->player);
	xpm_to_mlx_image(mlx, player, &mlx->player);
}

int	handle_keypress(int key, t_mlix *mlx)
{
	int	new_x;
	int	new_y;

	new_x = mlx->new_pos_player.x;
	new_y = mlx->new_pos_player.y;
	if (key == KEY_ESC)
		ft_clean(mlx, 1, "End of the game");
	else if (key == KEY_UP || key == KEY_W)
		new_y--;
	else if (key == KEY_DOWN || key == KEY_S)
		new_y++;
	else if (key == KEY_LEFT || key == KEY_A)
		new_x--;
	else if (key == KEY_RIGHT || key == KEY_D)
		new_x++;
	change_direction_player(mlx, key);
	player_movements(mlx, new_y, new_x);
	render_map(mlx);
	display_moves_on_screen(mlx);
	return (0);
}

int	ft_close(t_mlix *mlx)
{
	ft_clean(mlx, 1, "End of the game");
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_mlix	mlx;

	if (argc == 2)
	{
		ft_memset(&mlx, 0, sizeof(mlx));
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
			ft_clean(&mlx, 0, "Wrong file extension");
		init_vars(&mlx);
		get_map_dimensions(&mlx, argv[1]);
		if (mlx.map.height == 0)
			ft_clean(&mlx, 0, "Invalid map size");
		if (!&mlx.map)
			ft_clean(&mlx, 0, "Unable to load map");
		ft_init_mlx(&mlx);
		fill_main_image_with_differents_tiles(&mlx.img_main, &mlx);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img_main.ptr, 0,
			0);
		display_moves_on_screen(&mlx);
		mlx.collect.collect_count_c = 0;
		mlx_hook(mlx.mlx_win, KeyPress, KeyPressMask, handle_keypress, &mlx);
		mlx_hook(mlx.mlx_win, DestroyNotify, NoEventMask, ft_close, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	exit(EXIT_FAILURE);
}
