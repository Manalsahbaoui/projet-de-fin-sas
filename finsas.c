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

int Vdate(int jours, int mois, int annee) {
    if (jours < 1 || jours > 31) {
        return 0; 
    }
    if (mois < 1 || mois > 12) {
        return 0; 
    }
    if (annee < 2024) {
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

        while (1) {
            printf("Donner la date de la tache : \n");
            printf(" Date jours: ");
            scanf("%d", &nouvelleTache.Date.jours);
            printf(" Date mois: ");
            scanf("%d", &nouvelleTache.Date.mois);
            printf(" Date annee: ");
            scanf("%d", &nouvelleTache.Date.annee);
            if (Vdate(nouvelleTache.Date.jours, nouvelleTache.Date.mois, nouvelleTache.Date.annee)) {
                break;
            } else {
                printf("Date invalide. Veuillez entrer une date valide.\n");
            }
        }

        while (1) {
            printf("Donner la prioritee de la tache (0: low / 1: high) : ");
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

void AfficherListeTaches() {
    if (countTaches > 0) {
        printf("----------------Liste des taches :------------------\n");
        for (int i = 0; i < countTaches; i++) {
            printf("----Tache %d :\n", i + 1);
            printf("Titre : %s\n", ListeTaches[i].titre);
            printf("Description : %s\n", ListeTaches[i].Description);
            printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);
            printf("Priorite : %s\n", (ListeTaches[i].Priorite == 0) ? "low" : "high");
            printf("\n");
        }
    } else {
        printf("Aucune tache a afficher!\n");
    }
}

void ModifierTache() {
    if (countTaches > 0) {
        int numeroTache;
        printf("Donner le numero de la tache a modifier: ");
        scanf("%d", &numeroTache);
        if (numeroTache > 0 && numeroTache <= countTaches) {
            Tache *modifierTache = &ListeTaches[numeroTache - 1];
            printf("Entrez la nouvelle titre de la tache : ");
            scanf(" %[^\n]s", modifierTache->titre);

            printf("Entrez la nouvelle description de la tache : ");
            scanf(" %[^\n]s", modifierTache->Description);

            while (1) {
                printf("Entrez la nouvelle date de la tache : \n");
                printf(" Date jours: ");
                scanf("%d", &modifierTache->Date.jours);
                printf(" Date mois: ");
                scanf("%d", &modifierTache->Date.mois);
                printf(" Date annee: ");
                scanf("%d", &modifierTache->Date.annee);
                if (Vdate(modifierTache->Date.jours, modifierTache->Date.mois, modifierTache->Date.annee)) {
                    break;
                } else {
                    printf("Date invalide. Veuillez entrer une date valide.\n");
                }
            }

            while (1) {
                printf("Entrez la nouvelle prioritee de la tache (0: low, 1: high) : ");
                scanf("%d", &modifierTache->Priorite);
                if (modifierTache->Priorite == 0 || modifierTache->Priorite == 1) {
                    break; 
                }
                printf("Choix invalide. Veuillez entrer 0 ou 1.\n");
            }

            printf("Tache modifiee avec succes!\n");
        } else {
            printf("Numero de tache invalide.\n");
        }
    } else {
        printf("Aucune tache a modifier!\n");
    }
}

void SupprimerTache() {
    if (countTaches > 0) {
        int i;
        int numeroTache;
        printf("Entrez le numero de la tache a supprimer : ");
        scanf("%d", &numeroTache);

        if (numeroTache > 0 && numeroTache <= countTaches) {
            for (i = numeroTache - 1; i < countTaches - 1; i++) {
                ListeTaches[i] = ListeTaches[i + 1];
            }

            countTaches--;
            printf("Tache supprimee avec succes!\n");
        } else {
            printf("Numero de tache invalide.\n");
        }
    } else {
        printf("Aucune tache a supprimer!\n");
    }
}

void FiltrerParPriorite(int priorite) {
    int i;
    if (countTaches > 0) {
        printf("Taches avec priorite %d :\n", priorite);
        for (i = 0; i < countTaches; i++) {
            if (ListeTaches[i].Priorite == priorite) {
                printf("-----Tache %d :\n", i + 1);
                printf("Titre : %s\n", ListeTaches[i].titre);
                printf("Description : %s\n", ListeTaches[i].Description);
                printf("Date : %d-%d-%d\n", ListeTaches[i].Date.jours, ListeTaches[i].Date.mois, ListeTaches[i].Date.annee);
                printf("Priorite : %s\n", (ListeTaches[i].Priorite == 0) ? "low" : "high");
                printf("\n");
            }
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
                        FiltrerParPriorite(priorite);
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