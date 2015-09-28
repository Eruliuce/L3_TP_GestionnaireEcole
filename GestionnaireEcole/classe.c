#include <stdlib.h>
#include "structures.h"
#include "classe.h"

void cl_creerCours(Classe* c, LinkedList** listeCours, char* matiere, Professeur* prof)
{
    Cours co = (Cours*)malloc(sizeof(Cours));
    co->matiere = matiere;
    co->prof = &prof;
    co->c = c;

    ll_push(listeCours, co);
}

void cl_creerEtudiant(Classe* c, LinkedList** listeEtudiants, char* nom, char* prenom, int numero)
{
    Etudiant e = (Etudiant*)malloc(sizeof(Etudiant));
    e->num = numero;
    e->nom = nom;
    e->prenom = prenom;
    e->c = &c;
    ll_push(listeEtudiants, e);
}

