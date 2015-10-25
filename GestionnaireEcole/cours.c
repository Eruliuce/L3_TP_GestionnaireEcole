#include "cours.h"

void creerCours(LinkedList* listeCours, char* matiere, Professeur* p, Classe *cl)
{
    Cours *c = (Cours*)malloc(sizeof(Cours));
    c->matiere = matiere;
    c->prof = p;
    c->classe = cl;
    c->listeSeances = NULL;
    ll_push(&listeCours, c);
    ll_push(&(p->listeCours), c);
}
