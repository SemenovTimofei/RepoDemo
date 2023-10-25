#include <stdio.h>
#include <locale.h>

#include "stack.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    if (!testing())
    {
        printf("Ошибка при тестировании\n");
        return 1;
    }

    char text[100] = { 0 };
    printf("Введите операцию в постфикном виде\n");
    fgets(text, sizeof(text), stdin);

    int result = calculatePostfix(text);
    printf("Результат вычислений: %d\n", result);

    return 0;
}