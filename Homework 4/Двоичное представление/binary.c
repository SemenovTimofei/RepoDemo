#include "binary.h"

void decimalToBinary(int number, bool binary[])
{
    int index = 0;
    while (number > 0)
    {
        binary[index++] = number % 2;
        number /= 2;
    }
}

void printBinary(bool binary[])
{
    int index = MAX_INT_BIT_SIZE - 1;
    while (index > 0 && !binary[index])
    {
        --index;
    }
    while (index >= 0)
    {
        printf("%d", binary[index]);
        --index;
    }
    printf("\n");
}

void binarySum(bool first[], bool second[], bool result[])
{
    bool carryover = false;
    for (int i = 0; i < MAX_INT_BIT_SIZE; i++)
    {
        result[i] = first[i] ^ second[i] ^ carryover;
        carryover = (first[i] & second[i]) | (carryover & (first[i] ^ second[i]));
    }
}

int binaryToDecimal(bool array[])
{
    int result = 0;
    int multiplier = 1;

    for (size_t i = 0; i < MAX_INT_BIT_SIZE; ++i)
    {
        result += array[i] ? multiplier : 0;
        multiplier *= 2;
    }
    return result;
}