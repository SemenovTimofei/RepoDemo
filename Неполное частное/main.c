#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findIncompleteQuotient(int dividend, int divisor)
{
    if (divisor == 0)
    {
        // can't figure out what to output in this case
        return 0;
    }

    int sign = 1;
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
    {
        sign = -1; 
    }

    int quotient = 0;
    if (dividend < 0)
    {
        ++quotient;
    }

    dividend = abs(dividend);
    divisor = abs(divisor);

    while ((dividend - divisor) >= 0)
    {
        dividend -= divisor;
        quotient += 1;
    }

    return sign * quotient;
}

bool testing()
{
    if (findIncompleteQuotient(78, 33) != 2)
    {
        return false;
    }
    if (findIncompleteQuotient(-78, 33) != -3)
    {
        return false;
    }
    if (findIncompleteQuotient(-9, -13) != 1)
    {
        return false;
    }
    if (findIncompleteQuotient(9, 90) != 0)
    {
        return false;
    }
    if (findIncompleteQuotient(2, 0) != 0)
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

    printf("Enter dividend and divisor: ");
    int dividend = 0;
    int divisor = 0;
    scanf_s("%d %d", &dividend, &divisor);

    printf("The incomplete quotient: %d", findIncompleteQuotient(dividend, divisor));
    return 0;
}