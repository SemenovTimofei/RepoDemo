#include <stdio.h>
#include <stdlib.h>
#include "module.h"

typedef struct
{
    int data;
    struct QueueElement* next;
} QueueElement;

typedef struct
{
    QueueElement* front;
    QueueElement* back;
} Queue;

void createQueue(Queue** queue)
{
    *queue = malloc(sizeof(Queue));
    if (queue == NULL)
    {
        printf("Ошибка при выделении памяти\n");
        return;
    }
    (*queue)->front = NULL;
    (*queue)->back = NULL;
}

int enqueue(Queue* queue, const int data)
{
    QueueElement* newElement = malloc(sizeof(QueueElement));
    if (newElement == NULL)
    {
        printf("Ошибка при выделении памяти\n");
        return;
    }
    newElement->data = data;
    newElement->next = NULL;
    if (queue->back == NULL)
    {
        queue->front = newElement;
        queue->back = newElement;
    }
    else
    {
        queue->back->next = newElement;
        queue->back = newElement;
    }
}

int dequeue(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Очередь пуста\n");
        return 404;
    }
    Queue* trash = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->back = NULL;
    }
    free(trash);
    return 0;
}

void printQueue(Queue* queue)
{
    QueueElement* current = queue->front;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int isEmpty(Queue* queue)
{
    return queue->front == NULL;
}

int front(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Очередь пуста\n");
        return;
    }
    return queue->front->data;
}

int back(Queue* queue)
{
    if (queue->front == NULL)
    {
        printf("Очередь пуста\n");
    }
    return queue->back->data;
}

void deleteQueue(Queue* queue)
{
    while (queue->front != NULL)
    {
        Queue* trash = queue->front;
        queue->front = queue->front->next;
        free(trash);
    }
}

int main()
{
    system("chcp 1251 > nul");
    Queue* queue;
    createQueue(&queue);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printQueue(queue);
    deleteQueue(queue);
    printQueue(queue);

    free(queue);
    return 0;
}