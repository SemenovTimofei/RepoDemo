#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack Stack;

typedef struct Queue Queue;

Stack* createStack();

Queue* createQueue();

int push(Queue** queue, int value);

int pop(Stack** head);

void printStack(Stack* head);