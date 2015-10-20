#ifndef PROFESSEUR_H_INCLUDED
#define PROFESSEUR_H_INCLUDED

#include "ecole.h"

struct Professeur
{
    int num;
    char *nom;
    char *prenom;
    LinkedList *listeCours;
};

#endif // PROFESSEUR_H_INCLUDED
