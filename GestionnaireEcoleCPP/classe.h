#ifndef CLASSE_H_INCLUDED
#define CLASSE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "etudiant.h"

class Classe
{
private :
    std::string nom;
    std::vector<Etudiant*> etudiants;

public :
    Classe(std::string nom);
    std::string getNom();
    void afficherEtudiants();
    void ajouterEtudiant(Etudiant *e);
};

#endif // CLASSE_H_INCLUDED
