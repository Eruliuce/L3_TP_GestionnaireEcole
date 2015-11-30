#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED

class Personne
{
private :
    string nom;
    string prenom;
    size_t numero;
    static size_t numCourant = 1;
};

class Etudiant : public Personne
{

};

class Professeur : public Personne
{
    int
};

#endif // PERSONNE_H_INCLUDED
