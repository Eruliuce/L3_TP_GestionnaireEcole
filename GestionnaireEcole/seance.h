#ifndef SEANCE_H_INCLUDED
#define SEANCE_H_INCLUDED

#include "salle.h"
#include "cours.h"

typedef struct Seance Seance;
struct Seance
{
    Salle *salle;
    char *date;
    char *horaire;
};

void creerSeance(Cours *c, Salle *sa, char *date, char *horaire);

#endif // SEANCE_H_INCLUDED
