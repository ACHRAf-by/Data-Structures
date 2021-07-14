#include <stdio.h>

//#include "WithFile.h"
//#include "WithFile.c"

//#include "WithArray.h"
//#include "WithArray.c"

#include "WithLinkedList.h"
#include "WithLinkedList.c"

/*
 * You can chose one of the headers to specify the structure used for the implementation of the stack
*/

int main() {
    t_stack p;

    // Ne pas oublier d'enlever le commentaire pour la fonction pour ouvrir ou créer le fichier !
    //set_file(&p, "persistentStack"); //Fonction pour créer le fichier

    init_stack(&p);
    push_stack(&p, 5);
    push_stack(&p, 6);
    push_stack(&p, 7);
    display_stack(&p);

    printf("The head of the stack is : %d \n" , top_stack(&p)); //done only for Array and LinkedListImpl

    printf("Tap a button to start popping elements... \n");
    scanf("%*c");
    int val;

    pop_stack(&p, &val);
    printf("popped value = %d\n", val);
    display_stack(&p);

    pop_stack(&p, &val);
    printf("popped value = %d\n", val);
    display_stack(&p);

    pop_stack(&p, &val);
    printf("popped value = %d\n", val);
    display_stack(&p);

    pop_stack(&p, &val); // fails
    printf("popped value = %d\n", val); // prints out the old value
    display_stack(&p);


    //delete_file("persistentStack"); //Fonction pour supprimer un fichier
}
