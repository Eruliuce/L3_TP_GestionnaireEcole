#include "ecole.h"

Ecole::Ecole()
{
    nom = "EFREI";
    adresse = "30 Avenue de la Republique";
    classes.push_back(new Classe("Pas de classe"));
}

void Ecole::afficherClasses()
{
    std::cout << "Liste des classes :" << std::endl;
    for(auto i = 1; i < classes.size(); i++)
    {
        std::cout << " - " << classes.at(i)->getNom();
    }
}

void Ecole::afficherEtudiants()
{
    std::cout << "Liste des etudiants :" << std::endl;
    for(auto i = 0; i < classes.size(); i++)
    {
        classes.at(i)->afficherEtudiants();
    }
}

void Ecole::ajouterClasse()
{
    std::string nom;
    std::cout << "Saisissez nom : ";
    std::cin >> nom;
    classes.push_back(new Classe(nom));
}

void Ecole::ajouterEtudiant()
{
    std::string nom, prenom, classe;
    std::cout << "Saisissez nom : ";
    std::cin >> nom;
    std::cout << "Saisissez prenom : ";
    std::cin >> prenom;
    std::cout << "Saisissez classe : ";
    std::cin >> classe;
    bool trouve = false;
    size_t i = 0;
    while(!trouve && classes.at(i)->getNom().compare(classe))
    {
        i++;
    }
    if(!trouve)
    {
        std::cerr << "Cette classe n'existe pas." << std::endl;
    }
    else
    {
        Etudiant *e = new Etudiant(nom, prenom);
        etudiants.push_back(e);
        classes.at(i)->ajouterEtudiant(e);
    }
}

void Ecole::ajouterNote()
{
    size_t numEtu;
    float val;
    std::string matiere;
    std::cout << "Saisissez numero etudiant : ";
    std::cin >> numEtu;
    std::cout << "Saisissez valeur note : ";
    std::cin >> val;
    std::cout << "Saisissez matiere : ";
    std::cin >> matiere;
    bool trouve = false;
    size_t i = 0;
    while(!trouve && etudiants.at(i)->getNum() == numEtu)
    {
        i++;
    }
    if(!trouve)
    {
        std::cerr << "Cet etudiant n'existe pas." << std::endl;
    }
    else
    {
        etudiants.at(i)->ajouterNote(val, matiere);
    }
}

void Ecole::afficherNotes()
{
    size_t numEtu;
    std::cout << "Saisissez numero etudiant : ";
    std::cin >> numEtu;
    bool trouve = false;
    size_t i = 0;
    while(!trouve && etudiants.at(i)->getNum() == numEtu)
    {
        i++;
    }
    if(!trouve)
    {
        std::cerr << "Cet etudiant n'existe pas." << std::endl;
    }
    else
    {
        etudiants.at(i)->afficherNotes();
    }
}
