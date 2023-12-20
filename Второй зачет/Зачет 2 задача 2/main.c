#include <stdio.h>

#include "stack.h"

int main()
{
    Queue* queue = createQueue();
    push(&queue, 1);
    push(&queue, 2);
    push(&queue, 3);
    printQueue(queue);

    dequeue(&queue);
    printQueue(queue);

    return 0;
}