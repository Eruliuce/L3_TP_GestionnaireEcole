/// ///////////////////////////////////////////////////
///                                                 ///
///     linkedlist.h                                ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 17/09/2015              ///
///                                                 ///
/// Fonction : Définit une liste chaînée générique. ///
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
/// {Ajoute un élément à la fin de la liste.}
/// Paramètres :    - adresse de la liste à modifier
///                 - adresse de l'élément à ajouter

size_t ll_pull(LinkedList** l, void (*liberation)(void*));
/// {Retire le dernier élément de la liste. Retourne 0 en cas de réussite, 1 en cas d'échec.}
/// Paramètres :    - adresse de la liste à modifier
///                 - fonction permettant de liibéré les éléments alloués dans la liste
///                   (NULL si l'élément n'est pas alloué dynamiquement).

void ll_insert(LinkedList** l, void *elem, void* (*foncteurCond)(void*, void*));
/// {Insert un élément dans la liste en le triant.}
/// Paramètres :    - adresse de la liste à modifier
///                 - adresse élément à ajouter
///                 - fonction de condition prenant en paramètre un élément et l'élément suivant pour les comparer
///                   cette fonction doit retourner 1 lorsqu'on doit insérer l'élément, 0 sinon

void ll_remove(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem); //retire un élément de la liste selon une condition
void* ll_get(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem);

void ll_exec(LinkedList**, void (*foncteur)(), void* parametre);
/// {Appelle une fonction sur tous les éléments de la liste.}
/// Paramètres :    - adresse de la liste
///                 - fonction a éxecuter
///                 - paramètre ou liste de paramètres à passer à la fonction

void ll_destroy(LinkedList**, void (*liberation)());
/// {Détruit tous les maillons de la liste.}
/// Paramètres :    - adresse de la liste
///                 - fonction de libération de l'élément (NULL si l'élément n'est pas alloué dinamyquement)

size_t ll_size(LinkedList **l);
/// {Retourne la taille de la liste passée en paramètre.}

#endif // LINKEDLIST_H_INCLUDED
