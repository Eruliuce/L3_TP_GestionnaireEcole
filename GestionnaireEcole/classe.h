#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED

#include "structures.h"
#include "etudiant.h"

void cl_creerEtudiant(Classe* c, LinkedList** listeEtudiants, char* nom, char* prenom, int numero);
void cl_creerCours(Classe* c, LinkedList** listeCours, char* matiere, Professeur* prof);

#endif // CLASSE_H_INCLUDED
