#pragma once

typedef enum ErrorCode
{
	ok,
	stackIsEmpty,
	outOfMemory,
} ErrorCode;

typedef struct Stack Stack;

ErrorCode push(Stack** head, const int value);

ErrorCode pop(Stack** head);

void freeStack(Stack** head);

int top(Stack* head, ErrorCode* errorCode);