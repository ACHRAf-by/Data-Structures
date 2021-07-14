
#include <stdlib.h>
#include <stdio.h>
#include "WithLinkedList.h"

void init_stack(t_stack *stack) {
    if (stack == NULL) {
        return;
    }
    stack->top = NULL;
}

int push_stack(t_stack *stack, int value) {
    if (stack == NULL) {
        return 0;
    }
    t_node *node = malloc((sizeof(t_node)));
    node->val = value;
    node->next = stack->top;
    stack->top = node;
    return 1;
}

int pop_stack(t_stack *stack, int *value) {
    if (stack == NULL || stack->top == NULL) {
        return 0;
    }
    *value = stack->top->val;
    stack->top = stack->top->next;
    return 1;
}

int top_stack(t_stack *stack) {
    if (stack == NULL || stack->top == NULL) {
        return 0;
    }
    int value;
    value = stack->top->val;
    return value;
}

void display_stack(t_stack *stack) {
    if (stack == NULL) {
        printf("Empty\n");
    }
    t_node *temp = stack->top;
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
}

