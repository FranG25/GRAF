#include "graphe.h"


int grapheExistant = 0;

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
		}
		break;
		case 2:
		{
			menu2(G);
		}
		break;
		case 5:
		{
			printf(">> Suppression d'un sommet\n");
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
	menu1(G);
}
		
	

	
