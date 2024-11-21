//
// Created by moind on 21/11/2024.
//

#include "tree.h"
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