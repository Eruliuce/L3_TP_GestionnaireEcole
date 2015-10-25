#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED

#include "Outils/linkedlist.h"
#include "professeur.h"
#include "classe.h"
#include "etudiant.h"
#include "salle.h"

typedef struct Ecole Ecole;
struct Ecole
{
    char *nom;
    char *adresse;
    LinkedList *listeSalles;
    LinkedList *listeProfs;
    LinkedList *listeEtudiants;
    LinkedList *listeCours;
};

Ecole* genererEcole();

#endif // ECOLE_H_INCLUDED
