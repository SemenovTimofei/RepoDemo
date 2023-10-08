#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

char* binaryRepresentation(int n, int len)
{
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2)
    {
        binary[k++] = (n & i) ? '1' : '0';
    }

    binary[k] = '\0';

    return binary;
}

char binaryAddition(char binaryFirstNumber[], char binarySecondNumber[], int length)
{
    char* addition = (char*)malloc(sizeof(char) * length);
    memset(addition, 0, length * sizeof(char));
    
    for (int i = length - 1; i >= 0; --i)
    {
        addition[i] = (binaryFirstNumber[i] == binarySecondNumber[i]) ? "1" : "0";


        printf("%c", addition[i]);
    }
}

void main()
{
    setlocale(LC_ALL, "Rus");

    int firstNumber = 10;
    int secondNumber = 5;

    int length = 8;

    char* binaryFirstNumber = binaryRepresentation(firstNumber, length);
    printf("The binary representation of %d is %s\n", firstNumber, binaryFirstNumber);

    char* binarySecondNumber = binaryRepresentation(secondNumber, length);
    printf("The binary representation of %d is %s\n", secondNumber, binarySecondNumber);

    binaryAddition(binaryFirstNumber, binarySecondNumber, length);

    return;
}