#include "fonctions.h"

size_t comparaisonNum(size_t *a, size_t b)
{
    if(*a == b)
        return 1;
    return 0;
}

size_t comparaisonCours(void* a, char* b)
{
    return !strcmp(((Cours*)a)->matiere, b);
}

size_t comparaisonEtu(Etudiant* e1, int *e2)
{
    if(e1->num == *e2)
        return 1;
    return 0;
}

size_t comparaisonClasse(void* a, char* b)
{
    return !strcmp(((Classe*)a)->formation, b);
}

