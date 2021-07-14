
#include "Recursivity.h"

/* Multiplication récursive
     25 * 5 = 25 * 4 + 25
            = 25 * 3 + 50
            = 25 * 2 + 75
            = 25 * 1 + 100
            = 25 * 0 + 125
            = 125
     --> A * B = A * (B - i) + iA ; ( i allant de 1 à B)

*/
int multiply(int a, int b) {
    int p;
    if (b == 0 || a == 0) {
        return 0;
    }

    p = multiply(a, b - 1) + a;

    return p;
}

// Fonction qui affiche les entiers de 1 à n

void display(int n) {

    if (n > 1)
        display(n - 1);

    printf("%3d", n);
}

/* Tour de Hanoi

 Pour N = 1 ; N = 2 ; N = 3 c'est plutot facile.
 La compléxité commence à augmenter à partir de 4 / 5 disques
 ce qui nous fait penser récursivement (On peut résoudre le probléme pour 4 disques vu qu'on l'a résolu pour 3 disques)

 faire passer N-1 disques sur le pilier intermédiaire
 faire passer le Ni-ème disque sur le pilier final
 faire passer les N-1 disques du pilier intermédaire sur le pilier final

 Compléxité exponentielle !

 */
void towers(int n, char frompeg, char topeg, char auxpeg) {

    if (n == 1) {
        printf("From peg %c : to peg %c \n", frompeg, topeg);
    } else {
        towers(n - 1, frompeg, auxpeg, topeg);
        towers(1, frompeg, topeg, auxpeg);
        towers(n - 1, auxpeg, topeg, frompeg);
    }
}