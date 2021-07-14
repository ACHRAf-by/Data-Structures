#include "Fonctions.h"
#include "QueueForBreadthTraversal.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARBRE 20


ARBRE initTree() {
    return NULL;
}

int is_empty(ARBRE a) {
    return a == NULL;
}

// Fonction qui crée une feuille
ARBRE create_noeud(int valeur) {
    ARBRE a = malloc(sizeof(Sommet));
    a->val = valeur;
    a->filsg = NULL;
    a->filsd = NULL;
    return a;
}

void display_Tree(ARBRE a) {
    if (!is_empty(a)) {
        display_Tree(a->filsg);
        printf("[ %d ] ", a->val);
        display_Tree(a->filsd);
    }
}

// Fonction qui affiche un arbre binaire de façon plus claire {sag, racine, sad}
void display_struct_arbre(ARBRE a) {
    if (a == NULL) {
        printf("_");
    } else {
        printf("{");
        display_struct_arbre(a->filsg);
        printf("%d", a->val);
        display_struct_arbre(a->filsd);
        printf("}");
    }
}

int nombre_de_noeuds(ARBRE a) {
    if (a == NULL)
        return 0;
    return (1 + nombre_de_noeuds(a->filsg)
            + nombre_de_noeuds(a->filsd));
}


ARBRE insert(int valeur, ARBRE a) {
    if (is_empty(a)) {
        return create_noeud(valeur);
    }
    if (valeur < a->val) {
        a->filsg = insert(valeur, a->filsg);
    } else {
        a->filsd = insert(valeur, a->filsd);
    }
    return a;
}

// Parcours prefix : racine -> sag -> sad
void preorderTree(ARBRE a) {
    if (a != NULL) {
        printf(" -> (%d)", a->val);
        preorderTree(a->filsg);
        preorderTree(a->filsd);
    }

}

// Parcours infix : sag -> racine -> sad
void inorderTree(ARBRE a) {
    if (a != NULL) {
        inorderTree(a->filsg);
        printf(" -> (%d) ", a->val);
        inorderTree(a->filsd);
    }

}

// Parcours postfix : sag -> sad -> racine
void postorderTree(ARBRE a) {
    if (a != NULL) {
        postorderTree(a->filsg);
        postorderTree(a->filsd);
        printf(" -> (%d)", a->val);

    }
}

/*
 * J'ai essayé d'utiliser une file pour le parcours en largeur
 * First step : On enfile le noeud de départ
 * Second step : On défile et on incrémente un tableau contenants (arbre->val)
 * Third step : On visite les fils gauche et droite, on les enfile s'il existent et on les marque comme traités
 * On refait ça tant que la file n'est pas vide
*/

int *breadthTree(ARBRE a) {
    queue_t *file = (queue_t *) malloc(sizeof(queue_t));
    init_queue_list(file);
    int *tab = malloc(sizeof(int) * MAX_ARBRE);
    push_queue_list(file, a);
    ARBRE b = initTree();
    int i = 0;
    while (file->tete != NULL) {
        pop_queue_list(file, &b);
        tab[i] = b->val;
        printf(" -> (%d)", tab[i]);
        if (b->filsg != NULL) {
            push_queue_list(file, b->filsg);
        }
        if (b->filsd != NULL) {
            push_queue_list(file, b->filsd);
        }
        i++;
    }
    return tab;
}

ARBRE searchTree(ARBRE a, int data) {

    while (a != NULL) {
        if (data < a->val) {
            a = a->filsg;
        } else {

            if (data > a->val) {
                a = a->filsd;
            } else {
                return a;
            }
        }
    }
    return NULL;
}

int maxTree(ARBRE a) {

    if (a->filsd == NULL) {
        return a->val;
    }
    return maxTree(a->filsd);
}

int minTree(ARBRE a) {

    if (a->filsg == NULL) {
        return a->val;
    }
    return minTree(a->filsg);
}

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int hauteur(ARBRE a) {
    if (is_empty(a)) {
        return 0;
    }
    return 1 + max(hauteur(a->filsg), hauteur(a->filsd));
}

void desalloue(ARBRE a) {
    if (!is_empty(a)) {
        desalloue(a->filsg);
        desalloue(a->filsd);
        free(a);
    }
}

int est_equilibre(ARBRE a) {
    if (is_empty(a)) return 1;
    int dif = hauteur(a->filsg) - hauteur(a->filsd);
    return est_equilibre(a->filsg) && est_equilibre(a->filsd) &&
           (dif == -1 || dif == 0 || dif == 1);
}

int est_feuille(ARBRE a) {
    return !is_empty(a) && is_empty(a->filsg) && is_empty(a->filsd);
}

// Fonction qui supprime un noeud de l'arbre
ARBRE supprime(ARBRE a, int valeur) {

    if (is_empty(a)) return NULL;
    if (a->val == valeur) {
        if (est_feuille(a)) {
            free(a);
            return NULL;
        }
        if (is_empty(a->filsg)) {
            ARBRE temp = a->filsd;
            free(a);
            return temp;
        }
        if (is_empty(a->filsd)) {
            ARBRE temp = a->filsg;
            free(a);
            return temp;
        }
        ARBRE temp = a->filsg;
        if (!is_empty(temp->filsd)) {
            ARBRE pere = a;
            while (!is_empty(temp->filsd)) {
                pere = temp;
                temp = temp->filsd;
            }
            pere->filsd = temp->filsg;
            temp->filsg = a->filsg;
        }
        temp->filsd = a->filsd;
        free(a);
        return temp;
    } else {
        if (a->val > valeur) {
            a->filsg = supprime(a->filsg, valeur);
        } else {
            a->filsd = supprime(a->filsd, valeur);
        }
        return a;
    }
}