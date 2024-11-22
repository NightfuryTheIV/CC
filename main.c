#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void testTreeFunctions() {
    // Créer un arbre vide
    p_tree tree = createEmptyTree();
    printf("Arbre vide créé.\n");

    // Insérer des valeurs dans l'arbre BST
    int values[] = {15, 10, 20, 8, 12, 17, 25};
    for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++) {
        insertBST(tree, values[i]);
    }
    printf("Valeurs insérées dans l'arbre BST.\n");

    // Tester la hauteur de l'arbre
    int height = treeHeight(tree->root);
    printf("Hauteur de l'arbre : %d\n", height);

    // Tester le comptage des nœuds
    int nodeCount = treeNodeCount(tree->root);
    printf("Nombre de nœuds dans l'arbre : %d\n", nodeCount);

    // Tester la recherche d'une valeur
    int searchValue = 12;
    p_node foundNode = pnodeValueInTree(tree->root, searchValue);
    if (foundNode) {
        printf("Valeur %d trouvée dans l'arbre.\n", searchValue);
    } else {
        printf("Valeur %d non trouvée dans l'arbre.\n", searchValue);
    }

    // Tester si l'arbre est un BST
    if (isBST(*tree)) {
        printf("L'arbre est un BST.\n");
    } else {
        printf("L'arbre n'est pas un BST.\n");
    }

    // Tester si l'arbre est parfait
    if (isPerfectTree(tree->root)) {
        printf("L'arbre est parfait.\n");
    } else {
        printf("L'arbre n'est pas parfait.\n");
    }

    // Tester si l'arbre est AVL
    if (isAVL(tree->root)) {
        printf("L'arbre est AVL.\n");
    } else {
        printf("L'arbre n'est pas AVL.\n");
    }

    // Afficher les nœuds de l'arbre en parcours largeur
    printf("Parcours largeur de l'arbre : ");
    BFVisit(tree->root);
    printf("\n");

    // Libérer la mémoire de l'arbre
    free(tree);
    printf("Mémoire de l'arbre libérée.\n");
}

int main() {
    printf("=== Test des fonctions de l'arbre ===\n");
    testTreeFunctions();
    return 0;
}
