#pragma once

#include <stdbool.h>

// stack structure
typedef struct Stack Stack;

// adds value to a stack
int push(Stack** head, const char value);

// deletes last stack element
int pop(Stack** head);

// frees the stack
void freeStack(Stack** head);

// returns the last stack value
char top(Stack* head);

// returns open bracket of the same type
char findPair(char bracket);

// returns true or false value depeding on bracket placement correctness
bool bracketCheck(char* text);

// testing bracket balance algorithm
bool testing();