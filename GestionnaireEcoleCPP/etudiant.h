#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "note.h"

class Etudiant
{
private :
    std::string nom, prenom;
    std::vector<Note*> notes;
    size_t num;

public :
    Etudiant(std::string nom, std::string prenom);
    std::string getPrenom();
    std::string getNom();
    size_t getNum();
    void ajouterNote(float val, std::string matiere);
    void afficherNotes();
};

#endif // ETUDIANT_H_INCLUDED
