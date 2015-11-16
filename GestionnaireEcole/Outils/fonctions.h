#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "../cours.h"
#include "../etudiant.h"

size_t comparaisonNum(size_t *a, size_t b);
size_t comparaisonCours(void*, char*);
size_t comparaisonEtu(Etudiant*, int*);
size_t comparaisonClasse(void*, char*);

#endif // FONCTIONS_H_INCLUDED
