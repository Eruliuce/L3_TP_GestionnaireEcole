#include "note.h"

Note::Note(float val, std::string matiere)
{
    this->value = val;
    this->matiere = matiere;
}

void Note::afficher()
{
    std::cout << matiere << " : " << value << std::endl;
}
