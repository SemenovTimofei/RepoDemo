#include "test.h"

bool testing()
{
    int firstNumber = 1234;
    bool firstBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(firstNumber, firstBinary);
    bool check[] = { 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0 };

    for (size_t i = 0; i < 11; ++i)
    {
        if (firstBinary[i] != check[10 - i])
        {
            return false;
        }
    }

    int secondNumber = 0;
    bool secondBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(secondNumber, secondBinary);
    if (secondBinary[0] != 0)
    {
        return false;
    }

    bool sum[MAX_INT_BIT_SIZE] = { false };
    binarySum(firstBinary, secondBinary, sum);

    if (binaryToDecimal(sum) != 1234)
    {
        return false;
    }

    int thirdNumber = 9999999;
    bool thirdBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(thirdNumber, thirdBinary);

    int fourthNumber = 9999999;
    bool fourthBinary[MAX_INT_BIT_SIZE] = { false };
    decimalToBinary(fourthNumber, fourthBinary);

    bool newSum[MAX_INT_BIT_SIZE] = { false };
    binarySum(thirdBinary, fourthBinary, newSum);

    if (binaryToDecimal(newSum) != 19999998)
    {
        return false;
    }

    return true;
}