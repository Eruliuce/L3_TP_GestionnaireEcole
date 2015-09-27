/// ///////////////////////////////////////////////////
///                                                 ///
///     linkedlist.h                                ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Cr�ation : 17/09/2015                           ///
/// Derni�re modification : 17/09/2015              ///
///                                                 ///
/// Fonction : D�finit une liste cha�n�e g�n�rique. ///
///                                                 ///
/// ///////////////////////////////////////////////////

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct LinkedList LinkedList;
struct LinkedList
{
    LinkedList *next;
    void* elem;
};

void ll_push(LinkedList**, void*); //ajoute un �l�ment � la fin de la liste
size_t ll_pull(LinkedList** l, void (*liberation)(void*)); //retire le dernier �l�ment de la liste ; retourne 0 en cas de r�ussite, 1 en cas de probl�me
void ll_insert(LinkedList** l, void *elem, void* (*foncteurCond)(void*, void*)); //insert un �l�ment dans la liste selon une condition d'emplacement (pour obtenir une liste tri�e)
void ll_remove(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem); //retire un �l�ment de la liste selon une condition
void* ll_get(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem);
void ll_exec(LinkedList**, void (*foncteur)(), void* parametre); //appelle une fonction sur tous les �l�ments de la liste
void ll_destroy(LinkedList**, void (*liberation)()); //d�truit tous les maillons de la liste /!\ Si la liste contient un �l�ment allou�, passer en param�tre la fonction qui le lib�rera

#endif // LINKEDLIST_H_INCLUDED
