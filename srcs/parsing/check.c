#include "cub3d.h"

void is_valid_borders(t_map *maps)
{
	int i;

	i = 0;
	while (i < maps->width)
	{
		if (maps->grid[0][i] != '1')
			printf("H :Map edges are invalid. [%d][%d]: %c.\n", i, 0, maps->grid[i][0]);
		else if (maps->grid[maps->height - 1][i] != '1')
			printf("B: Map edges are invalid.[%d][%d]: %c\n", i, 0, maps->grid[i][0]);
		// else
		// 	printf("H et B :Map edges are valid.\n");
		i++;
	}
	i = 0;
	while (i < maps->height)
	{
		if (maps->grid[i][0] != '1')
			printf("G: Map edges are invalid, [%d][%d]: %c.\n", i, 0, maps->grid[i][0]);
		else if (maps->grid[i][maps->width - 1] != '1')
			printf("D: Map edges are invalid.[%d][%d]: %c\n", i, 0, maps->grid[i][0]);
		// else
		// 	printf("G et D: Map edges are valid.\n");
		i++;
	}
}
// void is_valid_borders(t_map *maps)
// {
// 	int i;

// 	i = 0;
// 	while (i < maps->width)
// 	{
// 		if (maps->grid[0][i] != '1')
// 			printf("H :Map edges are invalid.\n");
// 		else if (maps->grid[maps->height - 1][i] != '1')
// 			printf("B: Map edges are invalid.\n");
// 		// else
// 		// printf("H et B :Map edges are valid.\n");
// 		i++;
// 	}
// 	i = 0;
// 	while (i < maps->height)
// 	{
// 		if (maps->grid[i][0] != '1')
// 			printf("G: Map edges are invalid.\n");
// 		else if (maps->grid[i][maps->width - 1] != '1')
// 			printf("D: Map edges are invalid.\n");
// 		// else
// 		//     printf("G et D: Map edges are valid.\n");
// 		i++;
// 	}
// }

void check_all_conditions(t_map *maps)
{
	int i;
	int j;

	j = 0;
	while (maps->grid[j])
	{
		i = 0;
		while (maps->grid[j][i])
		{
			if (!ft_strchr("10NSWE", maps->grid[j][i]))
				printf("Other characters than 1 0 were found");
			i++;
		}
		j++;
	}
}

void check_N_S_W_E_elements(t_map *maps)
{
	int i;
	int j;
	int player_found = 0;
	j = 0;
	while (maps->grid[j])
	{
		i = 0;
		while (maps->grid[j][i])
		{
			if (player_found == 1 && ft_strchr("NSWE", maps->grid[j][i]))
			{
				printf("Error: N, S, W, E elements were found again\n");
				printf("second : Element found[%d][%d]: %c\n", j, i, maps->grid[j][i]);
				return;
			}
			else if (ft_strchr("NSWE", maps->grid[j][i]))
			{
				player_found = 1;
				printf("first : Element found[%d][%d]: %c\n", j, i, maps->grid[j][i]);
			}
			i++;
		}
		j++;
	}
	printf("nb d'element 'NSWE' est 1\n");
}

int skip_whitespace_after_map(int fd)
{
	int16_t c;
	t_obj_reader reader;
    char line[4096];

	reader = obj_create_reader(fd, line, BUFFER_SIZE);
	while ((c = obj_reader_peek(&reader)) != -1)
	{
		if (c == ' ' || c == '\t' || c == '\n')
			obj_reader_next(&reader); // Ignorer les espaces blancs
		else /* if (c != ' ' && c != '\t' && c != '\n') */
		{
			printf("%c\n", c);
			obj_reader_next(&reader);
			return -1; // Retourner -1 si EOF
		}
	}
	return 0; // Retourne -1 si EOF
}
void check_after_map_is_clean(int fd)
{
	if (skip_whitespace_after_map(fd) != -1) // Si on trouve un caractère non blanc
	{
		printf("❌❌ Error: Unexpected content after map\n");
		exit(EXIT_FAILURE);
	}
	// while (obj_reader_peek(fd) != -1)
	// 	obj_reader_next(fd);
	printf("✅ No extra content after the map!\n");
}

