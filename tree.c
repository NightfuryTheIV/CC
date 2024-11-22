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



// Parcours en largeur de l'arbre
void BFVisit(p_node root) {
    if (root == NULL) {
        return; // L'arbre est vide
    }

    // Créer une file pour le parcours
    t_queue_tab q = createEmptyQueue();

    // Ajouter la racine dans la file
    enqueueTab_Queue(&q, root);

    while (!isQueueEmpty(q)) {

        // Extraire le nœud en tête de la file
        p_node current = dequeueTab_Queue(&q);

        // Afficher la valeur du nœud
        printf("%d ", current->value);

        // Ajouter les enfants gauche et droit à la file
        if (current->left != NULL) {
            enqueueTab_Queue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueueTab_Queue(&q, current->right);
        }
    }

    // Libérer la mémoire utilisée par la file
    freeQueue(&q);
}

t_tree createAVL(int *values, int size) {
    t_tree tree;
    tree.root = createNodeAVL(values, 0, size - 1);
    return tree;
}



////////////////////////////////////////
// TP 4 - Arbres binaires de recherche//
////////////////////////////////////////

void insertBST(t_tree *tree, int value) {
    p_node newNode = createNode(value);
    if (tree->root == NULL) {
        tree->root = newNode; // Cas où l'arbre est vide
        return;
    }

    p_node current = tree->root;
    while (1) {
        if (value < current->value) {
            if (current->left == NULL) {
                current->left = newNode; // Insertion à gauche
                break;
            }
            current = current->left;
        } else {
            if (current->right == NULL) {
                current->right = newNode; // Insertion à droite
                break;
            }
            current = current->right;
        }
    }
}