#include <stdio.h>
#include <locale.h>

#include "stack.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    if (!testing())
    {
        printf("������ ��� ������������\n");
        return 1;
    }

    char text[100] = { 0 };
    printf("������� �������� � ���������� ����\n");
    fgets(text, sizeof(text), stdin);

    int result = calculatePostfix(text);
    printf("��������� ����������: %d\n", result);

    return 0;
}