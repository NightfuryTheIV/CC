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

    return nouv;
}

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