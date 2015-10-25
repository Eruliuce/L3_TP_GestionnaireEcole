#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#include "etudiant.h"

typedef struct Note Note;
struct Note
{
    float valeur;
    struct Etudiant *etu;
    Cours *cours;
};

#endif // NOTE_H_INCLUDED

