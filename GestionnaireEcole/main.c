#include <stdio.h>
#include <stdlib.h>

#include "ecole.h"
#include "Outils/fonctions.h"
#include "Tests/linkedlist.h"
#include "controleur.h"

int main()
{
    int i;
    Ecole *ecole = genererEcole();

    creerSalle(&(ecole->listeSalles), "C", "C21");
    creerSalle(&(ecole->listeSalles), "C", "C22");
    creerSalle(&(ecole->listeSalles), "C", "C23");
    creerSalle(&(ecole->listeSalles), "C", "C24");
    creerSalle(&(ecole->listeSalles), "E", "E41");
    creerSalle(&(ecole->listeSalles), "E", "E42");

    creerProfesseur(&(ecole->listeProfs), "Achvar", "Didier");

    creerEtudiant(&(ecole->listeEtudiants), "Dupont", "Jean");
    creerEtudiant(&(ecole->listeEtudiants), "Valjan", "Jean");
    creerEtudiant(&(ecole->listeEtudiants), "II", "Ramses");
    creerEtudiant(&(ecole->listeEtudiants), "II", "Elizabeth");
    creerEtudiant(&(ecole->listeEtudiants), "Seize", "Louis");
    creerEtudiant(&(ecole->listeEtudiants), "Menfin", "Gerard");
    creerEtudiant(&(ecole->listeEtudiants), "Le Cinquieme Mousquetaire", "Albert");
    creerEtudiant(&(ecole->listeEtudiants), "Stirling", "Lindsey");
    creerEtudiant(&(ecole->listeEtudiants), "Sucroe", "Robinson");

    creerClasse(&(ecole->listeClasses), "L3", "L3_ASYRIA");

    creerCours(&(ecole->listeCours), "maths", ll_at(&(ecole->listeProfs), 0), ll_at(&(ecole->listeClasses), 0));
    creerCours(&(ecole->listeCours), "francais", ll_at(&(ecole->listeProfs), 0), ll_at(&(ecole->listeClasses), 0));

    for(i = 0; i < ll_size(&(ecole->listeEtudiants)); i++)
    {
        affecterClasse(ll_at(&(ecole->listeEtudiants), i), ll_at(&(ecole->listeClasses), 0));
    }

    affecterNote(ll_at(&(ecole->listeEtudiants), 3), ll_at(&(ecole->listeCours), 0), 13.);
    affecterNote(ll_at(&(ecole->listeEtudiants), 3), ll_at(&(ecole->listeCours), 1), 15.5);
    affecterNote(ll_at(&(ecole->listeEtudiants), 3), ll_at(&(ecole->listeCours), 0), 16.);
    affecterNote(ll_at(&(ecole->listeEtudiants), 0), ll_at(&(ecole->listeCours), 1), 10.);

    controleur(ecole);

    return 0;
}

