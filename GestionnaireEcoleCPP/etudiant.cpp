#include "etudiant.h"

Etudiant::Etudiant(std::string nom, std::string prenom)
{
    static size_t numActuel = 1;
    this->nom = nom;
    this->prenom = prenom;
    num = numActuel;
    numActuel++;
}

std::string Etudiant::getPrenom()
{
    return prenom;
}

std::string Etudiant::getNom()
{
    return nom;
}

size_t Etudiant::getNum()
{
    return num;
}

void Etudiant::ajouterNote(float val, std::string matiere)
{
    notes.push_back(new Note(val, matiere));
}

void Etudiant::afficherNotes()
{
    std::cout << "Notes de " << prenom << " " << nom << " : " << std::endl;
    for(auto i = 0; i < notes.size(); i++)
    {
        notes.at(i)->afficher();
    }
}
