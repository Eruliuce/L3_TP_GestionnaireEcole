#include <stdlib.h>
#include "structures.h"
#include "cours.h"

void co_affecterProfesseur(Cours* c, Professeur* professeur)
{
    c->prof = &professeur;
}


void co_creerSeance(Cours* c, Salle* s, char* date, char* horraire)
{
    Seance se = (Seance*)malloc(sizeof(Seance));
    se.date = date;
    se.horaire = horraire;
    se.s = s;
    ll_push(&(c->listeSeance), );
}
