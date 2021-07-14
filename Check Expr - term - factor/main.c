#include <stdio.h>
#include "Fonctions.h"
#include "Fonctions.c"

int main() {
    printf("Exo 4 !\n");

    char *expression1 = "a*x*x+b*x+c";
    char *expression2 = "a*b+y";
    char *expression3 = "(a*b+y";

    int ppos = 0;
    if (expr(expression1, &ppos)) {
        printf("%s | Valid expression \n", expression1);
    } else { printf("%s | Invalid expression\n",expression1); }

    ppos = 0;
    if (expr(expression2, &ppos)) {
        printf("%s | Valid expression \n",expression2);
    } else { printf("%s | Invalid expression\n",expression2); }

    ppos = 0;
    if (expr(expression3, &ppos)) {
        printf("%s | Valid expression \n",expression3);
    } else { printf("%s | Invalid expression\n",expression3); }

    return 0;
}
