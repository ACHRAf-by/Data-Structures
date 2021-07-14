#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grammaire.h"


/* Pour la fonction 'OU' ( A = a | epsilon ), vous devez definir l'axiome A deux fois une fois avec 'a' comme production
 *   et une deuxième fois avec 'epsilon' comme production :
 *   A= a
 *   A=epsilon
*/

/*
   Vous pouvez essayer avec ces deux exemples :

 * Grammaire 1:

    S->xyz/aBC
    B->c/cd
    C->eg/df

    PREMIER(S)={x,a}
    PREMIER(B)={c}
    PREMIER(C)={e,d}

 * Grammaire 2: ( $ : epsilon )

    S->ABCDE
    A->a/$
    B->b/$
    C->c
    D->d/$
    E->e/$

    (Régle : Premier(S) = Premier(A) + Premier(S si A = $))

    PREMIER(S)={a,b,c,d,e,$}
    PREMIER(A)={a,ϵ}
    PREMIER(B)={b,ϵ}
    PREMIER(C)={c}
    PREMIER(D)={d,ϵ}
    PREMIER(E)={e,ϵ}
 */
int main() {
    printf("Projet grammaire ^^ \n");
    char car;
    char tableau[25];
    printf("\n Entrer le nombre total des productions (Regles) :\t");
    //fflush(stdin);
    scanf("%d", &nbProduction);
    for (int i = 0; i < nbProduction; i++) {
        printf("\n La regle numero [%d] : \t ", i + 1);
        scanf("%s", production[i]);
    }
    int choix;
    do {
        printf("\n Entrer l'axiome pour lequel vous voulez trouver le premier: \t");
        scanf(" %c", &car);

        premier(tableau, car);
        printf("\n Le premier de l'axiome %c est :\t{ ", car);
        for (int i = 0; tableau[i] != '\0'; i++) {
            printf(" %c ", tableau[i]);
        }
        printf("}\n");
        printf("Taper '1' pour continuer, '2' pour sortir  ");
        scanf("%d", &choix);
        memset(tableau, 0, sizeof(tableau)); // Vider le tableau
    } while (choix == 1);

}
