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
    printf("0 - �����\n");
    printf("1 - �������� ������ (��� � �������)\n");
    printf("2 - ����������� ��� ��������� ������\n");
    printf("3 - ����� ������� �� �����\n");
    printf("4 - ����� ��� �� ��������\n");
    printf("5 - ��������� ������� ������ � ����\n");
}

void addEntry(PhoneBookEntry* entries, int* entryCount)
{
    if (*entryCount >= 100)
    {
        printf("���� ������� �����\n");
        return;
    }

    PhoneBookEntry newEntry;
    
    printf("������� ���: ");
    scanf_s("%s", newEntry.name, sizeof(newEntry.name));

    printf("������� �������: ");
    scanf_s("%s", newEntry.phone, sizeof(newEntry.phone));
    
    entries[*entryCount] = newEntry;
    (*entryCount)++;

    printf("������ ������� ���������.\n");
}

void printEntries(PhoneBookEntry* entries, int entryCount)
{
    if (entryCount == 0)
    {
        printf("���� ������� �����.\n");
        return;
    }
    
    printf("������ �������:\n");
    for (int i = 0; i < entryCount; i++)
    {
        printf("���: %s, �������: %s\n", entries[i].name, entries[i].phone);
    }
}

void findPhoneByName(PhoneBookEntry* entries, int entryCount)
{
    if (entryCount == 0)
    {
        printf("���������� �����\n");
        return;
    }

    char name[50];
    printf("������� ���: ");
    scanf_s("%s", name);

    for (int i = 0; i < entryCount; ++i)
    {
        if (strcmp(entries[i].name, name) == 0)
        {
            printf("�������: %s\n", entries[i].phone);
            return;
        }
    }

    printf("������ � ��������� ������ �� �������\n");
}

void findNameByPhone(PhoneBookEntry* entries, int entryCount) {
    if (entryCount == 0) {
        printf("���� ������� �����\n");
        return;
    }

    char phone[20];
    printf("������� �������: ");
    scanf_s("%s", phone);

    for (int i = 0; i < entryCount; i++) {
        if (strcmp(entries[i].phone, phone) == 0) {
            printf("���: %s\n", entries[i].name);
            return;
        }
    }

    printf("������ � ��������� ��������� �� �������.\n");
}

void saveToFile(PhoneBookEntry* entries, int entryCount)
{
    FILE* file = fopen_s(&file, "phonebook.txt", "w");
    
    if (file == NULL)
    {
        printf("������ ������ �����\n");
        return;
    }

    if (entryCount == 0)
    {
        printf("���� ������\n");
    }

    for (int i = 0; i < entryCount; ++i)
    {
        fprintf_s(file, "%s %s\n", entries[i].name, entries[i].phone);
    }

    fclose(file);

    printf("��� � ����� ���������\n");
}