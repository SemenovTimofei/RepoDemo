#include <stdio.h>
#include <locale.h>

#include "binary.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    printf("������� ������ �����\n");
    int firstNumber = 0;
    scanf_s("%d", &firstNumber);
    bool firstBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(firstNumber, firstBinary);

    printf("������� ������ �����\n");
    int secondNumber = 0;
    scanf_s("%d", &secondNumber);
    bool secondBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(secondNumber, secondBinary);
    
    printf("�������� ������������� ������� �����: ");
    printBinary(firstBinary);
    printf("�������� ������������� ������� �����: ");
    printBinary(secondBinary);




    bool sum[MAX_INT_BIT_SIZE] = { false };
    binarySum(firstBinary, secondBinary, sum);
    printBinary(binarySum);

    return 0;
}