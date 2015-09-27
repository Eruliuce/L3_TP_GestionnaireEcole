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

void ll_push(LinkedList**, void*); //ajoute un élément à la fin de la liste
size_t ll_pull(LinkedList** l, void (*liberation)(void*)); //retire le dernier élément de la liste ; retourne 0 en cas de réussite, 1 en cas de problème
void ll_insert(LinkedList** l, void *elem, void* (*foncteurCond)(void*, void*)); //insert un élément dans la liste selon une condition d'emplacement (pour obtenir une liste triée)
void ll_remove(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem); //retire un élément de la liste selon une condition
void* ll_get(LinkedList** l, void (*foncteurCond)(), void* comparateur, size_t nbrElem);
void ll_exec(LinkedList**, void (*foncteur)(), void* parametre); //appelle une fonction sur tous les éléments de la liste
void ll_destroy(LinkedList**, void (*liberation)()); //détruit tous les maillons de la liste /!\ Si la liste contient un élément alloué, passer en paramètre la fonction qui le libérera

#endif // LINKEDLIST_H_INCLUDED
