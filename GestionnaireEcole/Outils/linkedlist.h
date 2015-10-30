/// ///////////////////////////////////////////////////
///                                                 ///
///     linkedlist.h                                ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 30/10/2015              ///
///                                                 ///
/// Fonction : Définit une liste chaînée générique. ///
///                                                 ///
/// ///////////////////////////////////////////////////

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdlib.h>

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
/// {Retire le dernier élément de la liste.}
/// Paramètres :    - adresse de la liste à modifier
///                 - fonction permettant de libérer les éléments alloués dans la liste
///                   (NULL si l'élément n'est pas alloué dynamiquement).
/// Retourne 0 en cas de réussite, 1 en cas d'échec.

void ll_insert(LinkedList** l, void *elem, void* (*foncteurCond)(void*, void*));
/// {Insert un élément dans la liste en le triant.}
/// Paramètres :    - adresse de la liste à modifier
///                 - adresse élément à ajouter
///                 - fonction de condition prenant en paramètre un élément et l'élément suivant pour les comparer
///                   cette fonction doit retourner 1 lorsqu'on doit insérer l'élément, 0 sinon

void ll_remove(LinkedList** l, void* (*foncteurCond)(void*, void*), void* comparateur, void(*liberation)(void*), size_t nbrElem);
/// {Retire un élément de la liste.}
/// Paramètres :    - adresse de la liste
///                 - fonction de condition (pour choisir les éléments à retirer)
///                 - paramètre de comparaison pour la fonction de condition
///                 - nombre d'éléments à supprimer (0 pour tous, 1 pour le premier, 2 pour les deux premiers, etc.)

LinkedList* ll_get(LinkedList** l, void* (*foncteurCond)(), void* comparateur, size_t nbrElem);
/// {Retourne les éléments d'une liste selon une condition.}
/// Paramètres :    - adresse de la liste
///                 - fonction de condition
///                 - paramètre pour la fonction de condition
///                 - nombre d'éléments à obtenir (0 pour tous, 1 pour le premier, 2 pour les deux premiers, etc.)
/// Rretourne une LinkedList contenant tout les éléments demandés.

void ll_exec(LinkedList**, void (*foncteur)(), void* parametre);
/// {Appelle une fonction sur tous les éléments de la liste.}
/// Paramètres :    - adresse de la liste
///                 - fonction a éxecuter
///                 - paramètre ou liste de paramètres à passer à la fonction

void ll_destroy(LinkedList**, void (*liberation)());
/// {Détruit tous les maillons de la liste.}
/// Paramètres :    - adresse de la liste
///                 - fonction de libération de l'élément (NULL si l'élément n'a pas besoin de traitement particulier)

size_t ll_size(LinkedList **l);
/// {Retourne la taille de la liste passée en paramètre.}

int ll_index(LinkedList **l, void* (*foncteurCond)(), void* comparateur);
/// {Retourne l'index du premier élément de la liste correspondant à la condition.}
/// Paramètres :    - adresse de la liste
///                 - fonction de comparaison
///                 - élément de comparaison
/// Retourne -1 si aucun élément ne correspond, l'index de l'élément sinon.

void* ll_at(LinkedList **l, size_t index);
/// {Retourne un pointeur sur le xème élément (commence à 0).}
/// Paramètres :    - adresse de la liste
///                 - index de l'élément
/// Retourne NULL en cas de débordement, l'élément souhaité sinon.

#endif // LINKEDLIST_H_INCLUDED

