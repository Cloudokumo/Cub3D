#include <stdint.h>
#include  <stdlib.h>
 #include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>






/* int main(int argc, char **argv)
{
    (void)argc;
    int fd = open(argv[1], O_RDONLY);
    char buffer[4096];
    char c;
    t_obj_reader tetelecture;
    tetelecture = obj_create_reader(fd, buffer, 4096);
    while ((c = obj_reader_peek(&tetelecture)) != 0)
    {
		if (c == -1)
		{
			printf("error");
			return(0);
		}
        printf("%c", c);
        obj_reader_next(&tetelecture);
    }
} */
/*
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
} 
        
*/

/* 11111111111111
11111111111111
11100001111111
11100000001111
1111N000000111
11000000000011
11111111111111 */

/* 
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
 */