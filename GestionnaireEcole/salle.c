#include "salle.h"

void creerSalle(LinkedList *listeSalles, char* bat, char* nom)
{
    Salle *s = (Salle*)malloc(sizeof(Salle));
    s->bat = bat;
    s->nom = nom;
    ll_push(&listeSalles, s);
}
