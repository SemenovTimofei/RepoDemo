#include <stdio.h>

#include "list.h"
#include "mergeSort.h"
#include "testing.h"

int main(void)
{
    const TestErrorCode testErrorCode = testing();

    switch (testErrorCode)
    {
        case testErrorOpenningFile:
        {
            printf("Error openning file during testing\n");
            return 1;
        }
        case testErrorCode1:
        {
            printf("Error sorting empty file during testing\n");
            return 1;
        }
        case testErrorCode2:
        {
            printf("Error sorting by phone number during testing\n");
            return 1;
        }
        case testErrorCode3:
        {
            printf("Error sorting by name during testing\n");
            return 1;
        }
    }
    
    Node* list = NULL;

    ListErrorCode openFileError = loadData(&list, "text.txt");
    if (openFileError)
    {
        printf("Error openning file\n");
        return errorOpenningFile;
    }

    printf("Initial phonebook layout:\n");
    printList(list);
    printf("\n");

    printf("Press 0 to sort by phone number\nPress 1 to sort by name\nUser input: ");

    int option = -1;
    scanf_s("%d", &option);
    if (!(option == 0 || option == 1))
    {
        printf("Invalid input\n");
        return inputError;
    }

    mergeSort(&list, option);

    printf("\nPhonebook has been sorted by ");
    printf(option == 1 ? "name:\n" : "phone number:\n");
    printList(list);

    freeList(&list);
    return 0;
}