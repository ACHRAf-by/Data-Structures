#ifndef PILES_WITHARRAY_H
#define PILES_WITHARRAY_H
#define MAX 10

typedef struct stack {
    int tab[MAX];
    int top;
} t_stack;

void init_stack(t_stack *); // initalize the data structure
int push_stack(t_stack *, int); // push value into stack
int pop_stack(t_stack *, int *); // pops top value from stack
int top_stack(t_stack *); // returns top value of stack
void display_stack(t_stack *); // displays the contents of the stack

#endif //PILES_WITHARRAY_H
