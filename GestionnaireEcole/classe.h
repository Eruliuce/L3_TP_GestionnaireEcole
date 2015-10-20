#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED

#include "ecole.h"


struct Classe
{
    char *annee;
    char *formation;
    LinkedList *listeEtudiants;
    LinkedList *listeCours;
};

void cl_creerEtudiant(LinkedList** listeEtudiants, char* nom, char* prenom, int numero, Classe* c);
void cl_creerCours(LinkedList** listeCours, Classe* c, char* matiere, Professeur* prof);

#endif // CLASSE_H_INCLUDED
