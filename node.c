//
// Created by moind on 21/11/2024.
//

#include "node.h"
#include <stdlib.h>

p_node createNode(int val)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->value = val;
    nouv->left = nouv->right = NULL;
    nouv->BF = 0;

    return nouv;
}










int nodeHeight(p_node node) {

    if (node == NULL) {
        return -1;
    }

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    if (leftHeight > rightHeight) {
        return 0 + leftHeight;
    }
    else {
        return 0 + rightHeight;
    }

}

int nodeCount(p_node node) {

    if (node == NULL) {
        return 0;
    }

    int leftCount = nodeCount(node->left);
    int rightCount = nodeCount(node->right);

    return 1 + leftCount + rightCount;
}


p_node seekNodeValue(p_node node, int value) {

    if (node == NULL) {
        return NULL;
    }

    if (node->value == value) {
        return node;
    }

    p_node foundNode = seekNodeValue(node->left, value);

    if (foundNode == NULL) {
        foundNode = seekNodeValue(node->right, value);
    }

    return foundNode;
}

void updateNodeDepth(p_node node, int depth) {

    if (node == NULL) {
        return;
    }

    node->depth = depth;

    // Mettre à jour les profondeurs des sous-arbres
    updateNodeDepth(node->left, depth + 1);
    updateNodeDepth(node->right, depth + 1);
}

int isBalancedNode(p_node node) {

    if (node == NULL) {
        return 1;
    }

    int leftHeight = nodeHeight(node->left);
    int rightHeight = nodeHeight(node->right);

    if (abs(leftHeight - rightHeight) > 1) {
        return 0;
    }

    return isBalancedNode(node->left) && isBalancedNode(node->right);
}


void computeBFs(p_node node) {
    if (node == NULL) {
        return;
    }

    // Calcul des BF pour les sous-arbres gauche et droit
    computeBFs(node->left);
    computeBFs(node->right);

    // Calculer la hauteur des sous-arbres gauche et droit
    int leftHeight = (node->left != NULL) ? node->left->height : -1;
    int rightHeight = (node->right != NULL) ? node->right->height : -1;

    // Mettre à jour la hauteur du nœud actuel
    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);

    // Calculer et mettre à jour le BF du nœud actuel
    node->BF = leftHeight - rightHeight;
}

p_node createNodeAVL(int *values, int start, int end) {
    if (start > end) {
        return NULL; // Base : aucun nœud dans cet intervalle
    }

    // Trouver l'élément du milieu
    int mid = (start + end) / 2;

    // Créer un nœud avec la valeur du milieu
    p_node newNode = (p_node)malloc(sizeof(t_node));
    newNode->value = values[mid];
    newNode->left = createNodeAVL(values, start, mid - 1); // Sous-arbre gauche
    newNode->right = createNodeAVL(values, mid + 1, end);  // Sous-arbre droit

    return newNode;
}

void updateNodeBF(p_node node) {
    if (node == NULL) {
        return;
    }
    int leftHeight = (node->left != NULL) ? node->left->height : -1;
    int rightHeight = (node->right != NULL) ? node->right->height : -1;
    node->BF = leftHeight - rightHeight;
}



////////////////////////////////////////
// TP 4 - Arbres binaires de recherche//
////////////////////////////////////////


int isNodeBST(p_node pn)
{
    if (pn == NULL) {
        return 1;
    }
    if (pn->left != NULL) {
        if (pn->left->value >= pn->value) {
            return 0;
        }
    }
    if (pn->right != NULL) {
        if (pn->right->value <= pn->value) {
            return 0;
        }
    }
    return (isNodeBST(pn->left) && isNodeBST(pn->right));
}



/////////////////
// TP 6 - AVls //
/////////////////

void updateNodeHeight(p_node node) {
    if (node == NULL) {
        return;
    }
    int leftHeight = (node->left != NULL) ? node->left->height : -1;
    int rightHeight = (node->right != NULL) ? node->right->height : -1;
    node->height = 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
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