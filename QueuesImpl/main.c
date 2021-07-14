#include <stdio.h>
#include <stdlib.h>
#include "WithLinkedList.h"

int main() {
    printf("Implementation of a QUEUE with a linked list!\n");

    queue_t *file;
    if ((file = (queue_t *) malloc(sizeof(queue_t))) == NULL)
        return -1;
    init_queue_list(file);
    push_queue_list(file, 20);
    push_queue_list(file, 15);
    push_queue_list(file, 10);
    push_queue_list(file, 5);
    push_queue_list(file, 0);

    display_queue_list(file);

    int val;
    pop_queue_list(file, &val);
    pop_queue_list(file, &val);

    printf("\n Display after applying pop for two elements \n");
    display_queue_list(file);

    printf("\n Display with a recursive function \n");
    display_rec(file);
    return 0;
}
