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
            printf("[%c]", maps->grid[j][k]);          // Affiche chaque caractère avec des crochets
        printf("\n");                                  // Nouvelle ligne après chaque ligne affichée
    }
}

char *read_string_map(t_obj_reader *reader /* , int flag */)
{
    char *str = NULL;
    size_t len = 0;
    int16_t c;
    char temp[1024];

    // if (flag == 0)
    // {
    skip_whitespace_map(reader);
    while ((c = obj_reader_peek(reader)) != -1 && c != '\n' && c != '\t')
    {
        if (len < sizeof(temp) - 1)
            temp[len++] = c;
        obj_reader_next(reader);
        if (c == '\0')
            break;
    }
    if (len == 0)
    return NULL;
    str = malloc((len + 1) * sizeof(char));
    if (!str)
    return NULL;
    ft_memcpy(str, temp, len);
    str[len] = '\0';
    return str;
}
// }
// else
// {
//     skip_whitespace_map(reader);
//     c = obj_reader_peek(reader);
//     while ((c = obj_reader_peek(reader)) != -1 && c != '\n' && c != '\t')
//     {
//         if (len < sizeof(temp) - 1)
//             temp[len++] = c;
//         obj_reader_next(reader);
//         if (c == '\0')
//             break;
//     }
// }

void create_line_of_map(t_map *maps, char *line, int i)
{
    maps->grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i + 2));
    if (!maps->grid)
        ft_clean_up(maps, 0, "Allocation failed for maps->grid");
    maps->grid[i] = ft_strdup(line);
    if (!maps->grid[i])
        ft_clean_up(maps, 0, "Allocation failed for maps->grid[i]");
    maps->height++;
    free(line);
    printf("[%d] : %s\n", i, maps->grid[i]);
}
void find_max_width(t_map *maps)
{
    int max_width = 0;
    int i = 0;

    if (!maps->grid)
        return;
    while (maps->grid[i])
    {
        int width = ft_strlen(maps->grid[i]);
        if (width > max_width)
            max_width = width;
        i++;
    }
    maps->width = max_width;
}
void fill_the_grid(t_map *maps, t_obj_reader tete_lecture, char *line)
{
    int i = 0;
    // int flag;
    char c;

    // flag = 0;
    line = read_string_map(&tete_lecture /* , flag */);
    if (line[0] == '\0')
    {
        free(line);
        ft_clean_up(maps, 0, "No existing map");
    }
    // flag = 1;
    // maps->width = ft_strlen(line);
    while (line && line[0] != '\0')
    {
        create_line_of_map(maps, line, i);
        if ((c = obj_reader_peek(&tete_lecture)) == '\n')
        {
            obj_reader_next(&tete_lecture);
            // printf("here \n");
            if ((c = obj_reader_peek(&tete_lecture)) == '\n' /*  || c == '\t' || c == ' ' || c == '\0' */)
                ft_clean_up(maps, 0, "Empty line in map");
        }
        i++;
        line = read_string_map(&tete_lecture /* , flag */);
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
        ft_clean_up(maps, 0, "Map is NULL"); // peut etre inutile
    fill_the_grid(maps, tete_lecture, line);
    return (1);
}
// {
//     printf("Wrong file extension\n");
//     return (EXIT_FAILURE);
// }

// {
//     printf("No file found");
//     return (EXIT_FAILURE);
// }
int check_map_file(t_map *maps, char **av)
{
    int fd;
    t_obj_reader reader;
    char buffer[BUFFER_SIZE];

    if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
        ft_clean_up(maps, 0, "Wrong file extension");
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        ft_clean_up(maps, 0, "No file found");
    reader = obj_create_reader(fd, buffer, BUFFER_SIZE);
    if (!parse_map_config(&reader, maps))
        ft_clean_up(maps, 0, "Error parsing map configuration");
    if (!read_file(maps, fd))
    {
        close(fd);
        ft_clean_up(maps, 0, "Error reading map data");
    }
    check_all_conditions(maps);
    check_N_S_W_E_elements(maps);
    call_flood_fill(maps);
    close(fd);
    ft_clean_up(maps, 1, "Map configuration and data parsed successfully");
    return (1);
}
// if (read_file(maps, fd) == 1)
// {
//     check_all_conditions(maps);
//     check_N_S_W_E_elements(maps);
//     call_flood_fill(maps);
//     close(fd);
//     ft_clean_up(maps, 1, "Map configuration and data parsed successfully");
// }
// else
// {
//     close(fd);
//     ft_clean_up(maps, 0, "Error reading map data");
// }
// return (EXIT_SUCCESS);

// {
//     printf("Error parsing map configuration\n");
//     close(fd);
//     free_map(maps);
//     return (EXIT_FAILURE);
// }

// {
//     printf("Error reading map data\n");
//     close(fd);
//     free_map(maps);
//     return (EXIT_FAILURE);
// }
// close(fd);
// free_map(maps);