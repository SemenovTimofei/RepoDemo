#pragma once

#include <stdbool.h>

// ��������� �����
typedef struct Stack Stack;

// ��������� �������� � ����
int push(Stack** head, const char value);

// ������� ������� �����
char pop(Stack** head);

// ������� ���� ����
void freeStack(Stack** head);

// ���������� ��������� �������� �����
char top(Stack* head);

// ���������� ������������� ������ ���� �� ����, ��� � ���������� ������������� ������
char findPair(char bracket);

// ���������� ������ ��� ���� � ����������� �� ������������ ��������� ������
bool bracketCheck(char* text);