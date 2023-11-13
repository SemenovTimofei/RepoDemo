#include <stdio.h>
#include <stdlib.h>
#include <string.h> // clean up ???

#include "tree.h"
#include "test.h"

#define MAX_EXPRESSION_LENGTH 100 // clean up ???

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    Node* tree = NULL;

    printOptions();
    
    int option = -1;

    while (option != 0)
    {
        printf("Enter command: ");
        scanf_s("%d", &option);

        switch (option)
        {
        case 0:
        {
            deleteTree(tree);
            return 0;
        }
        case 1:
        {
            printf("Enter key: ");
            int key = 0;
            scanf_s("%d", &key);

            printf("Enter the expression: ");
            char text[MAX_EXPRESSION_LENGTH] = { 0 };
            scanf_s("%s", &text, MAX_EXPRESSION_LENGTH);
            size_t length = strlen(text) + 1;

            char* value = (char*)calloc(length, sizeof(char));
            strcpy_s(value, sizeof(char) * length, text);

            tree = push(tree, key, value);
            break;
        }
        case 2:
        {
            printf("Enter key: ");
            int key = 0;
            scanf_s("%d", &key);

            if (!isPresent(tree, key))
            {
                printf("There is no value at %d\n", key);
                break;
            }

            printf("The value at %d is %s\n", key, search(tree, key));
            break;
        }
        case 3:
        {
            printf("Enter key: ");
            int key = 0;
            scanf_s("%d", &key);

            if (isPresent(tree, key))
            {
                printf("Key %d is present within the tree\n", key);
                break;
            }
            printf("Key %d is not present within the tree\n", key);
            break;
        }
        case 4:
        {
            printf("Enter key: ");
            int key = 0;
            scanf_s("%d", &key);

            deleteNode(tree, key);
            break;
        }
        default:
        {
            printf("Invalid command");
            return 1;
        }
        }
    }
}