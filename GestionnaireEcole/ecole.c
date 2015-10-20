#include <stdlib.h>

#include "ecole.h"


Ecole* ec_genererEcole()
{
    Ecole *ec = (Ecole*)malloc(sizeof(Ecole));
    ec->nom = "EFREI";
    ec->adresse = "30 Avenue de la Republique";
    ec->listeSalles = NULL;
    ec->listeEtudiants = NULL;
    ec->listeProfs = NULL;

    return ec;
}

void ec_creerSalle(char bat, int etage, int num, LinkedList *listeSalles)
{
    /*Salle *s = (Salle*)malloc(sizeof(Salle));
    s->bat = bat;
    s->etage = etage;
    s->num = num;*/
}

