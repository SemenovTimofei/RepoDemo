#include <stdio.h>
#include <stdbool.h>

int iterativeExponentiation(int number, int power)
{
    if (power < 0)
    {
        return 0;
    }
    else if (power == 0)
    {
        return 1;
    }

    int result = number;
    while (power > 1)
    {
        result *= number;
        --power;
    }

    return result;
}

int binaryExponentiation(int number, int power)
{
    if (power < 0)
    {
        return 0;
    }
    if (power == 0)
    {
        return 1;
    }
    if (power % 2 == 0)
    {
        int result = binaryExponentiation(number, power / 2);
        return result * result;
    }
    else
    {
        return binaryExponentiation(number, power - 1) * number;
    }
}

bool testing()
{
    if (iterativeExponentiation(0, 1) != 0 || binaryExponentiation(0, 1) != 0)
    {
        return false;
    }
    if (iterativeExponentiation(0, 0) != 1 || binaryExponentiation(0, 0) != 1)
    {
        return false;
    }
    if (iterativeExponentiation(2, 3) != 8 || binaryExponentiation(2, 3) != 8)
    {
        return false;
    }
    if (iterativeExponentiation(15, 2) != 225 || binaryExponentiation(15, 2) != 225)
    {
        return false;
    }
    return true;
}

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    printf("Enter number: ");
    int number = 0;
    scanf_s("%d", &number);
    
    printf("Enter power: ");
    int power = 0;
    scanf_s("%d", &power);

    printf("%d to the power of %d is %d\n", number, power, binaryExponentiation(number, power));

    return 0;
}