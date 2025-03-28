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
            continue;
        }
        // printf("Ligne %d: ", j);
        for (int k = 1; maps->grid[j][k] != '\0'; k++) // Parcours des colonnes
            printf("[%c]", maps->grid[j][k]);          // Affiche chaque caractère avec des crochets
        printf("\n");                                  // Nouvelle ligne après chaque ligne affichée
    }
}

/// A verifier si on prends en compte ce cas ou pas dans la lecture
/* char	*check_end_of_line(char *line, int fd)
{
    while (line = get_next_line(fd));
    {
        if (!line)
            return (NULL);
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
    }
    return (line);
} */
void free_map(t_map *maps)
{
    int i;

    i = 0;
    while (i < maps->height)
    {
        free(maps->grid[i]);
        maps->grid[i] = NULL;
        i++;
    }
    free(maps->grid);
    maps->grid = NULL;
}

int read_file(t_map *maps, int fd)
{
    t_obj_reader tete_lecture;
    char line[1024]; // Stocke la ligne courante
    tete_lecture = obj_create_reader(fd, line, BUFFER_SIZE);
    char c;

    if (!maps)
    {
        printf("Erreur : maps est NULL\n");
        return (0);
    }
    int i = 0;
    int line_len = 0;
    while ((c = obj_reader_peek(&tete_lecture)) != 0)
    {

        if (c != -1 && c != '\n')
        {
            line[line_len] = c;
            line_len++;
        }
        if (c == -1)
            break;
        if (c == '\n')
        {
            printf(":%s\n", line);
            line[line_len] = '\0';
            maps->grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i + 2));
            if (!maps->grid)
            {
                printf("Erreur d'allocation pour maps->grid\n");
                free_map(maps);
                return (0);
            }
            maps->grid[i] = ft_strdup(line);
            // printf("Ligne stockée dans maps->grid[%d] : '* *%s||'\n", i, maps->grid[i]);
            if (!maps->grid[i]) // Vérifie que strdup n’a pas échoué
            {
                printf("Erreur d'allocation pour maps->grid[%d]\n", i);
                free_map(maps);
                return (0);
            }

            // printf("%s", maps->grid[i]);
            i++;
            maps->height++;
            line_len = 0;
        }
        obj_reader_next(&tete_lecture);
    }
    maps->grid[i] = NULL; // Marque la fin du tableau de lignes
    // print_map(maps, i);   // Affiche la map
    return (1);
}

void init_vars(t_map *maps)
{
    maps->height = 0;
    // maps->grid = ft_calloc(sizeof(char *), 1);
}

int check_map_file(t_map *maps, char **av)
{
    int fd;
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
    // init_vars(maps);
    // read_file(maps, fd);
    if (read_file(maps, fd) == 1)
    {
        printf("\n");
        printf("c good3");
    }
    free_map(maps);
    close(fd);

    return (1);
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

/* int is_map(char *line)
{
    if (ft_strncmp(line, "NO", 2) == 0)
        return (1);
    if (ft_strncmp(line, "SO", 2) == 0)
        return (1);
    if (ft_strncmp(line, "EA", 2) == 0)
        return (1);
    if (ft_strncmp(line, "WE", 2) == 0)
        return (1);
    if (line[0] == 'C' && line[0] == 'F')
        return (1);
    else
        return (0);
} */

// tab['NO', 'SO', 'WE', 'EA'] = {0, 0, 0, 0};

// if (NO)
//     while (line[i] == ' ')
//         i++;
//     tab = [SO, WE, EA]
//     return 0
// if (NO)
//     tab = [SO, WE, EA]
//     return 0
// if (NO)
//     tab = [SO, WE, EA]
//     return 0
// if (NO)
//     tab = [SO, WE, EA]
//     return 0
// else
//     return 1;
