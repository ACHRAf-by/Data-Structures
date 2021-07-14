#include <stdio.h>
#include <stdlib.h>
#include "Simulations.h"

int main() {
    printf("Hello Doctor !\n");

    File *file;
    if ((file = (File *) malloc(sizeof(File))) == NULL)
        return -1;
    init_file_attente(file);

    simulation(file);


    return 0;
}
