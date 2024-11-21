//
// Created by moind on 21/11/2024.
//

#include "queue.h"
#include <assert.h>
#include <stdlib.h>

/**
 * @brief Function to create a queue
 * @param size : the size of the queue
 * @return the queue
 */
t_queue createQueue(int size)
{
    // the size of the queue must be positive
    assert(size > 0);
    t_queue queue;
    queue.size = size;
    queue.first = 0;
    queue.last = 0;
    queue.values = (int *)malloc(size * sizeof(int));
    return queue;
}

void enqueue(t_queue *p_queue, int val)
{
    // the queue must not be full
    assert((p_queue->last - p_queue->first) < p_queue->size);
    p_queue->values[(p_queue->last) % p_queue->size] = val;
    p_queue->last++;
    return;
}

int dequeue(t_queue *p_queue)
{
    // the queue must not be empty
    assert(p_queue->last != p_queue->first);
    p_queue->first++;
    return p_queue->values[(p_queue->first - 1) % p_queue->size];
}




// ----------------------------------------------------------------------------------------




void displayQueueL(QUEUELIST q)
{
    printf("out ");
    if (q.head != NULL) {
        p_cell temp = q.head;
        while (temp != NULL) {
            printf("<- %d ", temp->value);
            temp = temp->next;
        }
    }
    printf("<- in\n");
}