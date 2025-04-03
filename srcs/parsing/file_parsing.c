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

char *read_string_map(t_obj_reader *reader)
{
    char *str = NULL;
    size_t len = 0;
    int16_t c;
    char temp[1024];

    skip_whitespace(reader);
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

void fill_the_grid(t_map *maps, t_obj_reader tete_lecture, char *line)
{
    int i = 0;

    line = read_string_map(&tete_lecture);
    if (!line)
    {
        printf("file is empty");
        return;
    }
    maps->width = ft_strlen(line);
    while (line && line[0] != '\0')
    {
        create_line_of_map(maps, line, i);
        i++;
        line = read_string_map(&tete_lecture);
    }
    if (skip_whitespace_after_map(&tete_lecture) != 0)
    {
        printf("❌ Error: Invalid content after the map\n");
        free(line);
        return; // Arrêter le traitement si des erreurs sont trouvées
    }
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

        // check_after_map_is_clean(fd);
        printf("Map configuration and data parsed successfully\n");
    }
    else
    {
        printf("Error reading map data\n");
        close(fd);
        free_map(maps);
        return (EXIT_FAILURE);
    }
    // is_valid_borders(maps);
    // check_all_conditions(maps);
    // check_N_S_W_E_elements(maps);
    // check_after_map_is_clean(&reader);

    close(fd);
    free_map(maps);
    return (EXIT_SUCCESS);
}

/*  line = check_end_of_line(line, fd);
 if (!line)
    printf("file is empty");
 while (line = get_next_line(fd))
 {
     if (is_map(line) != 0)
     {
         get_texture(line);
         get_color(line);
     }
 } */

// VERSION 1
// Premiere examination de la map

// lire chaque ligne

/// si ya des lignes avant check si c'est que des "1" avant le mur d'extremite (haut de map)
/// check si c'est la derniere ligne avec que des "1" (au debut, pour savoir l'extremite du haut de map)
////(si oui prendre cette longueur en tant que max par defaut)

///(continuer de prendre la longueur des lignes suivante et check si plus long que celle par defaut
/// si oui, le maj en tant que la ligne la plus longue)

/// check si c'est la premiere ligne avec que des "1" (a la fin, pour savoir l'extremite du bas de map)
/// si ya des lignes apres check si c'est que des "1" apres le mur d'extremite (bas de map)

// Deuxieme examination de la map

// lire ligne par ligne

///(check si la longueur de la ligne est inf ou egal a la longueur max(connu avec la premiere examination)
////si plus petit complete les espaces "vide" avec des "1", pour les considerer comme des murs)
// si haut de map( extremite du haut) n'est pas que des "1", tout arreter et afficher un msg d'erreur

// check le milieu de map si c'est que des "1" et "0" et si ya "N","S", "W", "E" (si oui le marque qq part sinon continue)
/// check si en dehors des 2 extremites c'est que des "1"
/// check a l'interieur des 2 extremites si cest que des "1" et "0" et si ya "N","S", "W", "E" (si oui le marque qq part sinon continue)
