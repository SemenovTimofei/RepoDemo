#pragma once

#include "list.h"

// splits list into two parts
void splitList(Node* list, Node** left, Node** right);

// merges two parts into one
Node* mergeList(Node* left, Node* right, const int sortBy);

// sorts the list
ListErrorCode mergeSort(Node** list, const int sortBy);