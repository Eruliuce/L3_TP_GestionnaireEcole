/// ///////////////////////////////////////////////////
///                                                 ///
///     linkedlist.c                                ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 30/10/2015              ///
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

void ll_insert(LinkedList** l, void *elem, void* (*foncteurCond)(void*, void*))
{
    LinkedList* temp = NULL;
    LinkedList* newMaillon = NULL;
    ll_push(&newMaillon, elem);

    if (*l == NULL) //liste vide
    {
        *l = newMaillon;
    }
    else if(foncteurCond((*l)->elem, elem)) // insertion au début
    {
        newMaillon->next = *l;
        *l = newMaillon;
    }
    else // insertion au milieu ou a la fin
    {
        temp = *l;
        if(temp->next != NULL)
        {
            while(temp->next->next != NULL && !foncteurCond(temp->next->elem, elem))
            {
               temp = temp->next;
            }
            if(!foncteurCond(temp->next->elem, elem))
                temp = temp->next;
        }
        newMaillon->next = temp->next;
        temp->next = newMaillon;
    }
}

void ll_remove(LinkedList** l, void* (*foncteurCond)(void*, void*), void* comparateur, void(*liberation)(void*), size_t nbrElem)
{
    LinkedList *tmp;
    LinkedList *precedent;
    short next = 1;
    short all = nbrElem == 0 ? 1 : 0;
    short nontrouve;

    while(next && (all || nbrElem))
    {
        next = 0;
        if(*l != NULL)
        {
            precedent = *l;
            if(foncteurCond(precedent->elem, comparateur)) // tête de liste
            {
                *l = precedent->next;
                if(liberation != NULL)
                {
                    liberation(precedent->elem);
                }
                free(precedent);
                nbrElem--;
                next = 1;
            }
            else
            {
                precedent = *l;
                tmp = (*l)->next;
                nontrouve = 1;
                while(tmp != NULL && nontrouve)
                {
                    if(foncteurCond(tmp->elem, comparateur))
                    {
                        precedent->next = tmp->next;
                        if(liberation != NULL)
                            liberation(tmp->elem);
                        free(tmp);
                        nbrElem--;
                        nontrouve = 0;
                        next = 1;
                    }
                    precedent = tmp;
                    tmp = tmp->next;
                }
            }
        }
    }
}

LinkedList* ll_get(LinkedList** l, void* (*foncteurCond)(), void* comparateur, size_t nbrElem)
{
    LinkedList *res = NULL;
    LinkedList *tmp = *l;
    short all = !nbrElem ? 1 : 0;
    while(tmp != NULL && (all || nbrElem))
    {
        if(foncteurCond(tmp->elem, comparateur))
        {
            ll_push(&res, tmp->elem);
            nbrElem--;
        }
        tmp = tmp->next;
    }
    return res;
}

size_t ll_size(LinkedList **l)
{
    size_t i = 0;
    LinkedList *liste = *l;
    while(liste != NULL)
    {
        i++;
        liste = liste->next;
    }
    return i;
}

void ll_exec(LinkedList** l, void (*foncteur)(void*, void*), void* param)
{
    if(*l != NULL)
    {
        foncteur((*l)->elem, param);
        ll_exec(&((*l)->next), foncteur, param);
    }
}

void ll_destroy(LinkedList** l, void (*liberation)())
{
    while(!ll_pull(l, liberation));
}

int ll_index(LinkedList **l, void* (*foncteurCond)(), void* comparateur)
{
    size_t cpt = 0;
    LinkedList *tmp = *l;
    while(!foncteurCond(tmp->elem, comparateur) && tmp != NULL)
    {
        cpt++;
        tmp = tmp->next;
    }
    if(tmp == NULL)
        return -1;
    else
        return (int)cpt;
}


void* ll_at(LinkedList **l, size_t index)
{
    size_t i = 0;
    LinkedList *tmp = *l;
    while(i < index && tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    if(tmp == NULL)
        return NULL;
    else
        return (void*)(tmp->elem);
}

