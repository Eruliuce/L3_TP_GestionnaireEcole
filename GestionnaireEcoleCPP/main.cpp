#include <iostream>
#include "ecole.h"

using namespace std;

int main()
{
    Ecole *ec = new Ecole();

    bool quit = false;
    while(!quit);
    {
        int choix;
        do
        {
            cout << "0 - quitter" << endl;
            cout << "1 - consulter classes" << endl;
            cout << "2 - consulter etudiants" << endl;
            cout << "3 - consulter notes" << endl;
            cout << "4 - creer classe" << endl;
            cout << "5 - creer etudiant" << endl;
            cout << "6 - creer note" << endl;
            cout << "Choix : ";
            cin >> choix;
        }
        while(choix < 0 || choix > 6);

        switch(choix)
        {
        case 0:
            quit = true;
            break;
        case 1:
            ec->afficherClasses();
            break;
        case 2:
            ec->afficherEtudiants();
            break;
        case 3:
            ec->afficherNotes();
            break;
        case 4:
            ec->ajouterClasse();
            break;
        case 5:
            ec->ajouterEtudiant();
            break;
        case 6:
            ec->ajouterNote();
            break;
        }
    }
    return 0;
}
