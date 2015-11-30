#ifndef ECOLE_H_INCLUDED
#define ECOLE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "etudiant.h"
#include "classe.h"

class Ecole
{
private :
    std::string nom;
    std::string adresse;
    std::vector<Etudiant*> etudiants;
    std::vector<Classe*> classes;

public :
    Ecole();
    void afficherClasses();
    void afficherEtudiants();
    void afficherNotes();
    void ajouterClasse();
    void ajouterEtudiant();
    void ajouterNote();
};

#endif // ECOLE_H_INCLUDED
