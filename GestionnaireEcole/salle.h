#ifndef SALLE_H_INCLUDED
#define SALLE_H_INCLUDED

#include "Outils/linkedlist.h"

typedef struct Salle Salle;
struct Salle
{
    char bat[100];
    char nom[100];
};

void creerSalle(LinkedList **listeSalles, char* bat, char* nom);

#endif // SALLE_H_INCLUDED
