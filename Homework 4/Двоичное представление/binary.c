#include "binary.h"

size_t binaryLength(int number) // delete later ???
{
    size_t length = 1;
    number = abs(number);
    while (number > 1)
    {
        number = number >> 1;
        ++length;
    }
    return length;
}

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
    while (index >= 0 && !binary[index])
    {
        index--;
    }
    for (; index >= 0; index--)
    {
        printf("%d", binary[index]);
    }
    printf("\n");
}

void binarySum(bool first[], bool second[], bool result[])
{
    bool carry = false;
    for (int i = 0; i < MAX_INT_BIT_SIZE; i++)
    {
        result[i] = first[i] ^ second[i] ^ carry;
        carry = (first[i] & second[i]) | (carry & (first[i] ^ second[i]));
    }
}

