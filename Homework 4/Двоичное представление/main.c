#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>

char* binaryRepresentation(int number, int length)
{
    char* binary = (char*)calloc(length, length * sizeof(char));
    int k = 0;
    for (int i = 1 << length - 1; i > 0; i = i / 2)
    {
        binary[k++] = (number & i) ? '1' : '0';
    }

    binary[k] = '\0';

    return binary;
}

char* binaryAddition(char firstNumber[], char secondNumber[], int length)
{
    char* addition = (char*)calloc(length, length * sizeof(char));
    bool carryover = false;

    for (int i = length - 1; i >= 0; --i)
    {
        // случай, когда есть остаток от суммы предыдущих цифр
        if (carryover)
        {
            if ((firstNumber[i] == '1') && (secondNumber[i] == '1'))
            {
                addition[i] = '1';
                carryover = true;
            }
            else if (((firstNumber[i] == '0') && (secondNumber[i] == '1')) || ((firstNumber[i] == '1') && (secondNumber[i] == '0')))
            {
                addition[i] = '0';
                carryover = true;
            }
            else if ((firstNumber[i] == '0') && (secondNumber[i] == '0'))
            {
                addition[i] = '1';
                carryover = false;
            }
        }

        // случай, когда нет остатка от суммы предыдущих цифр
        else
        {
            if ((firstNumber[i] == '1') && (secondNumber[i] == '1'))
            {
                addition[i] = '0';
                carryover = true;
            }
            else if (((firstNumber[i] == '0') && (secondNumber[i] == '1')) || ((firstNumber[i] == '1') && (secondNumber[i] == '0')))
            {
                addition[i] = '1';
                carryover = false;
            }
            else if ((firstNumber[i] == '0') && (secondNumber[i] == '0'))
            {
                addition[i] = '0';
                carryover = false;
            }
        }
    }

    return addition;
}

int binaryToDecimal(char binary[], int length)
{
    int decimal = 0;
    int binaryNumber = 1;

    for (int i = length - 1; i >= 0; --i)
    {
        if (binary[i] == '1')
        {
            decimal += binaryNumber;
        }

        binaryNumber *= 2;
    }

    return decimal;
}

bool testing()
{
    srand(time(NULL));

    int length = 9;

    for (int i = 0; i < 100; ++i)
    {
        int firstNumber = rand() % 256;
        int secondNumber = rand() % 256;

        char* binaryFirstNumber = binaryRepresentation(firstNumber, length);
        char* binarySecondNumber = binaryRepresentation(secondNumber, length);
        char* sum = binaryAddition(binaryFirstNumber, binarySecondNumber, length);
        int decimalSum = binaryToDecimal(sum, length);

        if (!(firstNumber + secondNumber == decimalSum))
        {
            return false;
        }
    }

    return true;
}

void main()
{
    if (!testing())
    {
        printf("Test failed\n");
        return;
    }

    setlocale(LC_ALL, "Rus");

    printf("Введите первое число\n");
    int firstNumber = 0;
    scanf_s("%d", &firstNumber);

    // поддерживает числа от -65536 до 65536 включительно (2^16)
    if (firstNumber < -65535 || firstNumber > 65535)
    {
        printf("Числа меньше -65535 или больше 65535 не поддерживаются\n");
        return;
    }
    
    printf("Введите второе число\n");
    int secondNumber = 0;
    scanf_s("%d", &secondNumber);

    if (secondNumber < -65535 || secondNumber > 65535)
    {
        printf("Числа меньше -65535 или больше 65535 не поддерживаются\n");
        return;
    }

    int length = 17;

    char* binaryFirstNumber = binaryRepresentation(firstNumber, length);
    printf("Число %d в двоичном представлении это %s\n", firstNumber, binaryFirstNumber);

    char* binarySecondNumber = binaryRepresentation(secondNumber, length);
    printf("Число %d в двоичном представлении это %s\n", secondNumber, binarySecondNumber);

    char* sum = binaryAddition(binaryFirstNumber, binarySecondNumber, length);
    printf("Двоичная сумма чисел равна %s\n", sum);

    int decimalSum = binaryToDecimal(sum, length);
    printf("Сумма в десятеричном представлении это %d", decimalSum);

    return;
}