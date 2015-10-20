#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED

#include "typedef.h"
#include "Outils/linkedlist.h"
#include "professeur.h"
#include "classe.h"
#include "etudiant.h"
#include "cours.h"
#include "note.h"
#include "salle.h"
#include "seance.h"

typedef struct Ecole Ecole;
struct Ecole
{
    char *nom;
    char *adresse;
    LinkedList *listeSalles;
    LinkedList *listeProfs;
    LinkedList *listeEtudiants;
};

Ecole* ec_genererEcole();
void ec_creerSalle(char bat, int etage, int num, LinkedList *listeSalles);
void ec_ajouterProfesseur(Professeur *p);
void ec_creerClasse(char* annee, char* formation);
void ec_ajouterEtudiant(Etudiant *e);

#endif // ECOLE_H_INCLUDED
