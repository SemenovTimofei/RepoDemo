#pragma once

#include <stdbool.h>

// stack structure
typedef struct Stack Stack;

// initialize stack
Stack* initializeStack();

// adds an element to stack
int push(Stack** head, const int value);

// returns number of element in a stack
int stackSize(Stack* head);

// deletes the top element of a stack
char pop(Stack** head);

// deletes whole stack
void freeStack(Stack** head);

// returns the top element of a stack
char top(Stack* head);

// returns the priority value of a given math operation
int priority(char operation);

// changes given expression from infix to postfix
char* infixToPostfix(char* text);

// testing module for infixToPostfix
bool testing();