#ifndef CALCULATRICERPN_STACKIMPL_H
#define CALCULATRICERPN_STACKIMPL_H

typedef struct node {
    int val;
    struct node *next;
} t_node;

typedef struct stack {
    t_node *top;
} t_stack;

void init_stack(t_stack *); // initalize the data structure
int push_stack(t_stack *, int); // push value into stack
int pop_stack(t_stack *, int*); // pops top value from stack
int top_stack(t_stack *, int*); // returns top value of stack
void display_stack(t_stack *); // displays the contents of the stack

#endif //CALCULATRICERPN_STACKIMPL_H
