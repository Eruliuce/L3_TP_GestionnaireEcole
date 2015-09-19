/// ///////////////////////////////////////////////////
///                                                 ///
///     linkedlist.c                                ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 17/09/2015              ///
///                                                 ///
/// Fonction : Définit une liste chaînée générique. ///
///                                                 ///
/// ///////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include "..\Outils\linkedlist.h"

void ll_push(LinkedList **l, void *elem)
{
    if(*l == NULL)
    {
        *l = (LinkedList*)malloc(sizeof(LinkedList));
        (*l)->elem = elem;
        (*l)->next = NULL;
    }
    else
    {
        ll_push(&(*l)->next, elem);
    }
}

size_t ll_pull(LinkedList** l, void (*liberation)(void*))
{
    if(*l == NULL) // 0 maillons : erruer
        return 1;
    else if((*l)->next == NULL) // 1 seul maillon
    {
        if(liberation != NULL)
        {
            liberation((*l)->elem);
        }
        free(*l);
        *l = NULL;
    }
    else if((*l)->next->next != NULL)
    {
        ll_pull(&(*l)->next, liberation);
    }
    else
    {
        if(liberation != NULL)
        {
            liberation((*l)->elem);
        }
        free((*l)->next);
        (*l)->next = NULL;
    }

    return 0;
}

void ll_insert(LinkedList** l, void (*foncteurCond)(), void* cond)
{
    ///TO DO
}

void ll_remove(LinkedList** l, void (*foncteurCond)(), void* cond)
{
    ///TO DO
}

void ll_exec(LinkedList** l, void (*foncteur)(void*, void*), void* param)
{
    if(*l != NULL)
    {
        printf("test0\n");
        foncteur((*l)->elem, param);
        ll_exec(&((*l)->next), foncteur, param);
    }
}

void ll_destroy(LinkedList** l, void (*liberation)())
{
    while(!ll_pull(l, liberation));
}



