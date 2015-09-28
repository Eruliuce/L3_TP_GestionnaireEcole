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

void ll_push(LinkedList**, void*);
/// {Ajoute un �l�ment � la fin de la liste.}
/// Param�tres :    - adresse de la liste � modifier
///                 - adresse de l'�l�ment � ajouter

size_t ll_pull(LinkedList** l, void (*liberation)(void*));
/// {Retire le dernier �l�ment de la liste. Retourne 0 en cas de r�ussite, 1 en cas d'�chec.}
/// Param�tres :    - adresse de la liste � modifier
///                 - fonction permettant de liib�r� les �l�ments allou�s dans la liste
///                   (NULL si l'�l�ment n'est pas allou� dynamiquement).

void ll_insert(LinkedList** l, void *elem, void* (*foncteurCond)(void*, void*));
/// {Insert un �l�ment dans la liste en le triant.}
/// Param�tres :    - adresse de la liste � modifier
///                 - adresse �l�ment � ajouter
///                 - fonction de condition prenant en param�tre un �l�ment et l'�l�ment suivant pour les comparer
///                   cette fonction doit retourner 1 lorsqu'on doit ins�rer l'�l�ment, 0 sinon

void ll_remove(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem); //retire un �l�ment de la liste selon une condition
void* ll_get(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem);

void ll_exec(LinkedList**, void (*foncteur)(), void* parametre);
/// {Appelle une fonction sur tous les �l�ments de la liste.}
/// Param�tres :    - adresse de la liste
///                 - fonction a �xecuter
///                 - param�tre ou liste de param�tres � passer � la fonction

void ll_destroy(LinkedList**, void (*liberation)());
/// {D�truit tous les maillons de la liste.}
/// Param�tres :    - adresse de la liste
///                 - fonction de lib�ration de l'�l�ment (NULL si l'�l�ment n'est pas allou� dinamyquement)

size_t ll_size(LinkedList **l);
/// {Retourne la taille de la liste pass�e en param�tre.}

#endif // LINKEDLIST_H_INCLUDED
