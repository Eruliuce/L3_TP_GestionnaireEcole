#include "controleur.h"

void controleur(Ecole *ecole)
{
    int c;
    unsigned int choix;
    do
    {
        do
        {
            printf("\nQue voulez-vous faire ?\n\n");
            printf("%d : Quitter           |    %d : Creer note         |    %d : Lister salles\n", QUITTER, CR_NOTE, LIST_SALLE);
            printf("%d : Creer etudiant    |    %d : Lister etudiants   |    %d : Lister notes\n", CR_ETU, LIST_ETU, LIST_NOTE);
            printf("%d : Creer classe      |    %d : Lister classes     |   %d : Lister cours\n", CR_CLASSE, LIST_CLASSE, LIST_COURS);
            printf("%d : Creer salle       |    %d : Lister professeurs |   %d : Affecter classe\n\n>>> ", CR_SALLE, LIST_PROF, AFFECT_CLASSE);
            scanf("%d", &choix);
            while ((c = getchar ()) != '\n' && c != EOF);
            if(choix > MAX)
                printf("\nErreur : valeur inconnue.\n\n");
        }while(choix > MAX);

        switch(choix)
        {
        case QUITTER:
            printf("\nA bientot pour de nouvelles aventures !\n");
            break;
        case CR_ETU:
            creationEtu(ecole);
            break;
        case CR_CLASSE:
            creationClasse(ecole);
            break;
        case CR_SALLE:
            creationSalle(ecole);
            break;
        case CR_NOTE:
            creationNote(ecole);
            break;
        case LIST_ETU:
            listEtu(ecole);
            break;
        case LIST_CLASSE:
            listClasse(ecole);
            break;
        case LIST_PROF:
            listProfs(ecole);
            break;
        case LIST_SALLE:
            listSalles(ecole);
            break;
        case LIST_NOTE:
            listNotes(ecole);
            break;
        case LIST_COURS:
            listCours(ecole);
            break;
        case AFFECT_CLASSE:
            affectClasse(ecole);
            break;
        }

    }while(choix != QUITTER);
}

void creationEtu(Ecole *ecole)
{
    int c;
    char nom[100], prenom[100];
    printf("Vous souhaitez creer un etudiant, veuillez saisir son nom et prenom.\nNom : ");
    scanf("%s", nom);
    while((c = getchar ()) != '\n' && c != EOF);
    printf("Prenom : ");
    scanf("%s", prenom);
    creerEtudiant(&(ecole->listeEtudiants), nom, prenom);
    printf("\nL etudiant %s %s a ete cree.\n", prenom, nom);
}

void creationClasse(Ecole *ecole)
{
    int c;
    char annee[100], formation[100];
    printf("Vous souhaitez creer une classe, veuillez saisir le niveau et la formation.\nNiveau : ");
    scanf("%s", annee);
    while((c = getchar ()) != '\n' && c != EOF);
    printf("Formation : ");
    scanf("%s", formation);
    creerClasse(&(ecole->listeClasses), annee, formation);
    printf("\nLa classe %s %s a ete creee.\n", annee, formation);
}

void creationSalle(Ecole *ecole)
{
    int c;
    char bat[100], nom[100];
    printf("Vous souhaitez creer une salle, veuillez saisir son batiment et son nom.\nBatiment : ");
    scanf("%s", bat);
    while((c = getchar ()) != '\n' && c != EOF);
    printf("Nom : ");
    scanf("%s", nom);
    while((c = getchar ()) != '\n' && c != EOF);
    creerSalle(&(ecole->listeSalles), bat, nom);
    printf("\nLa salle %s a ete creee dans le batiment %s.\n", nom, bat);
}

void creationNote(Ecole *ecole)
{
    int c;
    int num;
    float val;
    char matiere[100];
    printf("Vous souhaitez creer une note, veuillez saisir un numero d'etudiant a qui l'attribuer : ");
    scanf("%d", &num);
    while((c = getchar ()) != '\n' && c != EOF);
    LinkedList *tmp = ll_get(&(ecole->listeEtudiants), (void*)comparaisonNum, (void*)num, 1);
    Etudiant *e = ll_at(&tmp, 0);

    printf("Dans quelle matiere ?\n>>> ");
    scanf("%s", matiere);
    while((c = getchar ()) != '\n' && c != EOF);

    tmp = ll_get(&(e->c->listeCours), (void*)comparaisonCours, matiere, 1);
    Cours *co = ll_at(&tmp, 0);

    printf("Valeur de la note : ");
    scanf("%f", &val);
    while((c = getchar ()) != '\n' && c != EOF);
    affecterNote(e, co, val);
    printf("La note %.2lf a ete attribuee a %s %s en %s.\n", val, e->prenom, e->nom, matiere);
}

void listEtu(Ecole *ecole)
{
    int i;
    printf("\nListe des etudiants :\n");
    for(i = 0; i < ll_size(&(ecole->listeEtudiants)); i++)
    {
        Etudiant *e = ((Etudiant*)ll_at(&(ecole->listeEtudiants), i));
        if(e->c != NULL)
            printf("%d : %s %s, %s %s\n", e->num, e->prenom, e->nom, e->c->annee, e->c->formation);
        else
            printf("%d : %s %s, classe non attribuee\n", e->num, e->prenom, e->nom);
    }
}

void listClasse(Ecole *ecole)
{
    int i;
    printf("\nListe des classes :\n");
    for(i = 0; i < ll_size(&(ecole->listeClasses)); i++)
    {
        printf("%s %s\n", ((Classe*)ll_at(&(ecole->listeClasses), i))->annee, ((Classe*)ll_at(&(ecole->listeClasses), i))->formation);
    }
}

void listProfs(Ecole *ecole)
{
    int i;
    printf("Liste des professeurs :\n");
    for(i = 0; i < ll_size(&(ecole->listeProfs)); i++)
    {
        printf("%s %s\n", ((Professeur*)ll_at(&(ecole->listeProfs), i))->nom, ((Professeur*)ll_at(&(ecole->listeProfs), i))->prenom);
    }
}

void listSalles(Ecole *ecole)
{
    int i;
    printf("\nListe des salles :\n");
    for(i = 0; i < ll_size(&(ecole->listeSalles)); i++)
    {
        printf("%s (bat %s)\n", ((Salle*)ll_at(&(ecole->listeSalles), i))->nom, ((Salle*)ll_at(&(ecole->listeSalles), i))->bat);
    }
}

void listNotes(Ecole *ecole)
{
    int i, j;
    printf("\nListe des notes :");
    for(i = 0; i < ll_size(&(ecole->listeEtudiants)); i++)
    {
        Etudiant *e = ((Etudiant*)ll_at(&(ecole->listeEtudiants), i));
        printf("\n%s %s : ", e->prenom, e->nom);
        for(j = 0; j < ll_size(&(e->listeNotes)); j++)
        {
            Note *n = ll_at(&(e->listeNotes), j);
            char *tmp = n->cours->matiere;
            printf("%.2lf en ", n->valeur);
            printf("%s - ", tmp);
        }
    }
    printf("\n");
}

void listCours(Ecole *ecole)
{
    int i;
    printf("\nListe des cours :\n");
    for(i = 0; i < ll_size(&(ecole->listeCours)); i++)
    {
        printf("%s\n", ((Cours*)ll_at(&(ecole->listeCours), i))->matiere);
    }
}

void affectClasse(Ecole *ecole)
{
    int num;
    char c;
    char formation[1000];
    Etudiant *e = NULL;
    Classe *cl;
    printf("A quel etudiant voulez-vous affecter une classe ?\nNumero : ");
    scanf("%d", &num);
    while((c = getchar ()) != '\n' && c != EOF);

    e = ll_get(&(ecole->listeEtudiants), (void*)comparaisonEtu, &num, 1)->elem;
    printf("Quelle classe voulez-vous affecter a %s %s ?\nFormation : ", e->prenom, e->nom);
    scanf("%s", formation);
    while((c = getchar ()) != '\n' && c != EOF);

    cl = ll_get(&(ecole->listeClasses), (void*)comparaisonClasse, formation, 1)->elem;
    printf("%s\n", cl->formation);
    affecterClasse(e, cl);
}

