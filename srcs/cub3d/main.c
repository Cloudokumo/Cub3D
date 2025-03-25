#include "cub3d.h"

char	*check_end_of_line(char *line, int fd)
{
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

int check_map_file(const char *file_path)
{
	int	fd;
    int i;
	char *line;

    line = NULL;
    i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		printf("No file found");
    line = check_end_of_line(line, fd);
    if (!line)
       printf("file is empty");
    return (0);
}

int directions_setup(int fd)
{
    int tab[4];
    memset(tab, 0, 4);

    int i;
    char *line;
    i = 0;
    line = NULL;
    line = check_end_of_line(line, fd);
    if (!line)
        return(1);
    return (0);
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


int main(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Wrong number of arguments\n");
        return (0);
    }
   	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
        printf("Wrong file extension\n");
	
    return (0);
}



/* #texture1 W
11110011
11100111
11100111
11100111
11100111
11111111
#texture2 S

recuperation_de_texture(t_obj_reader *tete_lecture)
{
    int i = 0;
    texture = malloc taille
    obj_reader_next(tete_lecture);
    while (obj_reader_peek(tete_lecture) != ' ')
    {
        texture[i] = obj_reader_peek(tete_lecture);
        i++;
        obj_reader_next(tete_lecture);
    }
    recupration_sudestnordouest();

}

buffer[4096]
t_obj_reader tete_lecture = obj_create_reader(1, buffer, 4096);
obj_reader_peek(&tete_lecture);
obj_reader_next(&tete_lecture);
while mon ficher a du contenu
{
    si peek == ' '
        skip_space(&tete_lecture);
    si peek == '#'
        recuperation_de_texture(&tete_lecture);
    si peek == '1'
        recuperation_de_la_map(&tete_lecture);
    sinon 
        gestion_erreur(&tete_lecture); // affichage de la ligne, colone et du caractere
} */