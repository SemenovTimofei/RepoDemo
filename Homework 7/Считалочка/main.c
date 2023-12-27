#include "counting.h"
#include "test.h"

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    printf("Enter how many soldiers there are: ");

    size_t number = 0;
    scanf_s("%zd", &number);
    if (number <= 0)
    {
        printf("There must be at least one soldier\n");
        return 1;
    }

    printf("Enter which soldier will be killed next: ");

    size_t step = 0;
    scanf_s("%zd", &step);
    if (step <= 0)
    {
        printf("Invalid step\n");
        return 1;
    }

    printf("The surviving soldier is number %zd\n", findSurvivor(number, step));
    return 0;
}