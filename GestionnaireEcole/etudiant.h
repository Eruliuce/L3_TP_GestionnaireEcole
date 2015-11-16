#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include <stdlib.h>
#include "Outils/linkedlist.h"
#include "cours.h"
#include "classe.h"
#include "note.h"

typedef struct Etudiant Etudiant;
struct Etudiant
{
    int num;
    char nom[100];
    char prenom[100];
    Classe *c;
    LinkedList *listeNotes;
};

void creerEtudiant(LinkedList **listeEtu, char* nom, char* prenom);
void affecterClasse(Etudiant* e, Classe* c);
void affecterNote(Etudiant* e, Cours *c, float val);

#endif // ETUDIANT_H_INCLUDED
