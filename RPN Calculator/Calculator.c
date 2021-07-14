#include "Calculator.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int priority(char op1, char op2) {
    char priority[6] = {')', '+', '-', '*', '/', '('};
    int i;
    int p1, p2;
    if (op1 == '(' || op2 == '(') {
        return -1;
    }
    for (i = 0; i < 6; i++) {
        if (op1 == priority[i]) p1 = i;
        if (op2 == priority[i]) p2 = i;
    }
    if (p1 > p2)
        return 1;
    if (p2 > p1)
        return 0;

    return -1;
}

void Infix2Postfix(char * Infix, char * postfix){
    int i=0;
    int j=0;
    int val;
    t_stack p;
    init_stack(&p);

    while(i<strlen(Infix)){
        if (isdigit((int)Infix[i])){
            postfix[j] = Infix[i];
            i++;
            j++;
        }
        else{
            while (top_stack(&p,&val) == 1 && priority((char)val, Infix[i]) >= 0) {
                pop_stack(&p, &val);
                if (val != '(') {
                    postfix[j] = (char)val;
                    j++;
                }
            }
            // Sauf Infix[i] == '('
            if(Infix[i] != ')')
                push_stack(&p,(int )Infix[i]);
            i++;
        }
    }
    while (top_stack(&p,&val) != 0){
        pop_stack(&p,&val);
        if (val != '('){
            postfix [j] = (char)val;
            j++;
        }
    }
}

int EvalPost(char *postfix, int *res) {
    int i = 0;
    t_stack p;

    init_stack(&p);
    *res = 0;

    while (postfix[i]) {

        if (postfix[i] >= '0' && postfix[i] <= '9')
            push_stack(&p, postfix[i] - '0'); // To get the number --> sub of the Ascii codes
        else {
            int op1, op2, temp;
            pop_stack(&p, &op1);
            pop_stack(&p, &op2);
            printf("op1 = %d op2 = %d\n", op1, op2);
            printf("The operation : %c\n" , postfix[i]);
            switch (postfix[i]) {
                case '+':
                    temp = op1 + op2;
                    break;
                case '-' :
                    temp = op2 - op1;
                    break;
                case '*' :
                    temp = op1 * op2;
                    break;
                case '/' :
                    if (op2 == 0){
                        printf("cannot divide by 0");
                        return -1;
                    }
                    temp = op2 / op1;
                    break;
            }
            printf("%d \n", temp);
            push_stack(&p, temp);
        }
        i++;
    }
    pop_stack(&p, res);
    return 0;
}