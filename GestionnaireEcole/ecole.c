#include <stdlib.h>

#include "ecole.h"

Ecole* genererEcole()
{
    Ecole *ec = (Ecole*)malloc(sizeof(Ecole));
    ec->nom = "EFREI";
    ec->adresse = "30 Avenue de la Republique";
    ec->listeSalles = NULL;
    ec->listeEtudiants = NULL;
    ec->listeProfs = NULL;
    ec->listeCours = NULL;

    return ec;
}

