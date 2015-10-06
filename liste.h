#ifndef NA_LISTE_H
#define NA_LISTE_H

#include "memoire.h"

typedef struct s_liste {
	int state;
	struct s_liste* suiv;
} TypVoisins;

//Supprime une liste contenant la valeur v
void supprimeListe(TypVoisins** l, int v);

//Ajoute une liste
void ajouteListe(TypVoisins** l, int q);

#endif
