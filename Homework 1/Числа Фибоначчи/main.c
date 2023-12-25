#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_NUMBER 20

size_t recursiveFibonacci(const size_t fibonacciNumber)
{
    if (fibonacciNumber <= 1)
    {
        return 0;
    }
    else if (fibonacciNumber <= 3)
    {
        return 1;
    }

    return recursiveFibonacci(fibonacciNumber - 1) + recursiveFibonacci(fibonacciNumber - 2);
}

size_t iterativeFibonacci(const size_t number)
{
    if (number <= 1)
    {
        return 0;
    }
    else if (number == 2)
    {
        return 1;
    }

    size_t fibonacciNumbers[3] = { 0, 1, 1 };
    size_t count = 0;
    for (int i = 3; i <= number; ++i)
    {
        fibonacciNumbers[2] = fibonacciNumbers[0] + fibonacciNumbers[1];
        fibonacciNumbers[0] = fibonacciNumbers[1];
        fibonacciNumbers[1] = fibonacciNumbers[2];
    }
    return fibonacciNumbers[2];
}

bool testing()
{
    size_t fibonacciArray[MAX_NUMBER] = { 0, 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584 };
    for (size_t i = 1; i < MAX_NUMBER; ++i)
    {
        if (iterativeFibonacci(i) != fibonacciArray[i] || recursiveFibonacci(i) != fibonacciArray[i])
        {
            printf("%zd %zd %zd\n", i, iterativeFibonacci(i), fibonacciArray[i]);
            return false;
        }
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

    printf("Enter number of the Fibonacci number series: ");
    size_t number = 0;
    scanf_s("%zd", &number);

    printf("Recursive calculation: %zd\nIterative calculation: %zd\n", recursiveFibonacci(number), iterativeFibonacci(number));
    
    size_t i = 0;
    clock_t recursiveTime = 0;
    clock_t iterativeTime = 0;
    while (recursiveTime <= iterativeTime) // doesn't stop
    {
        clock_t start = clock();
        recursiveFibonacci(i);
        clock_t stop = clock();
        clock_t recursiveTime = stop - start;

        start = clock();
        iterativeFibonacci(i);
        stop = clock();
        clock_t iterativeTime = stop - start;

        if (recursiveTime > iterativeTime)
        {
            break;
        }

        ++i;
    }
    printf("The iterative calculation is faster than recursive at number %zd of the Fibonacci series\n", i);
    return 0;
}