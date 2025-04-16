/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 04:05:01 by adiehl-b          #+#    #+#             */
/*   Updated: 2025/04/16 15:52:36 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_line_of_map(t_map *maps, char *line, int i)
{
	maps->grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i
				+ 2));
	if (!maps->grid)
		ft_clean_up(maps, 3, "Error\nAllocation failed for maps->grid\n");
	maps->grid[i] = ft_strdup(line);
	if (!maps->grid[i])
		ft_clean_up(maps, 3, "Error\nAllocation failed for maps->grid[i]\n");
	maps->height++;
	free(line);
}

void	find_max_width(t_map *maps)
{
	int	max_width;
	int	i;
	int	width;

	max_width = 0;
	i = 0;
	if (!maps->grid)
		return ;
	while (maps->grid[i])
	{
		width = ft_strlen(maps->grid[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	maps->width = max_width;
}

void	fill_the_grid(t_map *maps, t_obj_reader tete_lecture, char *line)
{
	char	c;
	int		i;

	i = -1;
	line = read_string_map(&tete_lecture);
	if (line[0] == '\0')
	{
		free(line);
		ft_clean_up(maps, 3, "Error\nNo existing map\n");
	}
	while (line && line[0] != '\0')
	{
		create_line_of_map(maps, line, ++i);
		c = obj_reader_peek(&tete_lecture);
		if (c == '\n')
		{
			obj_reader_next(&tete_lecture);
			c = obj_reader_peek(&tete_lecture);
			if (c == '\n')
				ft_clean_up(maps, 3, "Error\nError in .cub file\n");
		}
		line = read_string_map(&tete_lecture);
	}
	find_max_width(maps);
	free(line);
}

int	read_file(t_map *maps, int fd)
{
	t_obj_reader	tete_lecture;
	char			line[4096];

	tete_lecture = obj_create_reader(fd, line, BUFFER_SIZE);
	if (!maps)
		ft_clean_up(maps, 2, NULL);
	fill_the_grid(maps, tete_lecture, line);
	return (1);
}

int	check_map_file(t_map *maps, char **av)
{
	int				fd;
	t_obj_reader	reader;
	char			buffer[BUFFER_SIZE];

	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		ft_clean_up(maps, 3, "Error\nWrong file extension\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_clean_up(maps, 3, "Error\nNo file found\n");
	reader = obj_create_reader(fd, buffer, BUFFER_SIZE);
	if (!parse_map_config(&reader, maps))
		ft_clean_up(maps, 2, NULL);
	if (!read_file(maps, fd))
	{
		close(fd);
		ft_clean_up(maps, 3, "Error\nError reading map data\n");
	}
	check_all_conditions(maps);
	check_n_s_w_e_elements(maps);
	call_flood_fill(maps);
	close(fd);
	return (1);
}
