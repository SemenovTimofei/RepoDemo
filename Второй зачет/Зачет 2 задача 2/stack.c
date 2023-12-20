#include "stack.h"

typedef struct Stack
{
    int value;
    Stack* next;
} Stack;

typedef struct Queue
{
    Stack* first;
    Stack* second;
} Queue;

Stack* createStack()
{
    return (Stack*)calloc(1, sizeof(Stack));
}

Queue* createQueue()
{
    Queue* newQueue = (Queue*)calloc(1, sizeof(Queue));
    newQueue->first = createStack();
    newQueue->second = createStack();
    return newQueue;
}

int push(Queue** queue, int value)
{
    Stack* next = createStack();
    if (next == NULL)
    {
        return 1;
    }

    next->value = value;
    next->next = (*queue)->first;
    (*queue)->first = next;
    printf("testing %d\n", (*queue)->first->value);
    return 0;
}

int pop(Stack** head)
{
    if ((*head) == NULL)
    {
        return 1;
    }

    Stack* trash = *head;
    *head = (*head)->next;
    // char value = trash->value;

    free(trash);
    return 0;
}

int top(Stack* head)
{
    return head->value;
}

void printQueue(Queue* queue)
{
    Stack* current = queue->first;
    while (current->next != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int dequeue(Queue** queue)
{
    if ((*queue)->second = NULL)
    {
        printf("empty\n");
        (*queue)->second = (*queue)->first;
    }
    //printf("check %d value\n", (*queue)->second->value);
    return pop(&((*queue)->second));
}