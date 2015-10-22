#include "graphe.h"


int grapheExistant = 0;
char* save;
char chemin[50];

void menu1(TypGraphe* G);
void menu2(TypGraphe* G);

void menu1(TypGraphe* G)
{
	int choix;

	printf("1) Création d'un graphe\n");
	printf("2) Lecture d'un graphe\n");
	printf("3) Quitter\n");
	scanf("%d",&choix);
	scanf("%*[^\n]s");
	getchar();
	switch(choix)
	{
		case 1:
		{
			G = creerGraphe();
			afficheGraphe(G);
			grapheExistant = 1;
			menu2(G);
		}
		break;
		case 2:
		{
			
		}
		break;
		case 3:
		{
			exit(-1);
		}
		break;
		default:
		{
			printf("> Commande invalide\n");
			menu1(G);
		}
	}
}

void menu2(TypGraphe* G)
{	
	int choix;
	printf("1) Création d'un graphe\n");
	printf("2) Lecture d'un graphe\n");
	printf("3) Insertion d'un sommet\n");
	printf("4) Insertion d'une arête\n");
	printf("5) Suppression d'un sommet\n");
	printf("6) Suppression d'une arête\n");
	printf("7) Affichage\n");
	printf("8) Sauvegarde\n");
	printf("9) Quitter\n");
	scanf("%d",&choix);
	scanf("%*[^\n]s");
	getchar();
	switch(choix)
	{
		case 1:
		{
			G = creerGraphe();
			afficheGraphe(G);
			grapheExistant = 1;
			menu2(G);
		}
		break;
		case 2:
		{
			menu2(G);
		}
		break;
		case 3:
		{
			printf(">> Insertion d'un sommet\n\n");
			G->size++;
			G->voisins[G->size] = (TypVoisins*)malloc(sizeof(TypVoisins*));
			G->voisins[G->size] = NULL;
			menu2(G);
		}
		break;
		case 5:
		{
			printf(">> Suppression d'un sommet\n\n");
			printf("Sommet à supprimer (1 à %d) : ", G->size);
			scanf("%d",&choix);
			scanf("%*[^\n]s");
			getchar();
			supprimeSommet(G,choix);
			menu2(G);
		}
		break;
		case 7:
		{
			afficheGraphe(G);
			menu2(G);
		}
		break;
		case 8:
		{
			FILE* f;
			save = (char*)malloc(20*sizeof(char));
			printf("Saisir le nom du fichier : ");
			scanf("%s",save);
			scanf("%*[^\n]s");
			getchar();
			sprintf(chemin, "./sauvegarde/%s.txt", save);
			f = fopen(chemin, "w+");
			if(f == NULL)
			{
				perror("Error opening file");
			}
			else
			{
				sauvegardeGraphe(G,f);
				printf("...Sauvegarde dans %s.txt..\n", save);
				printf("\n");
			}
			fclose(f);
			free(save);
			menu2(G);
		}
		case 9:
		{
			exit(-1);
		}
		break;
		default:
		{
			printf("> Commande invalide\n");
			menu2(G);
		}
	}
}

int main()
{
	TypGraphe* G;
	printf("+--------------------+\n");
	printf("|  APPLICATION GRAF  |\n");
	printf("+--------------------+\n");
	printf("\n");
	menu1(G);
}
		
	

	
