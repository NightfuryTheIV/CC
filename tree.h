//
// Created by moind on 21/11/2024.
//

#ifndef CC_TREE_H
#define CC_TREE_H

#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

p_tree createEmptyTree();

int isBST(t_tree);

p_node searchBST(t_tree t, int val);

int treeHeight(p_node root);

int treeNodeCount(p_node root);

p_node pnodeValueInTree(p_node root, int value);

void updateTreeDepth(p_node root);

int isPerfectTree(p_node root);

int isDegeneratedTree(p_node node);

int isBalancedTree(p_node root);

int intpow(int base, int exp);

void updateTreeHeights(p_node root);

void updateTreeBFs(p_node root);

int isAVL(p_node root);

p_node leftRotation(p_node root);

p_node rightRotation(p_node root);

p_node doublerightRotation(p_node root);

p_node doubleleftRotation(p_node root);

void BFVisit(p_node root);

t_tree createAVL(int *values, int size);

#endif //CC_TREE_H
