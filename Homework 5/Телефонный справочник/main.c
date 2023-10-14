#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module.h"


int main()
{
    setlocale(LC_ALL, "Rus");

    PhoneBookEntry entries[100];
    int entryCount = 0;

    FILE* file = fopen_s(&file, "phonebook.txt", "r");

    if (file != NULL)
    {
        while (fscanf_s(file, "%s %s", entries[entryCount].name, entries[entryCount].phone) == 2)
        {
            ++entryCount;
            if (entryCount >= 100)
            {
                break;
            }
        }

        fclose(file);
    }

    int option = 0;
    do 
    {
        printOptions();
        printf("Введите номер операции: ");

        char characterCheck = '\0';
        scanf_s("%d%c", &option, &characterCheck);

        if (characterCheck != '\n')
        {
            printf("Программа принимает только числа\n");
            continue;
        }

        switch (option)
        {
        case 0:
            printf("Программа завершена\n");
            break;
        case 1:
            addEntry(entries, &entryCount);
            break;
        case 2:
            printEntries(entries, entryCount);
            break;
        case 3:
            findPhoneByName(entries, entryCount);
            break;
        case 4:
            findNameByPhone(entries, entryCount);
            break;
        case 5:
            saveToFile(entries, entryCount);
            break;
        default:
            printf("Неверный номер операции.\n");
            break;
        }
    } while (option != 0);


    return 0;
}