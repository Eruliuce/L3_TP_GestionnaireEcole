#include "seance.h"

void creerSeance(Cours *c, Salle *sa, char *date, char *horaire)
{
    Seance *s = (Seance*)malloc(sizeof(Seance));
    s->salle = sa;
    s->date = date;
    s->horaire = horaire;
    ll_push((&(c->listeSeances)), s);
}
