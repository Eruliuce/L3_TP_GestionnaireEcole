#include <stdio.h>
#include <stdlib.h>

#include "ecole.h"
#include "Outils/fonctions.h"

int main()
{
    Ecole *ecole = genererEcole();

    creerSalle(ecole->listeSalles, "C", "C21");
    creerSalle(ecole->listeSalles, "C", "C22");
    creerSalle(ecole->listeSalles, "C", "C23");
    creerSalle(ecole->listeSalles, "C", "C24");
    creerSalle(ecole->listeSalles, "E", "E41");
    creerSalle(ecole->listeSalles, "E", "C42");

    creerProfesseur(ecole->listeProfs, "Achvar", "Didier");

    creerEtudiant(ecole->listeEtudiants, "Dupont", "Jean");
    creerEtudiant(ecole->listeEtudiants, "Valjan", "Jean");
    creerEtudiant(ecole->listeEtudiants, "II", "Ramses");
    creerEtudiant(ecole->listeEtudiants, "II", "Elizabeth");
    creerEtudiant(ecole->listeEtudiants, "Seize", "Louis");
    creerEtudiant(ecole->listeEtudiants, "Menfin", "Gerard");
    creerEtudiant(ecole->listeEtudiants, "Le Cinquieme Mousquetaire", "Albert");
    creerEtudiant(ecole->listeEtudiants, "Stirling", "Lindsey");
    creerEtudiant(ecole->listeEtudiants, "Sucroe", "Robinson");

    return 0;
}

