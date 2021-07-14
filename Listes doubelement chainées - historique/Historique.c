#include <stdio.h>
#include <stdlib.h>
#include "Historique.h"


// Créer une liste vide
Dlist new_liste(){

    return NULL;
}

// Fonction qui retourne un booléen selon l'état de la liste ( vide ou non )
Bool is_empty_liste(Dlist li){

    if(li == NULL)
        return true;
    return false;

}

//Fonction qui retourne la longueur (taille) de la liste
int dlist_length(Dlist li){

    if(is_empty_liste(li))  return 0;

    return li -> longueur;
}

//Fonction qui retourne la valeur du premier noeud de la liste
char * dlist_first(Dlist li){

    if (is_empty_liste(li)){
        exit(1);
    }
    return li ->first ->x;
}

//Fonction qui retourne la valeur du dernier noeud de la liste
char * dlist_last(Dlist li){

    if(is_empty_liste(li)){
        exit(1);
    }
    return li ->last ->x;
}


// Fonction qui affiche la liste ( Empty si elle est vide )
void afficher_dlist(Dlist li){

    if(is_empty_liste(li)){

        printf("Empty , Nothing to print ^^ \n");
        return ;
    }

    DlisteNode * temp = li ->first;
    while (temp != NULL){
        printf("[ %s ] \n " , temp->x);
        temp = temp -> suiv ;
    }

}

//Ajout un élement à l'historique --> L'ajout va etre en tete de la liste
Dlist ajout_element(Dlist li , char *str){

    DlisteNode * element;
    element = malloc(sizeof(*element));
    if(element == NULL){
        fprintf(stderr , "Error : allocation problem \n");
        exit(EXIT_FAILURE);
    }

    element -> x = str;
    element ->suiv = NULL;
    element -> pred = NULL;

    if(is_empty_liste(li)){
        li = malloc(sizeof(*li));
        if (li == NULL){
            fprintf(stderr, "Error : allocation problem \n");
            exit(EXIT_FAILURE);
        }
        li ->longueur = 0;
        li ->first = element;
        li ->last = element;
    }
    else {
        li ->first->pred = element;
        element->suiv = li->first;
        li->first=element;
    }
    li ->longueur ++ ;

    return li;


}

/*Retirer le dernier élement rentré dans l'historique --> La suppression va etre au début de la liste.
J'ai choisie de retourner la liste - Par contre on peut changer le type de fonction en (char *)
et passer l'élement supprimé comme valeur de retour*/

Dlist retirer_element(Dlist li) {

    if (is_empty_liste(li)){
        printf("Nothing to remove , the list is already empty \n");
        return new_liste();

        //return " Message " ;
    }
    if (li ->first == li ->last){ //The list contains only one element
        free(li);
        li =NULL;
        return new_liste();
        // return li -> last -> x ;
    }
    DlisteNode *temp = li -> first ;

    li ->first = li ->first->suiv;
    li->first->pred = NULL;
    temp->suiv = NULL;
    temp->pred = NULL;
    // char * suppr = temp -> x ;
    free(temp);
    temp = NULL ;

    li->longueur --;

    return li ;

    //return suppr ;

}

//Parcours de la liste dans les deux sens !

void naviguer(Dlist  li ){

    char * head = dlist_first(li);
    char * tail = dlist_last(li);

    printf("First node of the list %s \n Last element of the list %s \n" , head , tail);

    DlisteNode * temp1 = li->first;
    DlisteNode * temp2 = li ->last;

    /*while (temp1 != NULL){
        printf("[ %s ] \n " , temp1->x);
        temp1 = temp1 -> suiv ;
    }*/

    //Affichage inverse
    while (temp2 != NULL){
        printf("[ %s ] \n " , temp2->x);
        temp2 = temp2 -> pred ;
    }

}


Dlist clear_dlist(Dlist li) {

    while (!is_empty_liste(li)) {
        li = retirer_element(li);
    }

    return new_liste();

}




