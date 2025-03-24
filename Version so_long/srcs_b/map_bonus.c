/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:09:19 by carzhang          #+#    #+#             */
/*   Updated: 2024/10/16 11:51:31 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_b/mlix_bonus.h"

char	*check_end_of_line(char *line, int fd)
{
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

void	create_grid(t_mlix *mlx, char *line, int i, int line_width)
{
	if (line_width != mlx->map.width)
	{
		free(line);
		ft_clean(mlx, 0, "Map no rectangular");
	}
	mlx->map.grid = ft_realloc(mlx->map.grid, sizeof(char *) * i, sizeof(char *)
			* (i + 2));
	if (!mlx->map.grid)
		ft_clean(mlx, 0, "Grid allocation failed");
	mlx->map.grid[i] = ft_strdup(line);
	mlx->map.grid[i + 1] = NULL;
	free(line);
	mlx->map.height++;
}

void	get_map_dimensions(t_mlix *mlx, const char *file_path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_clean(mlx, 0, "No file found");
	line = check_end_of_line(line, fd);
	if (!line)
		ft_clean(mlx, 0, "Empty line");
	mlx->map.width = ft_strlen(line);
	while (line)
	{
		create_grid(mlx, line, i, ft_strlen(line));
		i++;
		line = check_end_of_line(line, fd);
	}
	free(line);
	close(fd);
	is_valid_borders(mlx);
	check_all_conditions(mlx);
	check_each_elements(mlx);
	call_flood_fill(mlx);
}
