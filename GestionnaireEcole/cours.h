#ifndef COURS_H_INCLUDED
#define COURS_H_INCLUDED

#include "ecole.h"

struct Cours
{
    char *matiere;
    struct Professeur *prof;
    Classe *c;
    LinkedList *seances;
};

void co_affecterProfesseur(Cours* c, struct Professeur* professeur);
void co_creerSeance(Cours *c, Salle *s, char *date, char *horraire);

#endif // COURS_H_INCLUDED
