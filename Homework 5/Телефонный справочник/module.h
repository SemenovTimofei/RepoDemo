#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#pragma once


typedef struct {
    char name[50];
    char phone[20];
} PhoneBookEntry;

void printOptions()
{
    printf("0 - выйти\n");
    printf("1 - добавить запись (имя и телефон)\n");
    printf("2 - распечатать все имеющиеся записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить текущие данные в файл\n");
}

void addEntry(PhoneBookEntry* entries, int* entryCount)
{
    if (*entryCount >= 100)
    {
        printf("База номеров полна\n");
        return;
    }

    PhoneBookEntry newEntry;
    
    printf("Введите имя: ");
    scanf_s("%s", newEntry.name, sizeof(newEntry.name));

    printf("Введите телефон: ");
    scanf_s("%s", newEntry.phone, sizeof(newEntry.phone));
    
    entries[*entryCount] = newEntry;
    (*entryCount)++;

    printf("Запись успешно добавлена.\n");
}

void printEntries(PhoneBookEntry* entries, int entryCount)
{
    if (entryCount == 0)
    {
        printf("База номеров пуста.\n");
        return;
    }
    
    printf("Список записей:\n");
    for (int i = 0; i < entryCount; i++)
    {
        printf("Имя: %s, Телефон: %s\n", entries[i].name, entries[i].phone);
    }
}

void findPhoneByName(PhoneBookEntry* entries, int entryCount)
{
    if (entryCount == 0)
    {
        printf("Телефонная книга\n");
        return;
    }

    char name[50];
    printf("Введите имя: ");
    scanf_s("%s", name);

    for (int i = 0; i < entryCount; ++i)
    {
        if (strcmp(entries[i].name, name) == 0)
        {
            printf("Телефон: %s\n", entries[i].phone);
            return;
        }
    }

    printf("Запись с указанным именем не найдена\n");
}

void findNameByPhone(PhoneBookEntry* entries, int entryCount) {
    if (entryCount == 0) {
        printf("База номеров пуста\n");
        return;
    }

    char phone[20];
    printf("Введите телефон: ");
    scanf_s("%s", phone);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].phone, phone) == 0) {
            printf("Имя: %s\n", entries[i].name);
            return;
        }
    }

    printf("Запись с указанным телефоном не найдена.\n");
}

void saveToFile(PhoneBookEntry* entries, int entryCount)
{
    FILE* file = fopen_s(&file, "phonebook.txt", "w");
    
    if (file == NULL)
    {
        printf("Ошибка чтения файла\n");
        return;
    }

    if (entryCount == 0)
    {
        printf("Файл пустой\n");
    }

    for (int i = 0; i < entryCount; ++i)
    {
        fprintf_s(file, "%s %s\n", entries[i].name, entries[i].phone);
    }

    fclose(file);

    printf("Имя и номер сохранены\n");
}