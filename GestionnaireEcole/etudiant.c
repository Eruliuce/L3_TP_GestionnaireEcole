#include "etudiant.h"

void creerEtudiant(LinkedList *listeEtu, char* nom, char* prenom)
{
    static int nextNum = 1;
    Etudiant *e = (Etudiant*)malloc(sizeof(Etudiant));
    e->nom = nom;
    e->prenom = prenom;
    e->num = nextNum;
    nextNum++;
    e->listeNotes = NULL;
    ll_push(&listeEtu, e);
}

void affecterClasse(Etudiant* e, Classe* c)
{
    ll_push(&(c->listeEtudiants), e);
    e->c = c;
}

void affecterNote(Etudiant* e, Cours *c, float val)
{
    Note *n = (Note*)malloc(sizeof(Note));
    n->valeur = val;
    n->etu = e;
    n->cours = c;
    ll_push(&(e->listeNotes), n);
}
