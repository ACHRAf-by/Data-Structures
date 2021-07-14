#include <stdio.h>
#include "Fonctions.h"

int main() {


    ARBRE a = initTree();
    ARBRE b = create_noeud(18);
    b = insert(17, b);
    b = insert(9, b);
    b = insert(6, b);
    b = insert(2, b);
    b = insert(30, b);
    b = insert(24, b);
    display_Tree(b);
    printf("\n Height of the tree is %d \n", hauteur(b));
    printf(" Number of nodes of the tree %d \n", nombre_de_noeuds(b));

    printf("Max of tree is %d \n ", maxTree(b));
    printf("Min of tree is %d \n", minTree(b));
    if (est_equilibre(b)) printf("Blanaced tree : AVL ");

    printf("Preorder Traversal \n ");
    preorderTree(b);

    printf("\n Inorder Traversal \n");
    inorderTree(b);

    printf("\n Postorder Traversal \n");
    postorderTree(b);

    printf("\n Breadth first traversal \n");
    breadthTree(b);
    printf("\n");


    b = supprime(b, 17);
    printf("Display Tree after deleting value '17' : \n");
    display_Tree(b);
    printf("\n");

    int valToSearch = 30;
    if (searchTree(b, valToSearch) != NULL) {
        printf("Value found ! \n");
    } else printf("Not found \n");
    desalloue(b);
    return 0;
}
