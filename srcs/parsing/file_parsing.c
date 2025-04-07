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

char *read_string_map(t_obj_reader *reader/* , int flag */)
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
    if (len == 0)
        return NULL;
    str = malloc(len + 1);
    if (!str)
        return NULL;
    ft_memcpy(str, temp, len);
    str[len] = '\0';
    return str;
}

void create_line_of_map(t_map *maps, char *line, int i)
{
    maps->grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i + 2));
    if (!maps->grid)
    {
        printf("Erreur d'allocation pour maps->grid\n");
        free_map(maps);
        return;
    }
    maps->grid[i] = ft_strdup(line);
    if (!maps->grid[i])
    {
        printf("Erreur d'allocation pour maps->grid[%d]\n", i);
        free_map(maps);
        return;
    }
    maps->height++;
    free(line);
    printf("[%d] : %s\n", i, maps->grid[i]);
}
void find_max_width(t_map *maps)
{
    int max_width = 0;
    int i = 0;

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
    line = read_string_map(&tete_lecture/* , flag */);
    if (!line)
    {
        printf("file is empty");
        return;
    }
    // flag = 1;
    // maps->width = ft_strlen(line);
    while (line && line[0] != '\0')
    {
        create_line_of_map(maps, line, i);
        if ((c = obj_reader_peek(&tete_lecture)) == '\n')
        {
            obj_reader_next(&tete_lecture);
            printf("here \n");

            if ((c = obj_reader_peek(&tete_lecture)) == '\n'/*  || c == '\t' || c == ' ' */)
            {
                printf("end of map\n");
                return;
            }
        }
        i++;
        line = read_string_map(&tete_lecture/* , flag */);
    }
    find_max_width(maps);
    if (maps->width == 0)
    {
        printf("Erreur : La largeur de la carte est nulle\n");
        free_map(maps);
        return;
    }
    printf("width : %d\n", maps->width);
    printf("height : %d\n", maps->height);
    free(line);
}

int read_file(t_map *maps, int fd)
{
    t_obj_reader tete_lecture;
    char line[4096];

    tete_lecture = obj_create_reader(fd, line, BUFFER_SIZE);
    if (!maps)
    {
        printf("Erreur : maps est NULL\n");
        return (0);
    }
    fill_the_grid(maps, tete_lecture, line);
    return (1);
}

int check_map_file(t_map *maps, char **av)
{
    int fd;
    t_obj_reader reader;
    char buffer[BUFFER_SIZE];

    if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
    {
        printf("Wrong file extension\n");
        return (EXIT_FAILURE);
    }
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        printf("No file found");
        return (EXIT_FAILURE);
    }
    reader = obj_create_reader(fd, buffer, BUFFER_SIZE);
    if (!parse_map_config(&reader, maps))
    {
        printf("Error parsing map configuration\n");
        close(fd);
        free_map(maps);
        return (EXIT_FAILURE);
    }
    if (read_file(maps, fd) == 1)
    {
        check_all_conditions(maps);
        check_N_S_W_E_elements(maps);
        call_flood_fill(maps);
        printf("Map configuration and data parsed successfully\n");
    }
    else
    {
        printf("Error reading map data\n");
        close(fd);
        free_map(maps);
        return (EXIT_FAILURE);
    }
    close(fd);
    free_map(maps);
    return (EXIT_SUCCESS);
}


