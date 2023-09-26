#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct adding
{
    char titre[50];
    char disc[100];
    int m;
    char statut[10];
    int j;
    int an;
    int id;
};
int id;
int ch, total, count = 0, ch1, choice; // global variables

struct adding addings[33]; //[33] can support 33 tasks
void ajouteTache()
{
    system("cls");
    printf("entrer le titre :");
    scanf(" %[^\n]", &addings[count].titre);
    printf("Enter la discription :");
    scanf(" %[^\n]", &addings[count].disc);
    printf("entrer deadline, Mois :");
    scanf("%d", &addings[count].m);
    printf("Jour :");
    scanf("%d", &addings[count].j);
    printf("Annee :");
    scanf("%d", &addings[count].an);
    printf("Statut(todo/doing/ done) :");
    scanf(" %[^\n]s", &addings[count].statut);
    addings[count].id = count + 1;
    count++;
}
//=============================================================================

void ajoute()
{
    system("cls");
    printf("[1]ajouter une nouvelle tache :\n");
    printf("[2]ajouter plusieurs taches :");
    scanf("%d", &ch);
    if (ch == 1)
    {
        ajouteTache();
    }
    else if (ch == 2)
    {
        printf("entrer le nombre des taches a ajouter :");
        scanf("%d", &ch1);
        for (int i = 0; i < ch1; i++)
        {
            ajouteTache();
        }
    }
}

//============================================================
void show()
{
    system("cls");
    for (int i = 0; i <= count -1; i++)
    {
        printf("ID= %d \n", addings[i].id);
        printf("Titre : %s \n", addings[i].titre);
        printf("Discription : %s \n", addings[i].disc);
        printf("Deadline, Mois : %d \n", addings[i].m);
        printf("Jour : %d \n", addings[i].j);
        printf("Annee : %d \n", addings[i].an);
        printf("statut : %s \n", addings[i].statut);
        printf("=============================================== \n");
    }
}
//========================================================================
struct adding v; // v variable temporaire pour affecter la valeur que je veux changer
void affichage()
{
    system("cls");
    int tri;
    printf("[1]Trie par ordre alphabitique de A a Z : \n");
    printf("[2]Retour a Menu principale : \n");
    scanf("%d", &tri);

    if (tri == 1)
    {
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = 0; j < count - i - 1; j++)
            {
                if (strcasecmp(addings[j].titre, addings[j + 1].titre) > 0)
                {
                    v = addings[j];
                    addings[j] = addings[j + 1];
                    addings[j + 1] = v;
                }
            }
        }
        show();
    }
}
//================================================================================
void statistique() // statistique affiche les tâches éxecuté est pas encore éxecuté, et encore les tâches total.
{
    system("cls");
    int countDone = 0;
    int countNotDone = 0;
    total = count;
    printf("[1] Nombre des taches totals. \n");
    printf("[2] Les taches completes et incompletes. \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("number total des taches est : %d \n", total);
        break;
    case 2:
        for (int i = 0; i < count; i++)
        {
            if (strcmp(addings[i].statut, "done") == 0)
            {
                countDone++;
            }
            else
            {
                countNotDone++;
            }
        }
        printf("Nombre des taches comblet : %d \n", countDone);
        printf("Nombre des taches incomplet : %d \n", countNotDone);
    }
}
void rechrche()
{
    system("cls");
    char ti[30];
    printf("Tapper [1]pour ID, ou[2] pour titre :");
    scanf("%d", &ch);
    int trouve = 0;
    if (ch == 1)
    {

        printf("Donnee L ID : ");
        scanf("%d", &id);
        for (int i = 0; i < count; i++)
        {
            if (addings[i].id == id)
            {
                trouve = 1;
                printf("ID= %d \n", addings[i].id);
                printf("Titre : %s \n", addings[i].titre);
                printf("Discription : %s \n", addings[i].disc);
                printf("Deadline, Mois : %d \n", addings[i].m);
                printf("Jour : %d \n", addings[i].j);
                printf("Annee : %d \n", addings[i].an);
                printf("statut : %s \n", addings[i].statut);
                printf("=============================================== \n");
            }
        }
        if (trouve == 0)
        {
            printf("Aucune tache avec cet ID n'a ete trouve.\n");
        }
    }
    else if (ch == 2)
    {
        printf("Entre le titre :");
        scanf("%s", ti);
        for (int i = 0; i < count; i++)
        {
            if (strcmp(addings[i].titre, ti) == 0)
            {
                trouve = 1;
                printf("ID= %d \n", addings[i].id);
                printf("Titre : %s \n", addings[i].titre);
                printf("Discription : %s \n", addings[i].disc);
                printf("Deadline, Mois : %d \n", addings[i].m);
                printf("Jour : %d \n", addings[i].j);
                printf("Annee : %d \n", addings[i].an);
                printf("statut : %s \n", addings[i].statut);
                printf("=============================================== \n");
            }
        }
        if (trouve == 0)
        {
            printf("Aucune tache avec ce titre n'a ete trouve.\n");
        }
    }
}
void supprime()
{
    system("cls");
    printf("Donnee L ID : ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (addings[i].id == id)
        {
            for (int j = i; j < count; j++)
            {
                addings[j] = addings[j + 1];
            }
            count--;
        }
    }
}

void modifier()
{
    system("cls");
    char nouveau[100];
    int deadline;
    printf("[1]Modifier la description d'une tache . \n");
    printf("[2]Modifier le statut d'une tache . \n");
    printf("[3]Modifier le deadline d'une tache . \n");
    printf("entrer votre choix : ");
    scanf("%d", &ch);
    printf("Donner L ID pour modifier :");
    scanf("%d", &id);

    switch (ch)
    {
    case 1:
        for (int i = 0; i < count; i++)
        {
            if (id == addings[i].id)
            {
                printf("Entrer nouvelle discription : ");
                scanf(" %[^\n]", nouveau);
                strcpy(addings[i].disc, nouveau);
            }
        }
        break;
    case 2:

        for (int i = 0; i < count; i++)
        {
            if (id == addings[i].id)
            {
                printf("Entrer nouveau Statut : ");
                scanf(" %[^\n]", nouveau);
                strcpy(addings[i].statut, nouveau);
            }
        }
        break;

    case 3:
        for (int i = 0; i < count; i++)
        {
            if (id == addings[i].id)
            {
                printf("Entrer nouveau deadline, Mois : ");
                scanf("%d", &addings[i].m);
                printf("Jour :");
                scanf("%d", &addings[i].j);
                printf("Annee :");
                scanf("%d", &addings[i].an);
            }
        }
        break;
    default:
        printf("votre choix est indisponible .");
        break;
    }
}

int main()
{
    do
    {
        printf("=================Menu(ToDo)================== \n");
        printf("voici Menu ToDo List :\n");
        printf("[1]Ajouter a ToDo List  \n");
        printf("[2]Afficher les taches \n");
        printf("[3]Modifier une tache par id  \n");
        printf("[4]Supprimer une tache par id \n");
        printf("[5]Rechercher des taches \n");
        printf("[6]Statistiques \n");
        printf("[7]Quitter \n");
        printf("choisir un nombre :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            ajoute();
            break;
        case 2:
            affichage();
            break;
        case 3:
            modifier();
            break;
        case 4:
            supprime();
            break;
        case 5:
            rechrche();
            break;
        case 6:
            statistique();
            break;
        }

    } while (1);

    return 0;
}
