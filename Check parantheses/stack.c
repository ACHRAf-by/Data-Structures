
#include "stack.h"
#include <stdio.h>


void init_stack(t_stack *stack) {
    if (stack == NULL) {
        return;
    }
    stack->top = 0;
}

int push_stack(t_stack *stack, char value) {
    if (stack == NULL) {
        return 0;
    }
    if (stack->top > MAX) {
        return 0;
    }
    stack->tab[stack->top] = value;
    stack->top++;
    return 1;
}

int pop_stack(t_stack *stack, char *value) {
    if (stack == NULL) {
        return 0;
    }
    *value = stack->tab[stack->top - 1];
    if (stack->top > 0) {
        stack->top--;
    }
    return 1;
}

char top_stack(t_stack *stack) {
    if (stack == NULL) {
        return 0;
    }
    char value;
    value = stack->tab[stack->top - 1];

    return value;
}

void display_stack(t_stack *stack) {
    if (stack == NULL) {
        printf("Empty \n");
    }
    for (int i = stack->top; i > 0; --i) {
        printf("%c\n", stack->tab[i - 1]);
    }
}
