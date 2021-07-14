#ifndef ARBRES_FONCTIONS_H
#define ARBRES_FONCTIONS_H

// Arbre binaire : Racine -> 2 noeuds fils gauche et droite
struct sommet {
    int val;
    struct sommet *filsg;
    struct sommet *filsd;
};

typedef struct sommet Sommet;
typedef Sommet *ARBRE;

ARBRE initTree();

int is_empty(ARBRE a);

ARBRE create_noeud(int val);

void display_Tree(ARBRE a);

void display_struct_arbre(ARBRE a);

int nombre_de_noeuds(ARBRE a);

void preorderTree(ARBRE a);

void inorderTree(ARBRE a);

void postorderTree(ARBRE a);

int *breadthTree(ARBRE a);

ARBRE insert(int valeur, ARBRE a);

int maxTree(ARBRE a);

int minTree(ARBRE a);

ARBRE searchTree(ARBRE a, int data);

int hauteur(ARBRE a);

void desalloue(ARBRE a);

int est_equilibre(ARBRE a);

ARBRE supprime(ARBRE a, int valeur);

#endif //ARBRES_FONCTIONS_H
