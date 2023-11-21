#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "AVLTree.h"
#include "test.h"

int main()
{
    if (!testing())
    {
        printf("Testing failed\n");
        return 1;
    }

    bool finish = false;
    int command = 0;
    AVLTree* tree = createAVLTree();

    while (!finish)
    {
        printOptions();
        char key[EXPRESSION_SIZE] = "";
        if (scanf_s("%d", &command) != 1)
        {
            printf("Invalid input\n");
            break;
        }

        switch (command)
        {
            case 0:
            {
                deleteAVLTree(&tree);
                finish = true;
                break;
            }
            case 1:
            {
                printf("Enter key: ");
                if (scanf_s("%s", key, EXPRESSION_SIZE) != 1)
                {
                    printf("Invalid input\n");
                    break;
                }
                
                printf("Enter value: ");
                char value[EXPRESSION_SIZE];
                if (scanf_s("%s", value, EXPRESSION_SIZE) != 1)
                {
                    printf("Invalid input\n");
                    break;
                }
                addValue(tree, key, value);
                break;
            }
            case 2:
            {
                printf("Enter key: ");
                if (scanf_s("%s", key, EXPRESSION_SIZE) != 1)
                {
                    printf("Invalid input\n");
                    break;
                }

                char* value = getValue(tree, key);
                if (value != NULL)
                {
                    printf("The value is %s\n", value);
                }
                else
                {
                    printf("Value not found\n");
                }
                break;
            }
            case 3:
            {
                printf("Enter key: ");
                if (scanf_s("%s", key, EXPRESSION_SIZE) != 1)
                {
                    printf("Invalid input\n");
                    break;
                }
                if (isPresent(tree, key))
                {
                    printf("The key is present\n");
                }
                else
                {
                    printf("The key is not present\n");
                }
                break;
            }
            case 4:
            {
                printf("Enter key: ");
                if (scanf_s("%s", key, EXPRESSION_SIZE) != 1)
                {
                    printf("Invalid input\n");
                    break;
                }
                deleteValue(tree, key);
                break;
            }
            default:
            {
                printf("Invalid input\n");
                break;
            }
        }
    }

    deleteAVLTree(&tree);
    return 0;
}