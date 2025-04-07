#include "cub3d.h"


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
			if (!ft_strchr("10NSWE ", maps->grid[j][i]))
			{
				printf("Other characters than 1 0 were found\n");
				printf(" Element found[%d][%d]: %c\n", j, i, maps->grid[j][i]);
				return;
				// break;
			}

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

//si fichier vide ->obligatoire "Error", avec un autre msg
//si fichier invalide -> obligatoire "Error", avec un autre msg
//si ya pas de joueur -> obligatoire "Error", avec un autre msg
//si map trop petite (que des 1 ou 0), consideree comme pas de joueur-> obligatoire "Error", avec un autre msg
//si map pas complètement entoure de murs -> obligatoire "Error", avec un autre msg
//si ya des lignes vides -> obligatoire "Error", avec un autre msg
//si ya des caracteres autres que 1, 0, N, S, E, W -> obligatoire "Error", avec un autre msg
//si ya double player -> obligatoire "Error", avec un autre msg
//si ya pas de map -> obligatoire "Error", avec un autre msg
//si ya pas de texture -> obligatoire "Error", avec un autre msg
//si ya pas de couleur -> obligatoire "Error", avec un autre msg
//si la map pas en derniere position -> obligatoire "Error", avec un autre msg
//si player sur ligne de bordure -> obligatoire "Error", avec un autre msg
//si pas le bon extension ou mauvais extension -> obligatoire "Error", avec un autre msg
//si la map est bien entoure de murs , et que ya des '1' et '0' en dehors -> c'est bon
//si map en derniere position et que ya espace vide apres -> c'est bon

//a check la fin de la map avec '\n' '\t' ' ', c'est bizarre

//a voir comment faire quand ya '\t' et ' ' :
///quand c'est une ligne vide ca doit envoyer erreur
///quand c'est non vide ca doit pas envoyer erreur