#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED

#include <iostream>
#include <string>

class Note
{
private :
    float value;
    std::string matiere;

public :
    Note(float val, std::string matiere);
    void afficher();
};

#endif // NOTE_H_INCLUDED
