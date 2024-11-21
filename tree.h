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

#endif //CC_TREE_H
