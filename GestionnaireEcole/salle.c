#include "salle.h"
#include "string.h"

void creerSalle(LinkedList **listeSalles, char* bat, char* nom)
{
    Salle *s = (Salle*)malloc(sizeof(Salle));
    strcpy(s->bat, bat);
    strcpy(s->nom, nom);
    ll_push(listeSalles, s);
}

