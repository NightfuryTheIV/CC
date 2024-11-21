//
// Created by moind on 21/11/2024.
//

#include "tree.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

p_tree createEmptyTree() {

    // Allocation de la mémoire nécesaire à la création de la liste
    t_tree* tree = (t_tree*)malloc(sizeof (t_tree));
    tree->root = NULL;
    return tree;

}

int isBST(t_tree t) {
    return isNodeBST(t.root);
}

p_node searchBST(t_tree t, int val)
{
    p_node temp = t.root;
    while (temp != NULL) {
        if (val > temp->value) {
            if (temp->right == NULL) {
                return NULL;
            } else {
                temp = temp->right;
            }

        } else if (val < temp->value) {
            if (temp->left == NULL) {
                return NULL;
            } else {
                temp = temp->left;
            }

        } else {
            return temp;
        }
    }
    return NULL;
}


int treeHeight(p_node root) {
    return nodeHeight(root);
}

int treeNodeCount(p_node root) {
    return nodeCount(root);
}

p_node pnodeValueInTree(p_node root, int value) {
    return seekNodeValue(root, value);
}

void updateTreeDepth(p_node root) {
    updateNodeDepth(root, 0);
}

int isPerfectTree(p_node root) {

    if (root == NULL) {
        return 1;
    }

    int height = nodeHeight(root);
    int totalNodes = nodeCount(root);
    return totalNodes == intpow(2, height + 1) - 1;
}

int isDegeneratedTree(p_node node) {

    if (node == NULL) {
        return 1;
    }
    if (node->left != NULL && node->right != NULL) {
        return 0;
    }

    return isDegeneratedTree(node->left) && isDegeneratedTree(node->right);
}

int isBalancedTree(p_node root) {

    if (root == NULL) {
        return 1;
    }
    if (isPerfectTree(root)) {
        return 1;
    }
    if (isDegeneratedTree(root)) {
        return 0;
    }
    return isBalancedNode(root); // Vérification récursive pour les autres cas
}

int intpow(int base, int exp) {
    if (exp < 0) {
        return 0; // Cas non géré : puissances négatives
    }
    if (exp == 0) {
        return 1; // Toute base élevée à 0 vaut 1
    }
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

void updateTreeHeights(p_node root) {
    if (root == NULL) {
        return;
    }
    updateTreeHeights(root->left);
    updateTreeHeights(root->right);
    updateNodeHeight(root);
}

void updateNodeBF(p_node node) {
    if (node == NULL) {
        return;
    }
    int leftHeight = (node->left != NULL) ? node->left->height : -1;
    int rightHeight = (node->right != NULL) ? node->right->height : -1;
    node->BF = leftHeight - rightHeight;
}

void updateTreeBFs(p_node root) {
    if (root == NULL) {
        return;
    }
    updateTreeBFs(root->left);
    updateTreeBFs(root->right);
    updateNodeBF(root);
}

int isAVL(p_node root) {
    if (root == NULL) {
        return 1; // Un arbre vide est AVL
    }

    // Appel à la fonction computeBFs() (fournie en bibliothèque)
    computeBFs(root);

    // Vérification récursive des facteurs d'équilibrage
    if (root->BF < -1 || root->BF > 1) {
        return 0; // Si un nœud a |BF| > 1, l'arbre n'est pas AVL
    }

    return isAVL(root->left) && isAVL(root->right);
}

p_node leftRotation(p_node root) {
    if (root == NULL || root->right == NULL) {
        return root; // La rotation n'est pas possible
    }

    p_node newRoot = root->right; // Le nouveau nœud racine
    root->right = newRoot->left;  // Sous-arbre gauche de B devient le sous-arbre droit de A
    newRoot->left = root;         // A devient le sous-arbre gauche de B

    // Mettre à jour les hauteurs des nœuds
    updateNodeHeight(root);
    updateNodeHeight(newRoot);

    return newRoot; // Retourner la nouvelle racine
}

p_node rightRotation(p_node root) {
    if (root == NULL || root->left == NULL) {
        return root; // La rotation n'est pas possible
    }

    p_node newRoot = root->left;  // Le nouveau nœud racine
    root->left = newRoot->right;  // Sous-arbre droit de B devient le sous-arbre gauche de C
    newRoot->right = root;        // C devient le sous-arbre droit de B

    // Mettre à jour les hauteurs des nœuds
    updateNodeHeight(root);
    updateNodeHeight(newRoot);

    return newRoot; // Retourner la nouvelle racine
}

p_node doublerightRotation(p_node root) {
    if (root == NULL || root->left == NULL) {
        return root; // La rotation n'est pas possible
    }

    root->left = leftRotation(root->left); // Rotation gauche sur le sous-arbre gauche
    return rightRotation(root);           // Rotation droite sur la racine
}

p_node doubleleftRotation(p_node root) {
    if (root == NULL || root->right == NULL) {
        return root; // La rotation n'est pas possible
    }

    root->right = rightRotation(root->right); // Rotation droite sur le sous-arbre droit
    return leftRotation(root);               // Rotation gauche sur la racine
}

// Parcours en largeur de l'arbre
void BFVisit(p_node root) {
    if (root == NULL) {
        return; // L'arbre est vide
    }

    // Créer une file pour le parcours
    t_queue q = createQueue(2);

    // Ajouter la racine dans la file
    enqueue(&q, root);

    while (!isQueueEmpty(q)) {
        // Extraire le nœud en tête de la file
        p_node current = dequeue(q);

        // Afficher la valeur du nœud
        printf("%d ", current->value);

        // Ajouter les enfants gauche et droit à la file
        if (current->left != NULL) {
            enqueue(q, current->left);
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
        }
    }

    // Libérer la mémoire utilisée par la file
    freeQueue(q);
}

t_tree createAVL(int *values, int size) {
    t_tree tree;
    tree.root = createNodeAVL(values, 0, size - 1);
    return tree;
}