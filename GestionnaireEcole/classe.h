#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED

#include "Outils/linkedlist.h"
#include "classe.h"
#include "professeur.h"

typedef struct Classe Classe;
struct Classe
{
    char *annee;
    char *formation;
    LinkedList *listeEtudiants;
    LinkedList *listeCours;
};

void creerClasse(LinkedList *listeClasses, char* annee, char* formation);

#endif // CLASSE_H_INCLUDED
