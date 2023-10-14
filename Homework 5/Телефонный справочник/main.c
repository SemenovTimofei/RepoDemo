#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module.h"

int main()
{
    setlocale(LC_ALL, "Rus");

    FILE* file = fopen_s(&file, "database.txt", "r+");
    if (file == NULL)
    {
        file = fopen_s(&file, "database.txt", "a+");
    }

    int entryCount = 0;
    Phonebook entries[MAX_ENTRY_COUNT] = { 0 };

    read(file, entries, &entryCount);

    int newEntries = 0;

    if (!testAddEntry() || !testCapacity())
    {
        printf("Тесты не пройдены\n");
        return 1;
    }

    printOptions();
    int option = -1;
    while (option != 0)
    {
        printf("\nВыберите опцию: ");
        
        char characterCheck = "";
        scanf_s("%d%c", &option, &characterCheck);

        if (characterCheck != '\n')
        {
            printf("Программа принимает только цифры\n");
            return 1;
        }

        switch (option)
        {
        case 0:
        {
            break;
        }
        case 1:
        {
            printf("\nВведите имя: ");

            Phonebook newEntry;
            char name[MAX_NAME_SIZE] = { 0 };

            if (fgets(name, MAX_NAME_SIZE, stdin) == NULL)
            {
                return -1;
            }

            name[strcspn(name, "\n")] = '\0';


            strcpy_s(newEntry.name, sizeof(newEntry.name), name);
            printf("\nВведите номер телефона: ");
            if (scanf_s("%s", newEntry.phone, 12) == NULL)
            {
                return -1;
            }
            if (addEntry(entries, newEntry, &entryCount) == -1)
            {
                printf("\nКоличество записей превышено\n");
                break;
            }
            ++newEntries;
            break;
        }
        case 2:
        {
            printEntries(entries, entryCount);
            break;
        }
        case 3:
        {
            if (entryCount == 0)
            {
                printf("\nТелефонная книга пуста\n");
                break;
            }

            printf("\nВведите имя: ");
            char name[MAX_NAME_SIZE] = { 0 };
            if (scanf_s("%s", name, MAX_NAME_SIZE) == NULL)
            {
                break;
            }
            char phone[MAX_PHONE_SIZE] = { 0 };
            if (findPhoneByName(entries, entryCount, name, phone) == 0)
            {
                printf("\nНомер телефона: %s", phone);
                break;
            }
            printf("\nДанные не найдены\n");
            break;
        }
        case 4:
        {
            if (entryCount == 0)
            {
                printf("\nТелефонная книга пуста\n");
                break;
            }

            printf("\nВведите номер телефона: ");
            char phone[MAX_PHONE_SIZE] = { 0 };
            if (scanf_s("%s", phone, MAX_PHONE_SIZE) == NULL)
            {
                break;
            }
            char name[MAX_NAME_SIZE] = { 0 };
            if (findPhoneByName(entries, entryCount, name, phone) == 0)
            {
                printf("\nИмя: %s", name);
                break;
            }
            printf("\nДанные не найдены\n");
            break;
        }
        case 5:
        {
            saveToFile(file, entries, entryCount, newEntries);
            break;
        }
        default:
        {
            printf("Неправильная опция\n");
            break;
        }
        }
    }

    fclose(file);
    return 0;
}