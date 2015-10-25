#include "classe.h"

void creerClasse(LinkedList *listeClasses, char* annee, char* formation)
{
    Classe *c = (Classe*)malloc(sizeof(Classe));
    c->annee = annee;
    c->formation = formation;
    c->listeCours = NULL;
    c->listeEtudiants = NULL;
}

