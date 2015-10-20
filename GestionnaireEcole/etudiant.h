#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include "ecole.h"

struct Etudiant
{
    int num;
    char *nom;
    char *prenom;
    Classe *c;
    LinkedList *listeNotes;
};

int etu_fonctionComp(Etudiant* e, int numero);
void etu_changerClasse(Etudiant* e, Classe* oldClasse, Classe* newClasse);
void etu_affecterNote(Etudiant** e, Cours *c, float val);

#endif // ETUDIANT_H_INCLUDED
