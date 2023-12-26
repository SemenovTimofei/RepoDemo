#include <stdio.h>

#include "list.h"

int main()
{

    Node* head = NULL;

    printf("0 - exit\n1 - add value to the list\n2 - delete value from list\n3 - print list\n");
    int command = -1;
    while (command != 0)
    {
        printf("Enter command: ");
        scanf_s("%d", &command);

        switch (command)
        {
        case 0:
        {
            freeList(head);
            return 0;
        }
        case 1:
        {
            printf("Enter key: ");
            int key = 0;
            scanf_s("%d", &key);

            printf("Enter value: ");
            char value[100] = { '\0' };
            scanf_s("%s", &value);

            head = push(head, key, value);
            break;
        }
        case 2:
        {
            printf("Enter key of an element to delete: ");
            int key = 0;
            scanf_s("%d", &key);

            deleteByKey(head, key);
            break;
        }
        case 3:
        {
            if (isEmpty(head))
            {
                printf("The list is empty\n");
                break;
            }
            printList(head);
            break;
        }
        default:
        {
            printf("Incorrect command\n");

            freeList(head);
            return 1;
        }
        }
    }
}