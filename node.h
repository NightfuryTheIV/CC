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
 int height;
 int BF;
};

typedef struct s_node t_node, *p_node;

/***
 * @brief
 * @param
 * @return
 */
p_node createNode(int);

int isNodeBST(p_node);

int nodeHeight(p_node node);

int nodeCount(p_node node);

p_node seekNodeValue(p_node node, int value);

void updateNodeDepth(p_node node, int depth);

int isBalancedNode(p_node node);

void updateNodeHeight(p_node node);

void computeBFs(p_node node);

int isNodeBST(p_node node, int min, int max);

p_node createNodeAVL(int *values, int start, int end);

#endif //CC_NODE_H
