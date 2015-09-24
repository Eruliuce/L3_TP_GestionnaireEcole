#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED

#include "professeur.h"
#include "etudiant.h"
#include "classe.h"
#include "salle.h"
#include "ecole.h"

Ecole* ec_genererEcole();
void ec_creerSalle(char bat, int etage, int num, Salle *listeSalles);
void ec_ajouterProfesseur(Professeur *p);
void ec_creerClasse(char* annee, char* formation);
void ec_ajouterEtudiant(Etudiant *e);

#endif // ECOLE_H_INCLUDED
