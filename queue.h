//
// Created by moind on 21/11/2024.
//

#ifndef CC_QUEUE_H
#define CC_QUEUE_H

#include "list.h"
#include "node.h"

/**
 * @brief Structure for the queue of integers
 */
typedef struct s_queue
{
    int *values;
    int size;
    int last;
    int first;
} t_queue;

/**
 * @brief Function to create a queue
 * @param size : the size of the queue
 * @return the queue
 */
t_queue createQueue(int);

/**
 * @brief Function to enqueue a value in the queue
 * @param p_queue : pointer to the queue
 * @param value : the position to enqueue
 * @return none
 */
void enqueue(t_queue *,int );

/**
 * @brief Function to dequeue a value from the queue
 * @param p_queue : pointer to the queue
 * @return the value dequeued
 */
int dequeue(t_queue *);




// -----------------------------------------------------------------------------



typedef HTLIST QUEUELIST;

void displayQueueL(QUEUELIST);


// ------------------------------------------------------------------------------

#define MAX 2

typedef struct s_queue_tab {
    p_node values[MAX]; // Tableau de pointeurs de nœuds
    int first, last;
} t_queue_tab;

t_queue_tab createEmptyQueue();

int isQueueEmpty(t_queue_tab);
int isQueueFull(t_queue_tab);
void enqueueTab_Queue(t_queue_tab *, p_node);
p_node dequeueTab_Queue(t_queue_tab *);
void displayQueue_Tab_Queue(t_queue_tab);
void freeQueue(t_queue_tab *q);

#endif //CC_QUEUE_H
