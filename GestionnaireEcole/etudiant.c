#include <stdlib.h>
#include "structures.h"
#include "etudiant.h"

int etu_fonctionComp(Etudiant* e, int numero)
{
    return e->num==numero? 1:0;
}

void etu_changerClasse(Etudiant* e, Classe* oldClasse, Classe* newClasse)
{
    e->c = newClasse;
    ll_remove(&(oldClasse->listeEtudiants), etu_fonctionComp, &(e->num), 1);
    ll_push(&(newClasse->listeEtudiants), e);
}

void etu_affecterNote(Etudiant** e, Cours* c, float val)
{
    Note n = (Note*)malloc(sizeof(Note));
    n->valeur = val;
    n->c = c;
    ll_push(e->listeNotes, n)
}

