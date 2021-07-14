#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StackImpl.c"
#include "Calculator.c"


int main() {
    printf("############################\n");
    printf("        Calculator          \n");
    printf("############################\n");

    char * infix = "(1+2)*5-6";
    char * postfix = malloc(sizeof(char)*strlen(infix));

    int result;
    Infix2Postfix(infix, postfix);
    printf("Infix Format is %s \n",infix);
    printf("Postfix Format is %s \n", postfix);

    EvalPost(postfix, &result );

    printf("Result is %d ",result);

    return 0;
}
