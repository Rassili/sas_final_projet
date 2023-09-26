   #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





struct adding {
char titre[50];
char disc[100];
int m;
char statut[10];
int j;
int an;
int id;
};

int ch,count=0,ch1,choice;

struct adding addings[33];
void ajouteTache(){

    printf("entrer le titre :");
    scanf(" %[^\n]",&addings[count].titre);
    printf("Enter la discription :");
    scanf(" %[^\n]",&addings[count].disc);
    printf("entrer deadline, Mois :");
    scanf("%d",&addings[count].m);
    printf("Jour :");
    scanf("%d",&addings[count].j);
    printf("Annee :");
    scanf("%d",&addings[count].an);
    printf("Statut (a realisee/en cours/fait :");
    scanf(" %[^\n]",&addings[count].statut);
    addings[count].id=count+1;
    count++;

}
void ajoute(){
printf("[1]ajouter une nouvelle tache :\n");
printf("[2]ajouter plusieurs taches :");
scanf("%d",&ch);
if(ch==1){
    ajouteTache();
}
else if(ch==2){
    printf("entrer le nombre des taches a ajouter :");
    scanf("%d",&ch1);
for(int i=0;i<ch1;i++){
    ajouteTache();
}

}
}
void affichage (){

    for (int i=0;i<=count-1;i++){
        printf("ID= %d \n",addings[i].id);
        printf("Titre : %s \n",addings[i].titre);
        printf("Discription : %s \n",addings[i].disc);
        printf("Deadline, Mois : %d \n",addings[i].m);
        printf("Jour : %d \n",addings[i].j);
        printf("Annee : %d \n",addings[i].an);
        printf("statut : %s \n",addings[i].statut);

        printf("=============================================== \n");
    }



}




int main(){
  do{
    printf("=================Menu(ToDo)================== \n");
    printf("voici Menu ToDo List :\n");
    printf("[1]Ajouter a ToDo List  \n");
    printf("[2]Afficher les taches \n");
    printf("[3]Modifier une tache par id  \n" );
    printf("[4]Supprimer une tache par id \n");
    printf("[5]Rechercher des taches \n");
    printf("[6]Statistiques \n");
    printf("[7]Quitter \n");
    printf("choisir un nombre :");
    scanf("%d",&choice);
    switch(choice){
case 1:
    ajoute();
    break;
case 2:
    affichage();
    break;
case 3:

    break;
case 4:

    break;
case 5:

    break;
case 6:

    break;
}

  }while(1);





return 0;}
