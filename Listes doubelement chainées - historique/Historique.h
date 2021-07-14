#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED



//Definition of a Boolean

typedef enum {
    false,
    true
} Bool;


//Def d'un maillon de la liste
typedef struct DlisteNode {

    char * x ;
    struct DlisteNode * suiv ;
    struct DlisteNode * pred ;

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

void afficher_dlist(Dlist li);

Dlist ajout_element(Dlist li, char *str); // Push front

Dlist retirer_element(Dlist li); //Pop front -> last entered element

Dlist clear_dlist(Dlist li);

void naviguer (Dlist li);



#endif // HISTORIQUE_H_INCLUDED
