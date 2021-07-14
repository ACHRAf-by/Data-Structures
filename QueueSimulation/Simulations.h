#ifndef QUEUESIMULATION_SIMULATIONS_H
#define QUEUESIMULATION_SIMULATIONS_H

typedef struct {
    int number;
    int arrival_time;
    int treatment_time;
} Patient;

typedef struct ElementList {
    Patient patient;
    struct ElementList *next;
} Element;

typedef struct {
    Element *tete, *queue;
    int size;
} File;

void init_file_attente(File *file);

void Enfiler(File *, Patient);

int Defiler(File *, Patient *);

int PatientsList(File *file);

void simulation(File *file);

void display_queue(File *);

#endif //QUEUESIMULATION_SIMULATIONS_H
