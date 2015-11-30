#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "constantes.h"
#include "ecole.h"
#include "Outils/fonctions.h"

void controleur(Ecole *ecole);
void creationEtu(Ecole *ecole);
void creationClasse(Ecole *ecole);
void creationSalle(Ecole *ecole);
void creationNote(Ecole *ecole);
void listEtu(Ecole *ecole);
void listClasse(Ecole *ecole);
void listProfs(Ecole *ecole);
void listSalles(Ecole *ecole);
void listNotes(Ecole *ecole);
void listCours(Ecole *ecole);
void affectClasse(Ecole *ecole);

#endif // CONTROLEUR_H_INCLUDED
