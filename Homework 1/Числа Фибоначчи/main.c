#include <stdio.h>
#include <time.h>

int iterativeFibonacci(const int fibonacciPosition)
{

    int firstNumber = 0, secondNumber = 1, fibonacciNumber = 0;

    for (int i = 0; i < fibonacciPosition; i++)
    {
        if (i <= 1)
        {
            fibonacciNumber = i;
        }

        else
        {
            fibonacciNumber = firstNumber + secondNumber;
            firstNumber = secondNumber;
            secondNumber = fibonacciNumber;
        }
    }

    return fibonacciNumber;
}

int recursiveFibonacci(const int fibonacciPosition)
{
    if (fibonacciPosition == 1)
    {
        return 0;
    }

    if (fibonacciPosition == 2)
    {
        return 1;
    }

    return recursiveFibonacci(fibonacciPosition - 1) + recursiveFibonacci(fibonacciPosition - 2);
}

void main()
{
    for (int i = 1; i < 45; ++i)
    {
        time_t start = time(NULL);
        int result = iterativeFibonacci(i);
        int iterativeExecutionTime = (int)(time(NULL) - start);

        start = time(NULL);
        result = recursiveFibonacci(i);
        int recursiveExecutionTime = (int)(time(NULL) - start);

        printf("%d Fibonacci number is %d, iterative execution time: %d second(s), recursive execution time: %d second(s)\n", i, result, iterativeExecutionTime, recursiveExecutionTime);
    }
}