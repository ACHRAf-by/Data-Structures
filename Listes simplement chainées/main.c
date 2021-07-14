#include <stdio.h>
#include <stdlib.h>

#include "FonctionsList.h"

int main()
{
    printf(" TP1 ! \n " );

    maillon_t * Liste = NULL;

    printf("We start with an empty List \n");

    Liste=ajouter_debut(Liste , 15);
    Liste=ajouter_debut(Liste , 14);
    Liste=ajouter_debut(Liste , 13);

    printf("After adding elements on the head \n");
    afficher_liste(Liste);

    Liste=ajouter_fin(Liste , 0);
    Liste=ajouter_fin(Liste, 1);

    printf("\n After adding elements on the bottom \n");
    afficher_liste(Liste);

    Liste=rechercher_val(Liste , 14);

    printf("Delete the first element of the List \n ");
    Liste = supprimer_debut(Liste);

    afficher_liste(Liste);

    printf("Delete the final element of the List \n ");
    Liste = supprimer_fin(Liste);

    afficher_liste(Liste);

    printf("Delete a chosen element of the List (15 in this case) \n ");
    Liste = supprimer_val(Liste , 15);

    afficher_liste(Liste);

    return 0;
}
