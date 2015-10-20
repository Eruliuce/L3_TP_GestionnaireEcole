#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#include "ecole.h"

struct Note
{
    float valeur;
    Etudiant *e;
    Cours *c;
};

#endif // NOTE_H_INCLUDED

