#ifndef NA_LISTE_H
#define NA_LISTE_H

#include "memoire.h"

typedef struct s_liste {
	int voisin;
	int poids;
	struct s_liste* suiv;
} TypVoisins;


void supprimeListe(TypVoisins** l, int voisin);

void ajouteListe(TypVoisins** l, int voisin, int poids);

#endif
