#include "Fonctions.h"
#include "stack.c"
#include <string.h>


// Return 1 if we got the same type of bracket :: 0 else
int CheckRightToLeft(char char1, char char2){

    if (char1 == '(' && char2 == ')'){
        return 1;
    }
    if(char1 == '[' && char2 ==']'){
        return 1;
    }
    if(char1 == '{' && char2 =='}'){
        return 1;
    }
    return 0;
}

// Return 1 is the expression is correct :: 0 else
int CheckExpr( char * expr ){
    int i = 0;
    char val;
    t_stack p;
    init_stack(&p);

    while (i < strlen(expr)){

        if(expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){
            push_stack(&p, expr[i]);
        }
        if (expr[i] == ')' ||expr[i] == ']' ||expr[i] == '}'){

            if(p.top == 0)
                return 0;

            if(CheckRightToLeft(top_stack(&p), expr[i]))
                pop_stack(&p,&val);
                printf("%c <--> %c \n", val, expr[i]);
        }
        i++;
    }
    if (p.top == 0)
        return 1;
    else
        return 0;
}
