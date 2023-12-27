#pragma once

#include <stdlib.h>
#include <stdbool.h>

// структура стека
typedef struct Stack Stack;

// добавляет значение в стек
int push(Stack** head, const int value);

// удаляет элемент стека
int pop(Stack** head);

// удаляет весь стек
void freeStack(Stack** head);

// возвращает последнее значение стека
int top(Stack* head);

// возвращает результат постфиксного вычисления
int calculatePostfix(char* text);

// возвращает является ли узел последним или нет
bool isEnd(Stack* head);