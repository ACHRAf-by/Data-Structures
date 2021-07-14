#ifndef CALCULATRICE_RPN_CALCULATOR_H
#define CALCULATRICE_RPN_CALCULATOR_H


int priority(char op1, char op2);

void Infix2Postfix(char * Expr, char * postfix);

int EvalPost(char * postfix, int * res);

#endif //CALCULATRICE_RPN_CALCULATOR_H
