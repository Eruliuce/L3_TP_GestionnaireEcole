#include "classe.h"
#include <string.h>

void creerClasse(LinkedList **listeClasses, char* annee, char* formation)
{
    Classe *c = (Classe*)malloc(sizeof(Classe));
    strcpy(c->annee, annee);
    strcpy(c->formation, formation);
    c->listeCours = NULL;
    c->listeEtudiants = NULL;
    ll_push(listeClasses, c);
}

