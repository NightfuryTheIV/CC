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