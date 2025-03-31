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
        for (int k = 0; maps->grid[j][k] != '\0'; k++) // Parcours des colonnes
            printf("[%c]", maps->grid[j][k]);          // Affiche chaque caractère avec des crochets
        printf("\n");                                  // Nouvelle ligne après chaque ligne affichée
    }
}

/// A verifier si on prends en compte ce cas ou pas dans la lecture
// char *check_end_of_line(char *line, int fd)
// {
//     line = get_next_line(fd);
//     if (!line)
//         return (NULL);
//     if (line[ft_strlen(line) - 1] == '\n')
//         line[ft_strlen(line) - 1] = '\0';
//     return (line);
// }
void free_map(t_map *maps)
{
    int i;

    i = 0;
    while (i < maps->index_for_free)
    {
        free(maps->grid[i]);
        maps->grid[i] = NULL;
        i++;
    }
    free(maps->grid);
    maps->grid = NULL;
}

void fill_the_grid(t_map *maps, t_obj_reader tete_lecture, char *line)
{
    char c;
    int i = 0;
    int line_len = 0;

    while ((c = obj_reader_peek(&tete_lecture)) != 0)
    {
        if (c != -1 && c != '\n')
            line[line_len++] = c;
        if (c == -1)
            break;
        if (c == '\n')
            printf("\n");
        line[line_len] = '\0';
        // maps->grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i + 2));
        // if (!maps->grid)
        //     printf("Erreur d'allocation pour maps->grid\n");
        
        char **new_grid = ft_realloc(maps->grid, sizeof(char *) * i, sizeof(char *) * (i + 2));
        if (!new_grid)
        {
            printf("Erreur d'allocation pour maps->grid\n");
            return; // Ou gérer autrement si nécessaire
        }
        maps->grid = new_grid;
        printf("Copie de la ligne: '%s'\n", line);

        maps->grid[i] = ft_strdup(line);
        if (!maps->grid[i]) // Vérifie que strdup n’a pas échoué
            printf("Erreur d'allocation pour maps->grid[%d]\n", i);
        printf("[%d] : %s\n", i,maps->grid[i]);
        i++;
        maps->index_for_free++;
        line_len = 0;
        obj_reader_next(&tete_lecture);
    }
}

void is_valid_borders(t_map *maps)
{
    int j;
    int i;

    i = 0;
    j = 0;
    // while (!ft_strchr(" ", maps->grid[i][j]))
    // {
    //     // j = 0;

    //     if (!ft_strchr("1", maps->grid[i][j]))
    //         printf("Other characters than 1 were found\n");
    //     i++;
    // }
    // printf("largeur : %d\n", i);
    // printf("que de '1' in ligne one \n");

    while (maps->grid[i] && (ft_strchr("10 ", maps->grid[i][j]) || ft_strchr(" ", maps->grid[i][j])))
    {
        printf("grid[%d][%d] = '%c'\n", i, j, maps->grid[i][j]);
        if (ft_strchr(" ", maps->grid[i][j]))
        {
            printf("hauteur + 1 \n");
            maps->height++;
        }
        i++;
    }
    printf("hauteur : %d\n", maps->height);

    /*   while (ft_strchr("10", maps->grid[i][j]) || ft_strchr(" ", maps->grid[i][j]))
  {
      // j = 0;

      if (!ft_strchr(" ", maps->grid[i][j]))
      {
          printf("hauteur + 1 \n");
          maps->height++;
      }
      i++;
  } */

    // j = 0;
    // printf("h :%d\n", maps->height);

    // maps->height--;
    // maps->height--;

    // printf("h :%d\n", maps->height);
    // while (!ft_strchr(" ", maps->grid[maps->height][j]))
    // {
    //     // j = 0;
    //     // printf("valeur [%d][%d]: %s\n", maps->height, j, maps->grid[maps->height]);
    //     //  printf("valeur [%d][%d]: %s\n", maps->height - 1, j, maps->grid[maps->height - 1]);
    //     // if (ft_strchr("1", maps->grid[maps->height][j]))

    //     // maps->height--;
    //     // printf("1valeur [%d][%d]: %s\n", maps->height, j, maps->grid[maps->height]);

    //     if (!ft_strchr("1", maps->grid[maps->height][j]))
    //     {
    //         // printf("valeur [%d][%d]: %c\n", maps->height - 2, j, maps->grid[maps->height - 2][j]);

    //         printf("Other characters than 1 were found\n");
    //     }
    //     maps->height--;

    //     // printf("2valeur [%d][%d]: %s\n", maps->height, j, maps->grid[maps->height]);
    // }
    // printf("que de '1' in last line \n");
}

// void check_all_conditions(t_map *maps)
// {

//     int i;
//     int j;
//     i = 0;
//     j = 0;
//     // while (maps->grid[i][j])
//     // {
//     //     if (!ft_strchr("10", maps->grid[i][j]))
//     //     {
//     //         printf("Other characters than 1 0 were found[%d][%d]: %c\n", i, j, maps->grid[i][j]);
//     //         break;
//     //     }
//     //     i++;
//     // }
//     // printf("Other characters than 1 were found\n");

//     // while (ft_strchr("\0", maps->grid[i][j]))
//     // {
//     //     if (!ft_strchr("10", maps->grid[i][j]))
//     //     {
//     //         printf("Other characters than 1 were found\n");
//     //         printf("valeur [%d][%d]: %c\n", i, j, maps->grid[i][j]);
//     //         break;
//     //     }

//     //     i++;
//     // }

//     // printf("valeur [0][0]: %c\n", maps->grid[0][0]);
//     // printf("valeur [0]: '%s'\n", maps->grid[0]);

//     // printf("valeur [1][0]: %c\n", maps->grid[1][0]);
//     // printf("valeur [2][0]: %c\n", maps->grid[2][0]);
//     // printf("valeur [2][1]: * ' %c ' *\n", maps->grid[2][1]);
//     // printf("valeur [3][0]: + %c +\n", maps->grid[3][0]);

//     // printf("valeur [3][1]: * ' %c ' *\n", maps->grid[3][1]);
//     // printf("valeur [3][2]: + %c +\n", maps->grid[3][2]);
// }
int read_file(t_map *maps, int fd)
{
    t_obj_reader tete_lecture;
    char line[BUFFER_SIZE]; // Stocke la ligne courante
    tete_lecture = obj_create_reader(fd, line, BUFFER_SIZE);
    if (!maps)
    {
        printf("Erreur : maps est NULL\n");
        return (0);
    }
    // init_vars(maps);
    fill_the_grid(maps, tete_lecture, line);
    printf("\n");
    is_valid_borders(maps);
    // check_all_conditions(maps);
    return (1);
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
    if (read_file(maps, fd) == 1)
    {
        printf("\n");
        printf("c good3");
    }
    close(fd);
    free_map(maps);
    return (1);
    /*    line = check_end_of_line(line, fd);
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
}

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
