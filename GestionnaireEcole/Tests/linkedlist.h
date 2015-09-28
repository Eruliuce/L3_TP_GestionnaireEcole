/// ///////////////////////////////////////////////////
///                                                 ///
///     test_linkedlist.h                           ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Cr�ation : 17/09/2015                           ///
/// Derni�re modification : 17/09/2015              ///
///                                                 ///
/// Fonction : Test des fonctionnalit�s de la       ///
///            liste cha�n�e.                       ///
///                                                 ///
/// ///////////////////////////////////////////////////

#ifndef TEST_LINKEDLIST_H_INCLUDED
#define TEST_LINKEDLIST_H_INCLUDED

#include <stdlib.h>
#include "..\Outils\linkedlist.h"

void testLinkedList(); //�xecute une s�rie de tests pour v�rifier que la LinkedList fonctionne bien

size_t testPremierMaillon(); //retourne 0 si le premier maillon se cr�e correctement, 1 sinon
size_t testXMaillons(size_t x); //retourne 0 si tous les maillons se cr�ent correctement, une autre valeur sinon
size_t testPullUnMaillon();
size_t testPullXMaillons(size_t x);
size_t testSuppression();
void testExec();
void testExecAfficheInt(int *i);
size_t triNumeral(size_t *a, size_t *b);
void testInsert();
size_t testSize();

#endif // TEST_LINKEDLIST_H_INCLUDED
