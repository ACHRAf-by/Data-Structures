#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int calculSommeChiffre(char* nombre){

    if (strlen(nombre) == 0)    return 0;


    return nombre[0] -'0' + calculSommeChiffre(nombre + 1);
}

int palindrome (char *phrase, int NbCaract) {

    if (NbCaract<=1) return 1;


    if (phrase [0]==phrase[NbCaract-1])
        return palindrome(phrase+1,NbCaract-2);

    return 0;
}


int main() {
    printf("Hello, World!\n");
    char * nombre = "123456789";
    printf("\n La somme de 123456789 est %d", calculSommeChiffre(nombre));

    char * palin = "ressasser";
    int longeur = strlen(palin);
    if (palindrome(palin,longeur)==1)   printf("\npalindrome \n");
    else printf("\nNon palindrome \n");

    return 0;
}
