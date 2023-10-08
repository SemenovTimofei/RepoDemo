#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

char* binaryRepresentation(int number, int length)
{
    char* binary = (char*)malloc(sizeof(char) * length);
    int k = 0;
    for (unsigned i = (1 << length - 1); i > 0; i = i / 2)
    {
        binary[k++] = (number & i) ? '1' : '0';
    }

    binary[k] = '\0';

    return binary;
}

char* binaryAddition(char number1[], char number2[], int length)
{
    char* addition = (char*)calloc(length, length * sizeof(char));
    bool carryover = false;

    for (int i = length - 1; i >= 0; --i)
    {
        if ((number1[i] == '1') && (number2[i] == '1'))
        {
            carryover = true;
            addition[i] = '0';
        }
        else if (((number1[i] == '0') && (number2[i] == '1') && carryover) || ((number1[i] == '1') && (number2[i] == '0') && carryover))
        {
            carryover = true;
            addition[i] = '0';
        }
        else if (((number1[i] == '0') && (number2[i] == '1') && !carryover) || ((number1[i] == '1') && (number2[i] == '0') && !carryover))
        {
            addition[i] = '1';
        }
        else if ((number1[i] == '0') && (number2[i] == '0') && carryover)
        {
            addition[i] = '1';
            carryover = false;
        }
        else if ((number1[i] == '0') && (number2[i] == '0') && !carryover)
        {
            addition[i] = '0';
            carryover = false;
        }

        printf("%c %c %c\n", number1[i], number2[i], addition[i]);
    }
}

void main()
{
    setlocale(LC_ALL, "Rus");

    int firstNumber = 10;
    int secondNumber = -10;

    int length = 8;

    char* binaryFirstNumber = binaryRepresentation(firstNumber, length);
    printf("The binary representation of %d is %s\n", firstNumber, binaryFirstNumber);

    char* binarySecondNumber = binaryRepresentation(secondNumber, length);
    printf("The binary representation of %d is %s\n", secondNumber, binarySecondNumber);

    char* addition = binaryAddition(binaryFirstNumber, binarySecondNumber, length);

    return;
}