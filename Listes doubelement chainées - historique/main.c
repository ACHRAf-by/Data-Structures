#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "Historique.h"

int main()
{
    printf("TP1 -> EXO 2 : \n");

    Dlist mylist = new_liste();

    //printf("Taille de la liste : %d \n ", dlist_length(mylist));
    //afficher_dlist(mylist);

    printf("The size of the list is %d \n ",dlist_length(mylist));

    printf(" #####################");
    printf(" \n #       History     #\n");
    printf(" #####################\n");

    // Vous pouvez enlever les commentaires et remplir la liste en tapant des exemples de recherches dans le console

  /*  char * buffer = malloc(sizeof(char*));

    while(1){
        gets(buffer);
        if ((strcmp(buffer , "exit") == 0) || ((strcmp(buffer , "EXIT"))== 0))
            break;
        mylist = ajout_element(mylist , buffer);
    }
    afficher_dlist(mylist); */

    mylist = ajout_element(mylist , "https://www.youtube.com/watch?v=14d5fdg");
    mylist = ajout_element(mylist , "https://www.Efrei.fr/Moodle");
    mylist = ajout_element(mylist , "https://www.scholarvox.com");
    mylist = ajout_element(mylist , "https://www.CodeGaming.com");
    mylist = ajout_element(mylist , "https://www.leagueoflegends.com/Senna");

    afficher_dlist(mylist);

    printf("Delete elements \n");
    mylist = retirer_element(mylist);
    mylist = retirer_element(mylist);

    afficher_dlist(mylist);

    printf("Navigation in History \n");
    naviguer(mylist);

    printf("Clearing all the History \n");
    mylist = clear_dlist(mylist); //Retirer tous les élements --> supprimer tout l'historique
    afficher_dlist(mylist);

    return 0;


}
