#include "professeur.h"

void creerProfesseur(LinkedList **listeProfs, char* nom, char* prenom)
{
    static unsigned int nextNum = 1;
    Professeur *p = (Professeur*)malloc(sizeof(Professeur));
    p->num = nextNum;
    nextNum++;
    p->nom = nom;
    p->prenom = prenom;
    p->listeCours = NULL;
    ll_push(listeProfs, p);
}

