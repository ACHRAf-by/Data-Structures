#include "QueueForBreadthTraversal.h"
#include <stdlib.h>
#include <stdio.h>


void init_queue_list(queue_t *Pf) {
    Pf->tete = NULL;
    Pf->size = 0;
}

void push_queue_list(queue_t *Pf, ARBRE val) {
    Element *elem;
    elem = (Element *) malloc(sizeof(Element));
    elem->donnee = val;
    elem->next = NULL;
    if (Pf->tete == NULL || Pf->size == 0) {
        Pf->queue = Pf->tete = elem;
    } else {
        Pf->queue->next = elem;
        Pf->queue = elem;
    }
    Pf->size++;
}

int pop_queue_list(queue_t *Pf, ARBRE *val) {

    Element *elem;
    if (Pf->tete == NULL || Pf->size == 0) {
        printf("The queue is empty, cannot pop any element ^^ \n");
        return -1;
    }
    *val = Pf->tete->donnee;
    elem = Pf->tete;
    Pf->tete = Pf->tete->next;
    free(elem);
    Pf->size--;

    return 0;
}