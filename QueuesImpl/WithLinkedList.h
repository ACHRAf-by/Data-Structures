#ifndef QUEUESIMPL_WITHLINKEDLIST_H
#define QUEUESIMPL_WITHLINKEDLIST_H

typedef int TypeDonnee; //Used to change the type of elements ( can move to char, float, ...)

typedef struct ElementList {
    TypeDonnee donnee;
    struct ElementList *next;
} Element;

typedef struct {
    Element *tete, *queue;
    int size;
} queue_t;

void init_queue_list(queue_t *); // initialize the data structure
void push_queue_list(queue_t *Pf, int val); // push value into queue
int pop_queue_list(queue_t *Pf, int *val); // pops value from queue;
void display_queue_list(queue_t *); // displays the contents of the queue
void display_rec(queue_t *);

#endif //QUEUESIMPL_WITHLINKEDLIST_H
