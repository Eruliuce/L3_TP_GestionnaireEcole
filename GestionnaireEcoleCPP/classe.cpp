#include "classe.h"

Classe::Classe(std::string nom)
{
    this->nom = nom;
}

std::string Classe::getNom()
{
    return nom;
}

void Classe::afficherEtudiants()
{
    for(auto i = 0; i < etudiants.size(); i++)
    {
        std::cout << " - Etudiant n" << etudiants.at(i)->getNum() << " - " << etudiants.at(i)->getPrenom() << " " << etudiants.at(i)->getNom() << "\t- " << nom << std::endl;
    }
}

void Classe::ajouterEtudiant(Etudiant *e)
{
    etudiants.push_back(e);
}
