//
// Created by moind on 21/11/2024.
//

#ifndef CC_QUEUE_H
#define CC_QUEUE_H

#include "list.h"

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
void enqueue(t_queue *,t_position);

/**
 * @brief Function to dequeue a value from the queue
 * @param p_queue : pointer to the queue
 * @return the value dequeued
 */
t_position dequeue(t_queue *);




// -----------------------------------------------------------------------------



typedef HTLIST QUEUELIST;

void displayQueue(QUEUELIST);

#endif //CC_QUEUE_H
