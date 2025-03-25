#include "cub3d.h"

char	*check_end_of_line(char *line, int fd)
{
	while (line = get_next_line(fd));
	{
        if (!line)
		    return (NULL);
	    if (line[ft_strlen(line) - 1] == '\n')
		    line[ft_strlen(line) - 1] = '\0';
    }
	return (line);
}

int read_file(char *line, int fd)
{
    line = check_end_of_line(line, fd);
    if (!line)
       printf("file is empty");
    while (line = get_next_line(fd))
    {
        if (is_map(line) != 0)
        {
            get_texture(line);
            get_color(line);
        }
    }
}

//VERSION 1
//Premiere examination de la map

//lire chaque ligne

///si ya des lignes avant check si c'est que des "1" avant le mur d'extremite (haut de map)
///check si c'est la derniere ligne avec que des "1" (au debut, pour savoir l'extremite du haut de map)
////(si oui prendre cette longueur en tant que max par defaut)

///(continuer de prendre la longueur des lignes suivante et check si plus long que celle par defaut
///si oui, le maj en tant que la ligne la plus longue)

///check si c'est la premiere ligne avec que des "1" (a la fin, pour savoir l'extremite du bas de map)
///si ya des lignes apres check si c'est que des "1" apres le mur d'extremite (bas de map)

//Deuxieme examination de la map

//lire ligne par ligne

///(check si la longueur de la ligne est inf ou egal a la longueur max(connu avec la premiere examination)
////si plus petit complete les espaces "vide" avec des "1", pour les considerer comme des murs)  
//si haut de map( extremite du haut) n'est pas que des "1", tout arreter et afficher un msg d'erreur

//check le milieu de map si c'est que des "1" et "0" et si ya "N","S", "W", "E" (si oui le marque qq part sinon continue)
///check si en dehors des 2 extremites c'est que des "1"
///check a l'interieur des 2 extremites si cest que des "1" et "0" et si ya "N","S", "W", "E" (si oui le marque qq part sinon continue)





//VERSION 2
//lire chaque ligne

///si ya des lignes avant check si c'est que des "1" avant le mur d'extremite (haut de map)
///check si c'est la derniere ligne avec que des "1" (au debut, pour savoir l'extremite du haut de map)

///check si c'est la premiere ligne avec que des "1" (a la fin, pour savoir l'extremite du bas de map)
///si ya des lignes apres check si c'est que des "1" apres le mur d'extremite (bas de map)

//si haut de map( extremite du haut) n'est pas que des "1", tout arreter et afficher un msg d'erreur

//check le milieu de map si c'est que des "1" et "0" et si ya "N","S", "W", "E" (si oui le marque qq part sinon continue)
///check si en dehors des 2 extremites c'est que des "1"
///check a l'interieur des 2 extremites si cest que des "1" et "0" et si ya "N","S", "W", "E" (si oui le marque qq part sinon continue)

int is_map(char *line)
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
}

int check_map_file(const char *file_path)
{
	int	fd;
    int i;
	char *line;

    line = NULL;
    i = 0;
    if (ft_strncmp(file_path + ft_strlen(file_path) - 4, ".cub", 4) != 0)
        printf("Wrong file extension\n");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
    {
        printf("No file found");
        return (EXIT_FAILURE);
    }
    read_file(line, fd);
}

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
