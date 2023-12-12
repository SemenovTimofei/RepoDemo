#include "search.h"

#define MODULUS 101
#define ALPHABET_SIZE 256

size_t find(char string[], char pattern[])
{
    size_t patternLength = strlen(pattern);
    size_t stringLength = strlen(string);
    int patternHash = 0;
    int currentHash = 0;
    int hashValue = 1;

    for (size_t i = 0; i < patternLength - 1; ++i)
    {
        hashValue = (hashValue * ALPHABET_SIZE) % MODULUS;
    }

    for (size_t i = 0; i < patternLength; ++i)
    {
        patternHash = (ALPHABET_SIZE * patternHash + pattern[i]) % MODULUS;
        currentHash = (ALPHABET_SIZE * currentHash + string[i]) % MODULUS;
    }

    for (size_t i = 0; i <= stringLength - patternLength; i++)
    {
        if (patternHash == currentHash)
        {
            for (size_t j = 0; j < patternLength; j++)
            {
                if (string[i + j] != pattern[j])
                {
                    break;
                }
            }
            return i;
        }

        if (i < stringLength - patternLength)
        {
            currentHash = ((currentHash - string[i] * hashValue) * ALPHABET_SIZE + string[i + patternLength]) % MODULUS;
            if (currentHash < 0)
            {
                currentHash = (currentHash + MODULUS);
            }
        }
    }

    return 0;
}