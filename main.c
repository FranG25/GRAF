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
			lectureGraphe(G);
			menu2(G);
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
	int sommet, cible, poids;
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
			menu2(G);
		}
		break;
		case 2:
		{
			lectureGraphe(G);
			menu2(G);
		}
		break;
		case 3:
		{
			insertionSommet(G);
			menu2(G);
		}
		break;
		case 4:
		{
			insertionArete(G);
			menu2(G);
		}
		break;
		case 5:
		{
			suppressionSommet(G);
			menu2(G);
		}
		break;
		case 6:
		{
			suppressionArete(G);
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
			sauvegardeGraphe(G);
			menu2(G);
		}
		case 9:
		{
			printf("Fermeture de l'application.\n");
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
		
	

	
