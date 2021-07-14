
#ifndef CHECKPARANTHESES_STACK_H
#define CHECKPARANTHESES_STACK_H

#define MAX 20

typedef struct stack {
    char tab[MAX];
    int top;
} t_stack;

void init_stack(t_stack *); // initalize the data structure
int push_stack(t_stack *, char); // push value into stack
int pop_stack(t_stack *, char *); // pops top value from stack
char top_stack(t_stack *); // returns top value of stack

#endif //CHECKPARANTHESES_STACK_H
