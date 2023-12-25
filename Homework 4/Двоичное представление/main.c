#include <stdio.h>
#include <locale.h>

#include "binary.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    printf("Введите первое число\n");
    int firstNumber = 0;
    scanf_s("%d", &firstNumber);
    bool firstBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(firstNumber, firstBinary);

    printf("Введите второе число\n");
    int secondNumber = 0;
    scanf_s("%d", &secondNumber);
    bool secondBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(secondNumber, secondBinary);
    
    printf("Двоичное представление первого числа: ");
    printBinary(firstBinary);
    printf("Двоичное представление второго числа: ");
    printBinary(secondBinary);




    bool sum[MAX_INT_BIT_SIZE] = { false };
    binarySum(firstBinary, secondBinary, sum);
    printBinary(binarySum);

    return 0;
}