#ifndef COURS_H_INCLUDED
#define COURS_H_INCLUDED

#include "Outils/linkedlist.h"
#include "professeur.h"
#include "salle.h"
#include "classe.h"

typedef struct Cours Cours;
struct Cours
{
    char *matiere;
    struct Professeur *prof;
    Classe *classe;
    LinkedList *listeSeances;
};

void creerCours(LinkedList* listeCours, char* matiere, Professeur* p, Classe *c);

#endif // COURS_H_INCLUDED
