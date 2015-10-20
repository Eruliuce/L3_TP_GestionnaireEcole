/// ///////////////////////////////////////////////////
///                                                 ///
///     test_linkedlist.c                           ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 20/10/2015              ///
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
    if(!testSuppression())
    {
        printf("Suppression liste Ok.\n");
    }
    testExec();
    testInsert();
    if(!testSize())
    {
        printf("Test Size Ok.\n");
    }
    if(!testRemove())
    {
        printf("Test Remove Ok.\n");
    }
    if(!testGet())
    {
        printf("Test Get Ok.\n");
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
    printf("\tTestExec : %d.\n", *i);
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

size_t testSuppression()
{
    LinkedList *l1 = NULL, *l2 = NULL, *l3 = NULL;
    int var = 1;

    ll_push(&l1, &var);
    ll_push(&l2, &var);
    ll_push(&l3, &var);
    l1->next = l2;
    l2->next = l3;
    ll_destroy(&l1, testExecAfficheInt);
    if(l1 == NULL)
        return 0;
    return 1;
}

void testExecAfficheTableauMult(int* a, int* b)
{
    int i;
    for(i = 1; i < *b; i++)
    {
        printf("%d ", b[i] * *a);
    }
    printf("\n");
}

void testExec()
{
    LinkedList *l = NULL;
    int val1 = 2, val2 = 5, i;
    int* tab = (int*)malloc(5 * sizeof(int));
    tab[0] = 5;
    for(i = 1; i <= 4; i++)
    {
        tab[i] = i;
    }
    ll_push(&l, &val1);
    ll_push(&l, &val2);
    ll_exec(&l, testExecAfficheTableauMult, (void*)tab);

    ll_destroy(&l, NULL);
    free(tab);
}

size_t triNumeral(size_t *a, size_t *b)
{
    if(*b < *a)
        return 1;
    return 0;
}

size_t comparaisonNum(size_t *a, size_t b)
{
    if(*a == b)
        return 1;
    return 0;
}

void testInsert()
{
    size_t i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 5, i6 = 6, i7 = 7, i8 = 8, i9 = 9, i10 = 10;
    size_t *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10;
    LinkedList* l = NULL;

    ll_insert(&l, &i2, (void (*))triNumeral);
    ll_insert(&l, &i7, (void (*))triNumeral);
    ll_insert(&l, &i3, (void (*))triNumeral);
    ll_insert(&l, &i9, (void (*))triNumeral);
    ll_insert(&l, &i1, (void (*))triNumeral);
    ll_insert(&l, &i8, (void (*))triNumeral);
    ll_insert(&l, &i5, (void (*))triNumeral);
    ll_insert(&l, &i10, (void (*))triNumeral);
    ll_insert(&l, &i6, (void (*))triNumeral);
    ll_insert(&l, &i4, (void (*))triNumeral);

    p1 = l->elem;
    p2 = l->next->elem;
    p3 = l->next->next->elem;
    p4 = l->next->next->next->elem;
    p5 = l->next->next->next->next->elem;
    p6 = l->next->next->next->next->next->elem;
    p7 = l->next->next->next->next->next->next->elem;
    p8 = l->next->next->next->next->next->next->next->elem;
    p9 = l->next->next->next->next->next->next->next->next->elem;
    p10 = l->next->next->next->next->next->next->next->next->next->elem;

    printf("testInstert : %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10);

    ll_destroy(&l, NULL);
}

size_t testSize()
{
    LinkedList *l = NULL;
    short res = 1;
    int i1 = 1, i2 = 1, i3 = 1;
    ll_push(&l, &i1);
    ll_push(&l, &i2);
    ll_push(&l, &i3);

    if(ll_size(&l) == 3)
        res = 0;
    ll_destroy(&l, NULL);
    return res;
}

size_t testRemove()
{
    LinkedList *l = NULL;
    short res = 1;
    int i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 3, i6 = 2, i7 = 1, i8 = 2, i9 = 2, i10 = 2;

    ll_push(&l, &i1);
    ll_push(&l, &i2);
    ll_push(&l, &i3);
    ll_push(&l, &i4);
    ll_push(&l, &i5);
    ll_push(&l, &i6);
    ll_push(&l, &i7);
    ll_push(&l, &i8);
    ll_push(&l, &i9);
    ll_push(&l, &i10);
    ll_remove(&l, comparaisonNum, 3, NULL, 1);
    ll_remove(&l, comparaisonNum, 2, NULL, 4);
    ll_remove(&l, comparaisonNum, 4, NULL, 0);
    ll_remove(&l, comparaisonNum, 1, NULL, 1);
    LinkedList *tmp = l;

    if(*((int*)(l->elem)) == 3 && *((int*)(l->next->elem)) == 1 && *((int*)(l->next->next->elem)) == 2 && l->next->next->next == NULL)
        res = 0;
    ll_destroy(&l, NULL);
    return res;
}


size_t testGet()
{
    LinkedList *l = NULL;
    LinkedList *resL = NULL;
    short res = 0;
    int i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 3, i6 = 2, i7 = 1, i8 = 2, i9 = 2, i10 = 2;
    ll_push(&l, &i1);
    ll_push(&l, &i2);
    ll_push(&l, &i3);
    ll_push(&l, &i4);
    ll_push(&l, &i5);
    ll_push(&l, &i6);
    ll_push(&l, &i7);
    ll_push(&l, &i8);
    ll_push(&l, &i9);
    ll_push(&l, &i10);
    resL = ll_get(&l, comparaisonNum, 2, 3);
    if(!(*((int*)(resL->elem)) == 2 && *((int*)(resL->next->elem)) == 2 && *((int*)(resL->next->next->elem)) == 2 && resL->next->next->next == NULL))
        res++;
    ll_destroy(&resL, NULL);
    resL = ll_get(&l, comparaisonNum, 3, 0);
    if(!(*((int*)(resL->elem)) == 3 && *((int*)(resL->next->elem)) == 3 && resL->next->next == NULL))
        res++;
    ll_destroy(&resL, NULL);
    return res;
}
