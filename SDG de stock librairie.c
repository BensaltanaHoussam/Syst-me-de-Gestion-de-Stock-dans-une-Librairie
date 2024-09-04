#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_livres 100

char titres[max_livres][50], auteurs[max_livres][50];
float prix[max_livres];
int quantites[max_livres], nombrelivres = 0;

// Ajouter un livre au stock.
void ajouter() {
    if (nombrelivres < max_livres) {
        printf("Titre : ");
        scanf("%s", titres[nombrelivres]);
        printf("Auteur : ");
        scanf("%s", auteurs[nombrelivres]);
        printf("Prix : ");
        scanf("%f", &prix[nombrelivres]);
        printf("Quantité : ");
        scanf("%d", &quantites[nombrelivres]);
        nombrelivres++;
    } else {
        printf("La bibliothèque est pleine !\n");
    }
}

// Afficher tous les livres disponibles.
void afficher() {
    if (nombrelivres > 0) {
        printf("Livres en bibliothèque :\n");
        for (int i = 0; i < nombrelivres; i++) {
            printf("%s par %s - %.2f$ il y a %d en stock\n", titres[i], auteurs[i], prix[i], quantites[i]);
        }
    } else {
        printf("Aucun livre en stock.\n");
    }
}

// Rechercher un livre par son titre.
void rechercher() {
    char titreArechercher[50];
    printf("Entrez le titre du livre : ");
    scanf("%s", titreArechercher);
    for (int i = 0; i < nombrelivres; i++) {
        if (strcmp(titres[i], titreArechercher) == 0) {
            printf("Livre trouvé : %s par %s - %.2f$ il y a %d en stock\n", titres[i], auteurs[i], prix[i], quantites[i]);
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

// Mettre à jour la quantité d'un livre.
void update() {
    char titreArechercher[50];
    int Nquantite;
    printf("Entrez le titre du livre à mettre à jour : ");
    scanf("%s", titreArechercher);
    for (int i = 0; i < nombrelivres; i++) {
        if (strcmp(titres[i], titreArechercher) == 0) {
            printf("Entrez la nouvelle quantité : ");
            scanf("%d", &Nquantite);
            quantites[i] = Nquantite;
            printf("Quantité mise à jour.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}

//Supprimer un livre du stock.
void supprimer() {
    char titreASupprimer[50];
    printf("Entrez le titre du livre à supprimer : ");
    scanf("%s", titreASupprimer);
    for (int i = 0; i < nombrelivres; i++) {
        if (strcmp(titres[i], titreASupprimer) == 0) {
            for (int j = i; j < nombrelivres - 1; j++) {
                strcpy(titres[j], titres[j + 1]);
                strcpy(auteurs[j], auteurs[j + 1]);
                prix[j] = prix[j + 1];
                quantites[j] = quantites[j + 1];
            }
            nombrelivres--;
            printf("Livre supprimé avec succès.\n");
            return;
        }
    }
    printf("Livre non trouvé.\n");
}


// Afficher le nombre total de livres en stock.
void afficherTotal() {
    int total = 0;
    for (int i = 0; i < nombrelivres; i++) {
        total += quantites[i];
    }
    printf("Le nombre total de livres est : %d\n", total);
}

int main() {
    int choix;

    do {
        printf("\nSystème de Gestion de Stock dans une Librairie\n");
        printf("1. Ajouter un livre au stock.\n");
        printf("2. Afficher tous les livres disponibles.\n");
        printf("3. Rechercher un livre par son titre.\n");
        printf("4. Mettre à jour la quantité d'un livre.\n");
        printf("5. Afficher le nombre total de livres en stock.\n");
        printf("6. Supprimer un livre du stock.\n");
        printf("7. Quitter.\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter();
                break;
            case 2:
                afficher();
                break;
            case 3:
                rechercher();
                break;
            case 4:
                update();
                break;
            case 5:
                afficherTotal();
                break;
            case 6:
               supprimer();
                break;
                  case 7:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 8);

    return 0;
}
