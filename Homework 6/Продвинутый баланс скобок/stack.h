#pragma once

#include <stdbool.h>

// структура стека
typedef struct Stack Stack;

// добавл€ет значение в стек
int push(Stack** head, const char value);

// удал€ет элемент стека
char pop(Stack** head);

// удал€ет весь стек
void freeStack(Stack** head);

// возвращает последнее значение стека
char top(Stack* head);

// возвращает закрывающуюс€ скобку того же вида, что и полученна€ открывающа€с€ скобка
char findPair(char bracket);

// возвращает истину или ложь в зависимости от корректности написани€ скобок
bool bracketCheck(char* text);