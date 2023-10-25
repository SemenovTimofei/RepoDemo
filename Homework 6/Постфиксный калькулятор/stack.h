#pragma once

#include <stdbool.h>

// ��������� �����
typedef struct Stack Stack;

// ��������� �������� � ����
int push(Stack** head, const int value);

// ������� ������� �����
int pop(Stack** head);

// ������� ���� ����
void freeStack(Stack** head);

// ���������� ��������� �������� �����
int top(Stack* head);

// ���������� ��������� ������������ ����������
int calculatePostfix(char* text);

// ���������� ��������� ����������� ������
bool testing();