#include <stdio.h>
#include "Recursivity.c"

int main() {
    printf("Recursivity !\n");
    int produit = multiply(25, 5);
    printf("le produit de 25 et 5 est %d \n", produit);
    printf("Tap any button to continue ...\n");
    getchar();

    display(30);
    printf("\n");
    printf("Tap any button to continue ...\n");
    getchar();

    char depart = 'A';
    char final = 'C';
    char interm = 'B';
    printf(" Tour de Hanoi ^^ \n");
    towers(4, depart, final, interm);
    printf("Tap any button to continue ...\n");
    getchar();


    return 0;
}
