#ifndef NA_CONCAT_H
#define NA_CONCAT_H

#define TAILLE_MAX 200

#include "liste.h"

typedef struct
{
	int size;
	int oriente;
	int pondere;
	TypVoisins** voisins;
} TypGraphe;


void ajouteVoisin(TypGraphe* G, int sommet, int voisin, int poids);

//Création d'un nouveau graphe par le biais d'une procédure guidée.
TypGraphe* creerGraphe();

//Affichage du graphe dans le même format que celui de la sauvegarde
void afficheGraphe(TypGraphe* G);

//Affiche les arêtes (et donc les voisins)
void afficheVoisin(TypGraphe* G);

//Ajoute dans un tableau d'entier les voisins possible pour la création d'un graphe. Retourne le nom de voisin possible.
int listeVoisinsPossible(TypGraphe* G, int* possible, int s);

//Indique si le sommet i est présent dans les voisins de v
int presenceVoisin(TypGraphe* G, int i, int v);

//Insert une nouvelle arête dans le graphe G
void insertionArete(TypGraphe* G);

//Insert un nouveau sommet dans le graphe G
void insertionSommet(TypGraphe* G);

//Procédure pour la suppression d'un sommet
void suppressionSommet(TypGraphe* G);

//Supprime un sommet du graphe G
void supprimeSommet(TypGraphe* G, int sommet);

//Supprime une arête (et donc un voisin) pour le sommet "sommet"
void supprimeVoisin(TypGraphe* G, int sommet, int voisin);

//
void decrementerTransition(TypGraphe* G, int p);

//Sauvegarde le graphe courant dans le dossier sauvegarde et dans le bon format
int sauvegardeGraphe(TypGraphe* G);

//Etape dans la sauvegarde du graphe pour sauvegarder chaque arête
int sauvegardeVoisin(TypGraphe* G, FILE* f);

int choixSommet(int* possible, int size);

//Chargement d'un graphe depuis un fichier texte respectant le même format que celui de la sauvegarde et l'affichage
int lectureGraphe(TypGraphe* G);


#endif
