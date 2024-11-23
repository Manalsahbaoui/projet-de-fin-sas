#include <stdio.h>
#define MAX_TACHES 100
typedef struct {
    int jours;
    int mois;
    int annee;
} date;
typedef enum {
    basse,
    haute
} PrioriteEnum;
typedef struct {
    PrioriteEnum Priorite;
    char titre[100];
    char Description[100];
    date Date;
} Tache;
Tache ListeTaches[MAX_TACHES];
int countTaches = 0;
int Vdate(int jours, int mois, int annee) {
    if (jours < 1 || jours > 31) {
        return 0; 
    }
    if (mois < 1 || mois > 12) {
        return 0; 
    }
    if (annee < 2024)
    {
        return 0;
    }
    return 1; 
}
void AjouterTache() {
    if (countTaches < MAX_TACHES) {
        Tache nouvelleTache;
         printf("Donner le titre de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.titre);

        printf("Donner la description de la tache : ");
        scanf(" %[^\n]s", nouvelleTache.Description);
       while (1)
       {
        printf("Donner la date de la tache : \n");
        printf(" Date jours:");
        scanf("%d",&nouvelleTache.Date.jours);
        printf(" Date mois:");
        scanf("%d",&nouvelleTache.Date.mois);
        printf(" Date annee:");
        scanf("%d",&nouvelleTache.Date.annee);
        // scanf("%d-%d-%d", &nouvelleTache.Date.jours, &nouvelleTache.Date.mois, &nouvelleTache.Date.annee);
        if (Vdate(nouvelleTache.Date.jours,nouvelleTache.Date.mois,nouvelleTache.Date.annee))
        {
           break;
        }else{
            printf("Date invalide. Veuillez entrer une date valide.\n");
        }
        
        }
        while (1) {
            printf("Donner la prioritee de la tache (0: basse / 1: haute) : ");
            scanf("%d", &nouvelleTache.Priorite);
            if (nouvelleTache.Priorite == 0 || nouvelleTache.Priorite == 1) {
                break; 
            }
            printf("Choix invalide. Veuillez entrer 0 ou 1.\n");
        }
        ListeTaches[countTaches++] = nouvelleTache;
        printf("Tache ajoutee avec succes!\n");
    } else {
        printf("La liste de taches est pleine. Impossible d'ajouter plus de taches.\n");
    }
}
int main() {
    int choix;
    do {
        printf("\n-----------------------Menu:---------------------\n");
        printf("1. Ajouter une tache\n");
        printf("2. Afficher la liste des taches\n");
        printf("3. Modifier une tache\n");
        printf("4. Supprimer une tache\n");
        printf("5. Filtrer par priorite\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                AjouterTache();
                break;
            case 2:
                AfficherListeTaches();
                break;
            case 3:
                ModifierTache();
                break;
                 case 4:
                SupprimerTache();
                break;
                 case 5: {
    int priorite;
     while (1) { 
        printf("Entrez la priorite (0: basse, 1: haute) : ");
        scanf("%d", &priorite);
        if (priorite == 0 || priorite == 1) {
            FiltrerParPriorite((PrioriteEnum)priorite);
            break; 
        }
        printf("Choix invalide. Veuillez entrer 0 ou 1.\n");
     }
} break;
            
            case 0:
                printf("Programme termine!\n");
                break;
            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 5.\n");
        }
    } while (choix != 0);
    return 0;
}