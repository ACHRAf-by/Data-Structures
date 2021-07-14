#include <stdio.h>
#include <stdlib.h>
#include "FonctionsList.h"


maillon_t * ajouter_debut(maillon_t * pliste , int val){

    maillon_t * NewList = (maillon_t *)malloc(sizeof(struct maillon)) ;

    NewList -> x = val ;

    NewList -> suiv = pliste ;

    pliste = NewList ;

    return pliste;

}

maillon_t * ajouter_fin(maillon_t * pliste , int val){

    maillon_t * NewList = (maillon_t *)malloc(sizeof(struct maillon));
    maillon_t * temp ;

    temp = pliste;

    NewList -> x = val ;
    NewList -> suiv = NULL ;

    if(temp == NULL){
        temp = NewList ;
    }

    while(temp->suiv != NULL){

        temp = temp -> suiv ;
    }

    //else : qu'on arrive à la fin de la liste
    temp -> suiv = NewList;

    return pliste ;
}




maillon_t *supprimer_debut(maillon_t * pliste){

    if (pliste == NULL){
        return pliste ;
    }

    maillon_t * suppr ;


    suppr = pliste ;

    pliste = pliste -> suiv ;

    free(suppr);

    return pliste ;
}


maillon_t * supprimer_fin(maillon_t * pliste){

    if (pliste ==NULL){
        return pliste;
    }
    if(pliste -> suiv == NULL){

        free(pliste);
        pliste =NULL;

        return NULL;
    }

    maillon_t * temp = pliste ;
    maillon_t * prec =pliste ;

    while(temp -> suiv != NULL){

        prec = temp ;
        temp = temp -> suiv ;
    }
    prec -> suiv = NULL ;
    free(temp);
    temp =NULL;

    return pliste ;
}



maillon_t * supprimer_val(maillon_t * pliste , int val){

    if (pliste == NULL){
        return pliste;
    }

    maillon_t * prec = pliste ;
    maillon_t * courant = pliste ;

    while(courant !=NULL && courant -> x != val ){

        prec = courant ;
        courant = courant -> suiv ;
    }

    prec -> suiv = courant -> suiv ;

    free(courant);

    return pliste;

}






maillon_t * rechercher_val(maillon_t * pliste , int val){

    int j = 0 ; // Valeur de vérification

    maillon_t * temp = pliste ;
    while (temp != NULL) {
        if (temp -> x == val){
            j = 1 ;
            printf("\n Existant : %d \n" , temp -> x);
            break;
        }
        temp = temp -> suiv ;

    }
    if (j==0){
        printf(" Non existant \n");
    }

 return pliste ;

}




void afficher_liste(maillon_t * pliste){


    while (pliste != NULL) { //( X temp -> suiv != NULL )

        printf(" [ %d ] " , pliste -> x);

        pliste = pliste -> suiv ;

    }
    printf("\n");

}
