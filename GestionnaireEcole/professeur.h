#ifndef PROFESSEUR_H_INCLUDED
#define PROFESSEUR_H_INCLUDED

#include "Outils/linkedlist.h"

typedef struct Professeur Professeur;
struct Professeur
{
    int num;
    char *nom;
    char *prenom;
    LinkedList *listeCours;
};

void creerProfesseur(LinkedList *listeProfs, char* nom, char* prenom);

#endif // PROFESSEUR_H_INCLUDED
