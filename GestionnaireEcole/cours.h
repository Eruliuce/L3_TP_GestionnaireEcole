#ifndef COURS_H_INCLUDED
#define COURS_H_INCLUDED

#include "structures.h"
#include "professeur.h"
#include "classe.h"

void co_affecterProfesseur(Cours* c, Professeur* professeur);
void co_creerSeance(Cours* c, Salle* s, char* date, char* horraire);

#endif // COURS_H_INCLUDED
