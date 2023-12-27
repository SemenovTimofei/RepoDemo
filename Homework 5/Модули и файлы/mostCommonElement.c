#include "mostCommonElement.h"

int findMostCommonElement(int array[], size_t length)
{
    quickSort(array, 0, length - 1);

    int mostCommonElement = 0;
    size_t maxFrequency = 0;
    size_t currentFrequency = 1;
    
    for (size_t i = 0; i < length - 1; ++i)
    {
        if (array[i] == array[i + 1])
        {
            ++currentFrequency;
            if (currentFrequency > maxFrequency)
            {
                maxFrequency = currentFrequency;
                mostCommonElement = array[i];
            }
        }
        else
        {
            currentFrequency = 1;
        }
    }
    return mostCommonElement;
}