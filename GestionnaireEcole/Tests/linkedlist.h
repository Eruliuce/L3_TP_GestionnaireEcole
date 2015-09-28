/// ///////////////////////////////////////////////////
///                                                 ///
///     test_linkedlist.h                           ///
///                                                 ///
/// Auteurs : RIBEIRO Olivier & BRIANT Arnaud       ///
/// Création : 17/09/2015                           ///
/// Dernière modification : 17/09/2015              ///
///                                                 ///
/// Fonction : Test des fonctionnalités de la       ///
///            liste chaînée.                       ///
///                                                 ///
/// ///////////////////////////////////////////////////

#ifndef TEST_LINKEDLIST_H_INCLUDED
#define TEST_LINKEDLIST_H_INCLUDED

#include <stdlib.h>
#include "..\Outils\linkedlist.h"

void testLinkedList(); //éxecute une série de tests pour vérifier que la LinkedList fonctionne bien

size_t testPremierMaillon(); //retourne 0 si le premier maillon se crée correctement, 1 sinon
size_t testXMaillons(size_t x); //retourne 0 si tous les maillons se créent correctement, une autre valeur sinon
size_t testPullUnMaillon();
size_t testPullXMaillons(size_t x);
size_t testSuppression();
void testExec();
void testExecAfficheInt(int *i);
size_t triNumeral(size_t *a, size_t *b);
void testInsert();
size_t testSize();

#endif // TEST_LINKEDLIST_H_INCLUDED
