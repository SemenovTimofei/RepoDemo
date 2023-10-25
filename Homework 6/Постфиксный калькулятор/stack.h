#pragma once

#include <stdbool.h>

// структура стэка
typedef struct Stack Stack;

// добавляет значение в стэк
int push(Stack** head, const int value);

// возвращает размер стэка
int stackSize(Stack* head);

// удаляет элемент стэка
int pop(Stack** head);

// удаляет весь стэк
void freeStack(Stack** head);

// возвращает последнее значение стэка
int top(Stack* head);

// возвращает результат постфиксного вычисления
int calculatePostfix(char* text);

// возвращает результат прохождения тестов
bool testing();