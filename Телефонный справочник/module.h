#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define MAX_ENTRY_COUNT 100
#define MAX_NAME_SIZE 50
#define MAX_PHONE_SIZE 20

typedef struct {
    char name[MAX_NAME_SIZE];
    char phone[MAX_PHONE_SIZE];
} Phonebook;

void printOptions()
{
    printf("0 - выйти\n");
    printf("1 - записать имя и телефон\n");
    printf("2 - вывести все записи\n");
    printf("3 - найти телефон по имени\n");
    printf("4 - найти имя по телефону\n");
    printf("5 - сохранить все записи в файл\n");
}

int addEntry(Phonebook* entries, Phonebook newEntry, int* entryCount)
{
    if (*entryCount >= MAX_ENTRY_COUNT)
    {
        return -1;
    }
    entries[*entryCount] = newEntry;
    (*entryCount)++;
    return 0;
}

void printEntries(Phonebook* entries, int entryCount)
{
    if (entryCount == 0)
    {
        printf("\nТелефонная книга пуста\n");
        return;
    }
    
    printf("\nСписок записей:\n\n");
    for (int i = 0; i < entryCount; i++)
    {
        printf("Имя: %s, Телефон: %s\n", entries[i].name, entries[i].phone);
    }
}
int findPhoneByName(Phonebook* entries, int entryCount, char* name, char* phone)
{
    if (entryCount == 0)
    {
        return 1;
    }

    for (int i = 0; i < entryCount; ++i)
    {
        if (strcmp(entries[i].name, name) == 0)
        {
            memcpy(phone, entries[i].phone, MAX_PHONE_SIZE);
            return 0;
        }
    }
    phone = NULL;
    return 1;
}

int findNameByPhone(Phonebook* entries, int entryCount, char* name, char* phone)
{
    if (entryCount == 0)
    {
        return 1;
    }

    for (int i = 0; i < entryCount; i++)
    {
        if (strcmp(entries[i].phone, phone) == 0)
        {
            memcpy(name, entries[i].name, MAX_NAME_SIZE);
            return 0;
        }
    }
    name = NULL;
    return 1;
}

int saveToFile(FILE* file, Phonebook* entries, int entryCount, int newEntries)
{
    if (file == NULL)
    {
        file = fopen_s(&file, "phonebook.txt", "a");
        return 1;
    }

    if (entryCount == 0)
    {
        return 1;
    }

    for (int i = 0; i < entryCount; ++i)
    {
        fprintf_s(file, "%s %s\n", entries[i].name, entries[i].phone);
    }

    fclose(file);

    printf("Имя и номер сохранены\n");
}

bool testCapacity()
{
    int entryCount = 100;

    Phonebook testCapacity[MAX_ENTRY_COUNT] = { 0 };
    Phonebook newEntry;
    char name[] = "egor";
    char phone[] = "33";
    strcpy_s(newEntry.name, sizeof(newEntry.name), name);
    strcpy_s(newEntry.phone, sizeof(newEntry.phone), phone);

    if (addEntry(testCapacity, newEntry, &entryCount) != -1)
    {
        return false;
    }

    return true;
}

bool testAddEntry()
{
    int entryCount = 0;
    Phonebook testAddEntry[MAX_ENTRY_COUNT] = { 0 };
    Phonebook newEntry = { "asd", "123" };

    return addEntry(testAddEntry, newEntry, &entryCount) == 0;
}