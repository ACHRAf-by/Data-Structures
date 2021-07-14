

#ifndef UNTITLED_NOMBRESLARGES_H
#define UNTITLED_NOMBRESLARGES_H


//Definition of a Boolean

typedef enum {
    false,
    true
} Bool;


//Def d'un maillon de la liste
typedef struct DlisteNode {

    char * x ;
    struct DlisteNode * pred ;
    struct DlisteNode * suiv ;

} DlisteNode;

//Def d'une Dlist

typedef struct Dlist {

    int longueur;
    struct DlisteNode *first;
    struct DlisteNode *last;
} *Dlist;

// Prototypes


Bool is_empty_liste(Dlist li);
Dlist new_liste();

int dlist_length(Dlist li);

char *dlist_first(Dlist li);

char *dlist_last(Dlist li);

Dlist RemplirListes(Dlist li , char * chiffre);

void afficher_dlist(Dlist li);

Dlist ajout_element(Dlist li, void *str); // Push front; (void *) en parametres pour définir la généricité

Dlist SommeNombreLarge(Dlist l1 , Dlist l2);


#endif //UNTITLED_NOMBRESLARGES_H
