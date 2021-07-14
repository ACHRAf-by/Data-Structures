#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <process.h>
#include "Simulations.h"


#define TREATMENT_TIME_MAX 30 // Temps de traitrment d'un patient max
#define BLOOD_ANALYSE_MAX_TIME 6 // Temps d'analyse de sang max

void init_file_attente(File *file) {
    file->tete = NULL;
    file->size = 0;
}

void Enfiler(File *file, Patient p) {

    Element *elem;
    elem = (Element *) malloc(sizeof(Element));
    elem->patient.number = p.number;
    elem->patient.arrival_time = p.arrival_time;
    elem->patient.treatment_time = p.treatment_time;
    if (file->tete == NULL) {
        file->queue = file->tete = elem;
    }
    file->queue->next = elem;
    file->queue = elem;
    file->size++;
}

int Defiler(File *file, Patient *p) {
    Element *elem;
    if (file->tete == NULL || file->size == 0) {
        printf(" La salle d'attente est vide ^^ \n");
        return -1;
    }

    *p = file->tete->patient;
    elem = file->tete;
    file->tete = file->tete->next;
    free(elem);
    file->size--;

    return 0;
}

int PatientsList(File *file) {

    int nbPatients;
    int T = 8; // Date d'arrivée du premier patient
    Patient patient;
    printf("Enter the number of clients for today : ");
    scanf("%d", &nbPatients);
    srand(time(NULL) + getpid());
    for (int i = 0; i < nbPatients; i++) {
        patient.number = i;
        patient.arrival_time = T;
        patient.treatment_time = 4 + rand() % TREATMENT_TIME_MAX;
        T = T + 1;
        Enfiler(file, patient);
    }
    return nbPatients;
}

void simulation(File *file) {
    int global_time = 0;
    int waiting_time = 10; // We suppose that the first person will wait 10min before doctor's call
    int global_waiting_time = 0;
    int cmp = 0;
    int nb_patients = PatientsList(file);
    display_queue(file);
    Patient p;
    printf("For today we have %d patients : \n", nb_patients);
    while (cmp < nb_patients) {
        Defiler(file, &p);
        printf(" Client %d has finished his consultation \n", p.number);
        global_waiting_time += waiting_time;

        printf(" Client %d has waited %d minutes \n ", p.number, waiting_time);
        printf(" --------------------------------------- \n ");
        int blood_test_time = rand() % BLOOD_ANALYSE_MAX_TIME;
        global_time = global_time + p.treatment_time + blood_test_time;
        waiting_time = p.treatment_time + blood_test_time;
        cmp++;
    }

    printf("Average global time is %.2f min \n", (float) global_time / nb_patients);
    printf(" Average Waiting time is %.2f min \n", (float) global_waiting_time / nb_patients);
}

void display_queue(File *file) {
    Element *courant;
    int i;
    courant = file->tete;
    for (i = 0; i < file->size; i++) {
        printf(" Client %d | arrival time : %dh | treatment time : %d min \n", courant->patient.number,
               courant->patient.arrival_time, courant->patient.treatment_time);
        courant = courant->next;
    }
}


