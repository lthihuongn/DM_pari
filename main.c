#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char demander_action(float solde) {
    char action;
    while (1) {
        printf("Solde actuel : %.2f$. Souhaitez-vous jouer (J) ou retirer (R) ? \n", solde);
        scanf(" %c", &action);
        if (action == 'J' || action == 'R') {
            return action;
        } else {
            printf("Veuillez entrer 'J' pour jouer ou 'R' pour retirer.\n");
        }
    }
}

float jouer(float solde) {
    char action = demander_action(solde);

    if (action == 'R') {
        printf("Vous avez retire %.2f$. Au revoir !\n", solde);
        return 0;
    } else {
        float mise;
        printf("Entrez la somme que vous souhaitez parier : ");
        scanf("%f", &mise);

        while (mise <= 0 || mise > solde) {
            printf("La mise doit etre superieure a 0 et ne pas depasser votre solde.\n");
            printf("Entrez la somme que vous souhaitez parier : ");
            scanf("%f", &mise);
        }

        int resultat = rand() % 2;

        if (resultat == 1) {
            solde += mise;
            printf("Felicitations ! Vous avez double votre mise. Votre solde actuel est de %.2f$.\n", solde);
        } else {
            solde -= mise;
            printf("Dommage ! Vous avez perdu votre mise. Votre solde actuel est de %.2f$.\n", solde);
        }
    }

    return solde;
}


int main() {
    srand(time(NULL));
    float solde_initial = 100.00;
    float solde = solde_initial;

    printf("Bienvenue dans le jeu du pari !\n");
    printf("Vous commencez avec %.2f$.\n", solde);

    while (solde > 0.00) {
        solde = jouer(solde);
    }

    printf("Le jeu est termine.\n");

    return 0;
}