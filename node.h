#include <stdlib.h>

#ifndef CC_NODE_H
#define CC_NODE_H

/**
 * @brief Structure for the queue of integers
 */
struct s_node
{
 int value;
 struct s_node   *left, *right;
 int depth;
};

typedef struct s_node t_node, *p_node;

/***
 * @brief
 * @param
 * @return
 */
p_node createNode(int);

int isNodeBST(p_node);

int nodeHeight(p_node* node);

#endif //CC_NODE_H
