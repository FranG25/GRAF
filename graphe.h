#ifndef NA_CONCAT_H
#define NA_CONCAT_H

#include "liste.h"

typedef struct
{
	int size;
	int oriente;
	int pondere;
	TypVoisins** voisins;
} TypGraphe;

void ajouteVoisin(TypGraphe* G, int sommet, int voisin, int poids);

TypGraphe* creerGraphe();

void afficheGraphe(TypGraphe* G);

void afficheVoisin(TypGraphe* G);

void supprimeSommet(TypGraphe* G, int sommet);

void supprimeVoisin(TypGraphe* G, int sommet, int voisin);

void decrementerTransition(TypGraphe* G, int p);



//Construit un automate exemple pour la déterminisation
//TypGraphe* construitAutomateExempleDeterminisation();

//Crée en mémoire l'automate exemple et renvoie un pointeur vers cet automate
//TypGraphe* construitAutomateExemple();

/*
//Retourne le nombre de transitions de l'automate A
int compteTransitions (automate* A);

//Retourne 1 si l'automate A est déterministe, et 0 sinon.
int deterministe (automate* A);

//Retourne 1 si l'automate A est complet, et 0 sinon.
int complet (automate* A);




//Supprime la transition (depart, etiquette, arrivee) de l'automate A.
void supprimeTransition (automate* A, int depart, int arrivee, char etiquette);

//Supprime l'état p de l'automate A. Si l'état n'existait pas, l'automate ne change pas.
void supprimeEtat (automate* A, int p);

//Ajoute un nouvel état et retourne le numéro de celui-ci
int ajoutEtat(automate* A);

//Complète l'automate A
void completeAutomate (automate* A);

//fusionne les états p1 et p2 dans l'automate A
void fusionEtats (automate* A, int p1, int p2);

//Retourne le produit de deux automates
automate* produit(automate* au1, automate* au2);

//Retourne 1 si l'intersection est vide, 0 sinon.
int intersectionVide(automate* au1, automate* au2);

//Déterminisation d'un automate.
automate* determinise(automate* A);

//Détermine si deux états sont équivalents
int nerodeEquivalent(automate* A, int e1, int e2);

//Minimisation d'un automate
void minimiseNerode(automate* A);
*/


#endif
