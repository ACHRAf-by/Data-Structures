#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NombresLarges.h"

#define MAX_NUMBER 15

//L'exemple qui nous montre qu'à un certain niveau, le langage ne peux plus gérer les opérations des nombres larges
/*
int main() {
    printf("Hello, World!\n");
    int res = 10;
    for (int i = 0; i < 1000; i++ ) {
        res *= 2;
        printf("i = %d : %d\n", i, res);
        if (res < 0) {
            printf("negatif\n");
            break;
        }

        }
    return 0;
    }
*/


int main(){

    char * chiffre1 = malloc(sizeof(char *) * MAX_NUMBER );
    char * chiffre2 = malloc(sizeof(char *) * MAX_NUMBER);

    printf("Enter your first large number ");
    scanf("%s" , chiffre1);
    printf("Enter your second large number ");
    scanf("%s" , chiffre2);

    Dlist mylist1 = new_liste();
    Dlist mylist2 = new_liste();
    printf("PART 1 : code numbers in lists \n");
    mylist1 = RemplirListes(mylist1 , chiffre1);
    afficher_dlist(mylist1);
    mylist2 = RemplirListes(mylist2 , chiffre2);
    afficher_dlist(mylist2);

    printf("PART 2 : Add two numbers and return them in a final list");

    Dlist listeFinale = SommeNombreLarge(mylist1 , mylist2);
    printf("The final list which contains the large number is : \n");
    afficher_dlist(listeFinale);






    /* long somme;
    somme = atoi(chiffre1) + atoi(chiffre2);
    printf("%lu" , somme); */










    return 0;
}