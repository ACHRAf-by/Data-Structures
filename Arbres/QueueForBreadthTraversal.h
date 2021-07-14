#ifndef ARBRES_QUEUEFORBREADTHTRAVERSAL_H
#define ARBRES_QUEUEFORBREADTHTRAVERSAL_H

#include "Fonctions.h"


typedef struct ElementList {
    ARBRE donnee;
    struct ElementList *next;
} Element;

// Struct d'une file avec une liste
typedef struct {
    Element *tete, *queue;
    int size;
} queue_t;

void init_queue_list(queue_t *); // initialize the data structure
void push_queue_list(queue_t *Pf, ARBRE val); // push value into queue
int pop_queue_list(queue_t *Pf, ARBRE *val); // pops value from queue;

#endif //ARBRES_QUEUEFORBREADTHTRAVERSAL_H
