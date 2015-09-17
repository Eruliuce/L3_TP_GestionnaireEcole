/// ///////////////////////////////////////////////////
///                                                 ///
///     test_linkedlist.c                           ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 17/09/2015              ///
///                                                 ///
/// Fonction : Test des fonctionnalités de la       ///
///            liste chaînée.                       ///
///                                                 ///
/// ///////////////////////////////////////////////////

#include <stdio.h>
#include "..\Tests\linkedlist.h"


void testLinkedList()
{
    if(!testPremierMaillon())
    {
        printf("Premier maillon Ok.\n");
    }
    if(!testXMaillons(3))
    {
        printf("Trois maillons Ok.\n");
    }
    if(!testPullUnMaillon())
    {
        printf("Pull premier maillon Ok.\n");
    }
    if(!testPullXMaillons(4))
    {
        printf("Pull sur une liste de 4 maillons Ok.\n");
    }
}


size_t testPremierMaillon()
{
    LinkedList *l = NULL;
    size_t i = 1;
    size_t ok = 1;
    ll_push(&l, &i);
    if(l != NULL)
    {
        if(*((size_t*)(l->elem)) == 1 && l->next == NULL)
        {
            ok = 0;
        }
    }
    free(l->elem);
    free(l);

    return ok;
}

size_t testXMaillons(size_t x)
{
    LinkedList *l = NULL;
    LinkedList *m = NULL;
    size_t j = 0;
    size_t *i = NULL;
    size_t ok = 0;

    i = (size_t*)malloc(x * sizeof(size_t));
    for(j = 0; j < x; j++)
    {
        i[j] = 1;
        ll_push(&l, &i[j]);
    }

    m = l;
    for(j = 0; j < x-1; j++)
    {
        if(*((size_t*)(m->elem)) != 1)
        {
            ok++;
        }
        m = m->next;
    }
    if(m->next != NULL)
    {
        ok++;
    }

    for(j = 0; j < x; j++)
    {
        m = l;
        l = l->next;
        free(m);
    }
    free(i);

    return ok;
}

void testExecAfficheInt(int* i)
{
    printf("TestExec : %d.\n", *i);
}

size_t testPullUnMaillon()
{
    LinkedList *l = NULL;
    int i = 42;
    ll_push(&l, &i);
    ll_pull(&l, (void*)testExecAfficheInt);
    if(l == NULL)
        return 0;
    else
        return 1;
}

size_t testPullXMaillons(size_t x)
{
    LinkedList *l = NULL;
    LinkedList *m = NULL;
    size_t j = 0;
    size_t *i = NULL;
    size_t ok = 0;

    i = (size_t*)malloc(x * sizeof(size_t));
    for(j = 0; j < x; j++)
    {
        i[j] = 1;
        ll_push(&l, &i[j]);
    }
    ll_pull(&l, (void*)testExecAfficheInt);
    m = l;
    for(j = 0; j < x-2; j++)
    {
        if(*((size_t*)(m->elem)) != 1)
        {
            ok++;
        }
        m = m->next;
    }
    if(m->next != NULL)
    {
        ok++;
    }

    for(j = 0; j < x-1; j++)
    {
        m = l;
        l = l->next;
        free(m);
    }
    free(i);

    return ok;
}

