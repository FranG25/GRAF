#include "graphe.h"


int grapheExistant = 0;

void menu1();
void menu2(TypGraphe* G);

void menu1()
{
	int choix;
	TypGraphe* G;

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
			afficheTransition(G);
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
			menu1();
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
			grapheExistant = 1;
		}
		case 2:
		{
			grapheExistant = 1;
			menu2(G);
		}
		case 7:
		{
			menu2(G);
		}
		case 9:
		{
			exit(-1);
		}
		default:
		{
			printf("> Commande invalide\n");
			menu2(G);
		}
	}
}

/*void menu1(automate* A)
{
	int depart, arrivee, choix, n, e1, e2, etiquette;
	
	while(1)
	{
		printf("\n");
		printf("1.  Ajouter une transition.\n");
		printf("2.  Compter les transitions.\n");
		printf("3.  Déterministe?\n");		
		printf("4.  Complet?\n");
		printf("5.  Supprimer Transition .\n");
		printf("6.  Supprimer état.\n");
		printf("7.  Compléter un automate.\n");
		printf("8.  Ajouter un état.\n");
		printf("9.  Fusionner deux états.\n\n");
		printf("0.  Retour au menu.\n");
		scanf("%d",&choix);
		scanf("%*[^\n]s");
		getchar();
		
		switch(choix)
		{
			case 0:
			{
				menu(A);
			}
			break;
			case 1:
			{
				printf("départ : ");
				scanf("%d",&depart);
				scanf("%*[^\n]s");
				printf("arrivée : ");
				scanf("%d",&arrivee);
				scanf("%*[^\n]s");
				printf("étiquette : ");
				scanf("%d",&etiquette);
				scanf("%*[^\n]s");
				getchar();
				ajouteTransition(A, depart, arrivee, 'a'+etiquette);
			}
			break;
			case 2:
			{
				printf("	Il y a %d transition(s).\n", compteTransition(A));
			}
			break;
			case 3:
			{
				n = deterministe(A);
				if(n == 1)
				{
					printf("	L'automate est déterministe.\n");
				}
				else
				{
					printf("	L'automate n'est pas déterministe.\n");
				}
			}
			break;
			case 4:
			{
				n = complet(A);
				if(n == 1)
				{
					printf("	L'automate est complet.\n");
				}
				else
				{
					printf("	L'automate n'est pas complet.\n");
				}
			}
			break;
			case 5:
			{
				printf("départ : ");
				scanf("%d",&depart);
				scanf("%*[^\n]s");
				printf("arrivée : ");
				scanf("%d",&arrivee);
				scanf("%*[^\n]s");
				printf("etiquette : ");
				scanf("%d",&etiquette);
				scanf("%*[^\n]s");
				getchar();
				supprimeTransition(A, depart, arrivee, 'a'+etiquette);
			}
			break;
			case 6:
			{
				printf("Numéro de l'état à supprimer : ");
				scanf("%d",&n);
				scanf("%*[^\n]s");
				supprimeEtat(A, n);
			}
			break;
			case 7:
			{
				completeAutomate(A);
			}
			break;
			case 8:
			{
				ajoutEtat(A);
			}
			break;
			case 9: 
			{
				printf("état 1 : ");
				scanf("%d",&e1);
				scanf("%*[^\n]s");
				printf("état 2 : ");
				scanf("%d",&e2);
				scanf("%*[^\n]s");
				
				fusionEtats(A, e1, e2);
			}
			break;
		}
	}
}
				
void menu2(automate* A)
{
	int choix, n;
	
	while(1)
	{
		printf("\n");
		printf("1.  Langage vide?\n");
		printf("2.  Supprimer Non co-accessible.\n");
		printf("3.  Supprimer Non accessible.\n\n");
		printf("0.  Retour au menu.\n");
		scanf("%d",&choix);
		scanf("%*[^\n]s");
		getchar();
		
		switch(choix)
		{
			case 0:
			{
				menu(A);
			}
			break;
			case 1:
			{
				n = langageVide(A);
				if(n == 1)
				{
					printf("	Le langage reconnu par l'automate est vide.\n");
				}
				else
				{
					printf("	Le langage reconnu par l'automate n'est pas vide.\n");
				}
			}
			break;
			case 2:
			{
				supprimeNonCoAccessibles(A);
			}
			break;
			case 3:
			{
				supprimeNonAccessibles(A);
			}
			break;
			default:
			{
				printf("	Erreur, cette action n'est pas disponible.\n");
			}
		}
	}
}
	
void menu3(automate* A)
{
	int choix, res;
	automate* B = (automate*)malloc(sizeof(automate));
	
	while(1)
	{
		printf("\n");
		printf("1.  Faire le produit de deux automates.\n");
		printf("2.  Intersection du vide?.\n\n");
		printf("0.  Retour au menu.\n");
		scanf("%d",&choix);
		scanf("%*[^\n]s");
		getchar();
		
		switch(choix)
		{
			case 0:
			{
				menu(A);
			}
			break;
			case 1:
			{
				B = choixAutomate();
				A = produit(A, B);
			}
			break;
			case 2:
			{
				B = choixAutomate();
				res = intersectionVide(A,B);
				
				if(res == 1)
				{
					printf("\n	Il y a intersection.\n");
				}
				else
				{
					printf("\n	Il n'y a pas intersection.\n");
				}
			}
			break;
			default:
			{
				printf("	Erreur, cette action n'est pas disponible.\n");
			}
		}
	}
}
		
	
				
	

void menu(automate* A)
{
	int choix;

	while(1)
	{
		printf("\n");
		printf("1.  Propriétés d'un automate.\n");
		printf("2.  Test du vide.\n");
		printf("3.  Produit d'TypGraphe.\n");
		printf("4.  Déterminisation.\n");
		printf("5.  Minimisation.\n");
		printf("6.  Afficher un automate.\n");
		printf("7.  Changer d'automate.\n\n");
		printf("0.  Quitter.\n");
		scanf("%d",&choix);
		scanf("%*[^\n]s");
		getchar();
		
		switch(choix)
		{
			case 0:
			{
				exit(-1);
			}
			case 1:
			{
				menu1(A);
			}
			break;
			case 2:
			{
				menu2(A);
			}
			break;
			case 3:
			{
				menu3(A);
			}
			break;
			case 4:
			{
				determinise(A);
				printf("	L'automate a été déterminisé.\n");
			}
			break;
			case 5:
			{
				printf("Minimisation de l'automate.\n");
				minimiseNerode(A);
				afficheAutomate(A);
			}
			break;
			case 6:
			{
				afficheAutomate(A);
			}
			break;
			case 7:
			{
				A = choixAutomate();
			}
			break;
			default:
			{
				printf("	Erreur, cette action n'est pas disponible.\n");
			}
		}
	}
}
*/


int main()
{
	menu1();
}
	
		
	

	
