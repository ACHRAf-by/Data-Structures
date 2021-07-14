#include <stdio.h>
#include "Fonctions.c"

int main() {
    printf("Check Parantheses!\n");

    char * str = "{[((  ))]}";
    int bool = CheckExpr(str);

    if(bool == 1){
        printf("Expression is correct and balanced \n");
    } else
        printf("Parantheses are not correctly nested \n");
    
    return 0;
}
