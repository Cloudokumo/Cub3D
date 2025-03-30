// #include "cub3d.h"

// char *check_end_of_line(char *line, int fd)
// {
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (NULL);
// 	if (line[ft_strlen(line) - 1] == '\n')
// 		line[ft_strlen(line) - 1] = '\0';
// 	return (line);
// }

// void free_map(t_map *maps)
// {
// 	int i;

// 	i = 0;
// 	while (i < maps->height)
// 	{
// 		free(maps->grid[i]);
// 		maps->grid[i] = NULL;
// 		i++;
// 	}
// 	free(maps->grid);
// 	maps->grid = NULL;
// }

// void print_map(t_map *maps, int i)
// {
// 	if (!maps || !maps->grid)
// 	{
// 		printf("Erreur : maps ou maps->grid est NULL\n");
// 		return;
// 	}
// 	printf("Nombre de lignes : %d\n", i);
// 	for (int j = 0; j < i; j++) // Parcours des lignes
// 	{
// 		if (!maps->grid[j])
// 		{
// 			printf("maps->grid[%d] est NULL !\n", j);
// 			continue;
// 		}
// 		// printf("Ligne %d: ", j);
// 		for (int k = 0; maps->grid[j][k] != '\0'; k++) // Parcours des colonnes
// 			printf("[%c]", maps->grid[j][k]);		   // Affiche chaque caractère avec des crochets
// 		printf("\n");								   // Nouvelle ligne après chaque ligne affichée
// 	}
// }

// void create_grid(t_map *maps, char *line, int i, int line_width)
// {
// 	if (line_width != maps->width)
// 	{
// 		free(line);
// 		printf("Map no rectangular");
// 	}
// 	maps->grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i + 2));
// 	if (!maps->grid)
// 		printf("Grid allocation failed");
// 	maps->grid[i] = ft_strdup(line);
// 	maps->grid[i + 1] = NULL;
// 	free(line);
// 	maps->height++;
// }

// void is_valid_borders(t_map *maps)
// {
// 	int i;

// 	i = 0;
// 	while (i < maps->width)
// 	{
// 		if (maps->grid[0][i] != '1')
// 			printf("Map h edges are invalid.\n");

// 		else if (maps->grid[maps->height - 1][i] != '1')
// 			printf("Map b edges are invalid.\n");
// 		else
// 			printf("haut et bas good\n");

// 		i++;
// 	}
// 	i = 0;
// 	while (i < maps->height)
// 	{
// 		if (maps->grid[i][0] != '1')
// 			printf("Map g edges are invalid.\n");

// 		else if (maps->grid[i][maps->width - 1] != '1')
// 			printf("Map d edges are invalid.\n");
// 		else
// 			printf("gauche et droit good\n");
// 		i++;
// 	}
// }

// void get_map_dimensions(t_map *maps, const char *file_path)
// {
// 	int fd;
// 	char *line;
// 	int i;

// 	i = 0;
// 	line = NULL;
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 		printf("No file found");
// 	line = check_end_of_line(line, fd);
// 	if (!line)
// 		printf("Empty line");
// 	maps->width = ft_strlen(line);
// 	while (line)
// 	{
// 		create_grid(maps, line, i, ft_strlen(line));
// 		i++;
// 		line = check_end_of_line(line, fd);
// 	}
// 	print_map(maps, i);

// 	free(line);
// 	close(fd);
// 	is_valid_borders(maps);
// }