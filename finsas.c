#include <stdio.h>
#define MAX_TACHES 100

typedef struct {
    int jours;
    int mois;
    int annee;
} date;

typedef struct {
    int Priorite; 
    char titre[100];
    char Description[100];
    date Date;
} Tache;

Tache ListeTaches[MAX_TACHES];
int countTaches = 0;



void AjouterTache() {
    if (countTaches < MAX_TACHES) {
        Tache nouvelleTache;
        printf("Donner le titre de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.titre);

        printf("Donner la description de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.Description);

        
            printf("Donner la date de la tache : \n");
            printf(" Date jours: ");
            scanf("%d", &nouvelleTache.Date.jours);
            printf(" Date mois: ");
            scanf("%d", &nouvelleTache.Date.mois);
            printf(" Date annee: ");
            scanf("%d", &nouvelleTache.Date.annee);
            
       

       
            printf("Donner la prioritee de la tache (0: basse / 1: haute) : ");
            scanf("%d", &nouvelleTache.Priorite);
            if (nouvelleTache.Priorite == 0 || nouvelleTache.Priorite == 1) {
               
            }
           

        ListeTaches[countTaches++] = nouvelleTache;
        printf("Tache ajoutee avec succes!\n");
    } else {
        printf("La liste de taches est pleine. Impossible d'ajouter plus de taches.\n");
    }
}

void AfficherListeTaches() {
    if (countTaches > 0) {
        printf("----------------Liste des taches :------------------\n");
        for (int i = 0; i < countTaches; i++) {
            printf("----Tache %d :\n", i + 1);
            printf("Titre : %s\n", ListeTaches[i].titre);
            printf("Description : %s\n", ListeTaches[i].Description);
            printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);
            printf("Priorite : %s\n", (ListeTaches[i].Priorite == 0) ? "basse" : "haute");
            printf("\n");
        }
    } else {
        printf("Aucune tache a afficher!\n");
    }
}

int main() {
    int choix;
    do {
        printf("\n-----------------------Menu:---------------------\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la liste des taches\n");
        
        printf("Choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                AjouterTache();
                break;
            case 2:
                AfficherListeTaches();
                break;
            
                 
                
            
           
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 5.\n");
        }
    } while (choix != 0);
    return 0;
}