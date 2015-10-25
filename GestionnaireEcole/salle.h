#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

#include "Outils/linkedlist.h"

typedef struct Salle Salle;
struct Salle
{
    char *bat;
    char *nom;
};

void creerSalle(LinkedList *listeSalles, char* bat, char* nom);

#endif // SALLE_H_INCLUDED
