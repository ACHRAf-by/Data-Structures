

#include "NombresLarges.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

//Ajout en tete de la liste -- str est les substring de chiffre 1 ou chiffre 2 qui contient 5 caractére ou moins
Dlist ajout_element(Dlist li , void *str){
    DlisteNode  *element;
    element = malloc(sizeof(*element));
    if(element == NULL)
    {
        fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element->x = str;
    element->suiv = NULL;
    element->pred = NULL;
    if(is_empty_liste(li))
    {
        li = malloc(sizeof(*li));
        if(li == NULL)
        {
            fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
            exit(EXIT_FAILURE);
        }
        li->longueur = 0;
        li->first = element;
        li->last = element;
    }
    else
    {
        li->last->suiv = element;
        element->pred = li->last;
        li->last= element;
    }
    li->longueur++;

    return li;
}


//Deuxiéme fonction pour ajouter un élement à la fin d'une liste

/* void PushBack(Dlist li , char * str){

    DlisteNode * elem = malloc(sizeof(DlisteNode));
    if (!elem)   fprintf(stderr , "Error on malloc");

    elem ->x = str;
    elem -> pred = li ->last;
    elem ->suiv = NULL;
    if(li ->last)   li ->last->suiv = elem;
    else li->first = elem;

    li -> last = elem;

}*/

/* Fonction qui remplit une liste par un nombre large souhaité
On a eu un probléme au niveau de cette fonction, en fait quand on rajoute une nouvelle valeur à la liste, ce nouvel élément écrase toutes les valeurs  précédantes stockées */

 Dlist RemplirListes(Dlist li , char * chiffre){
    int l = strlen(chiffre);

    int i = 0 , j = 0 ;
    char * s= malloc(sizeof(char ) * 5); // Sous chaines pour diviser le chiffre sur des parties


    while ((i < l)){
        while(j < 5){
            s[j] = chiffre[i];

            i++;
            j++;
        }
        printf(" Sous chaine : %s \n" , s);
        li = ajout_element(li, s);

        // afficher_dlist(li); // Vous pouvez enlever le commentaire pour voir l'état de la liste après chaque itération

        j = 0;
    }

     return li;
}

//La fonction qui fait la somme des deux nombres codés dans les 2 listes chainées en paramétres
Dlist SommeNombreLarge(Dlist l1 , Dlist l2){
    char * s1 = malloc(sizeof(char ) * 5);
    char * s2 = malloc(sizeof(char ) * 5);

    int somme ;
    char * sommeStr = malloc(sizeof(char )* 6);
    char * maillon = malloc(sizeof(char ) * 5);
    char Cret = '0' ; // Retenu en caractére

    Dlist li = new_liste(); // La liste qui va contenir la valeur finale ( chaque n chiffres dans un maillon ; n <= 5 )
                            // Du coup on  va avoir un retenu qui va etre ajouter au maillon suivant de la liste
    printf("Last element of mylist1 %s \n", l1 ->last->x);
    printf("Last element of mylist2 %s \n", l2 ->last->x);
    while ((l1 -> last != NULL) && (l2 -> last != NULL)){

        s1 = l1 -> last -> x;
        s2 = l2 -> last -> x;

        printf("the rest of addition is %c \n " , Cret);
        somme = atoi(s1) + atoi(s2) + (int)Cret; // (int)Cret == 0 si Cret est vide
        printf("somme = %d \n" , somme);
        snprintf(sommeStr , 6 , "%d" , somme);
        printf(" sommeStr = %s \n" , sommeStr);



         //S'il existe un retenu
         if (strlen(sommeStr) > 5 ){
             Cret = sommeStr[0];
             for(int i = 1 ; i<= strlen(sommeStr) ; i++){

                 maillon[i] = sommeStr[i];
             }
             li = ajout_element(li , maillon);
         }
         else{
             li = ajout_element(li , sommeStr);
         }

         l1 -> last = l1 -> last -> pred ;
         l2 -> last = l2 -> last -> pred ;
    }

    //li = ajout_element(li, (char*)Cret);

    return li;
 }
