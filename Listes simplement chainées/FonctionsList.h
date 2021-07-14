#ifndef FONCTIONSLIST_H_INCLUDED
#define FONCTIONSLIST_H_INCLUDED

typedef struct maillon{

    int x ; //Contenu d'une case de la liste
    struct maillon * suiv ; // Pointeur vers la case suivante

} maillon_t ;


maillon_t *ajouter_debut(maillon_t * pliste , int val );

maillon_t *ajouter_fin (maillon_t * pliste , int val );

maillon_t *rechercher_val ( maillon_t * pliste , int val ) ;

maillon_t *supprimer_debut (maillon_t * pliste) ;

maillon_t *supprimer_fin (maillon_t * pliste);

maillon_t *supprimer_val (maillon_t * pliste , int val);

void afficher_liste(maillon_t * pliste );


#endif // FONCTIONSLIST_H_INCLUDED
