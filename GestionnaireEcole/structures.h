#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct Ecole Ecole;
typedef struct Classe Classe;
typedef struct Salle Salle;
typedef struct Cours Cours;
typedef struct Etudiant Etudiant;
typedef struct Note Note;
typedef struct seance seance;
typedef struct Professeur Professeur;

struct Ecole
{
    char *nom;
    char *adresse;
    LinkedList *listeSalles;
    LinkedList *listeClasses;
    LinkedList *listeProfs;
    LinkedList *listeEtudiants;
};

struct Professeur
{
    int num;
    char *nom;
    char *prenom;
    LinkedList *listeCours;
};

struct Classe
{
    char *annee;
    char *formation;
    LinkedList *listeEtudiants;
    LinkedList *listeCours;
};

struct Salle
{
    char *bat;
    int etage;
    int num;
};

struct Cours
{
    char *matiere;
    Professeur *prof;
    Classe *c;
};

struct Note
{
    float valeur;
    Etudiant *e;
    Cours *c;
};

struct Etudiant
{
    int num;
    char *nom;
    char *prenom;
    Classe *c;
    LinkedList *listeNotes;
};

struct seance
{
    Salle *s;
    char *date;
    char *horaire;
};

#endif // STRUCTURES_H_INCLUDED
