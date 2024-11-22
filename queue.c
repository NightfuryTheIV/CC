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


// ----------------------------------------------------------------------------------------------------


t_queue_tab createEmptyQueue() {
    t_queue_tab q = {{0}, 0, -1};
    return q;
}

int isQueueEmpty(t_queue_tab q) {
    return q.first > q.last;
}

int isQueueFull(t_queue_tab q) {
    return q.last == MAX - 1;
}

void enqueueTab_Queue(t_queue_tab *q, p_node value) {
    if (isQueueFull(*q)) {
        printf("Queue is full\n");
        return;
    }
    q->last++;
    q->values[q->last] = value;
}

p_node dequeueTab_Queue(t_queue_tab *q) {
    if (isQueueEmpty(*q)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return q->values[q->first++];
}

void displayQueueTab_Queue(t_queue_tab q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents:\n");
    for (int i = q.first; i <= q.last; i++) {
        printf("Value: %d\n", q.values[i]->value); // Affichage des valeurs de chaque nœud
    }
}

void freeQueue(t_queue_tab *q) {
    while (!isQueueEmpty(*q)) {
        p_node node = dequeueTab_Queue(q);
        if (node != NULL) {
            free(node); // Libère la mémoire du nœud
        }
    }
    q->first = 0;
    q->last = -1;
}