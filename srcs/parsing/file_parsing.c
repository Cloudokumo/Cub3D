/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carzhang <carzhang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:59:51 by carzhang          #+#    #+#             */
/*   Updated: 2025/04/12 12:13:19 by carzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/// a supprimer
void print_map(t_map *maps, int i)
{
	if (!maps || !maps->grid)
	{
		printf("Erreur : maps ou maps->grid est NULL\n");
		return;
	}
	printf("Nombre de lignes : %d", i);
	for (int j = 0; j < i; j++) // Parcours des lignes
	{
		if (!maps->grid[j])
		{
			printf("maps->grid[%d] est NULL !\n", j);
		}
		for (int k = 0; maps->grid[j][k] != '\0'; k++) // Parcours des colonnes
			printf("[%c]", maps->grid[j][k]);
		// Affiche chaque caractère avec des crochets
		printf("\n");
		// Nouvelle ligne après chaque ligne affichée
	}
}

void create_line_of_map(t_map *maps, char *line, int i)
{
	maps->grid = ft_realloc(maps->grid,
							sizeof(char *) * i, sizeof(char *) * (i + 2));
	if (!maps->grid)
		ft_clean_up(maps, 1, "Allocation failed for maps->grid\n");
	maps->grid[i] = ft_strdup(line);
	if (!maps->grid[i])
		ft_clean_up(maps, 1, "Allocation failed for maps->grid[i]\n");
	maps->height++;
	free(line);
	printf("[%d] : %s\n", i, maps->grid[i]);
}

void find_max_width(t_map *maps)
{
	int max_width;
	int i;
	int width;

	max_width = 0;
	i = 0;
	if (!maps->grid)
		return;
	while (maps->grid[i])
	{
		width = ft_strlen(maps->grid[i]);
		if (width > max_width)
			max_width = width;
		i++;
	}
	maps->width = max_width;
}

void fill_the_grid(t_map *maps, t_obj_reader tete_lecture, char *line)
{
	char c;
	int i;

	i = -1;
	line = read_string_map(&tete_lecture);
	if (line[0] == '\0')
	{
		free(line);
		ft_clean_up(maps, 1, "No existing map\n");
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
				ft_clean_up(maps, 1, "Empty line after map\n");
		}
		line = read_string_map(&tete_lecture);
	}
	find_max_width(maps);
	free(line);
}

int read_file(t_map *maps, int fd)
{
	t_obj_reader tete_lecture;
	char line[4096];

	tete_lecture = obj_create_reader(fd, line, BUFFER_SIZE);
	if (!maps)
		ft_clean_up(maps, 1, "Map is NULL\n"); // peut etre inutile
	fill_the_grid(maps, tete_lecture, line);
	return (1);
}

int check_map_file(t_map *maps, char **av)
{
	int fd;
	t_obj_reader reader;
	char buffer[BUFFER_SIZE];

	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		ft_clean_up(NULL, 1, "Wrong file extension\n");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_clean_up(NULL, 1, "No file found\n");
	reader = obj_create_reader(fd, buffer, BUFFER_SIZE);
	if (!parse_map_config(&reader, maps))
		ft_clean_up(maps, 1, "Error parsing map configuration\n");
	if (!read_file(maps, fd))
	{
		close(fd);
		ft_clean_up(maps, 1, "Error reading map data\n");
	}
	check_all_conditions(maps);
	check_n_s_w_e_elements(maps);
	call_flood_fill(maps);
	close(fd);
	return (1);
}
// ft_clean_up(0, 1, "Map configuration and data parsed successfully");
