#ifndef ASSIGNUTILS_H
#define ASSIGNUTILS_H

#include <iostream>
#include <vector>
using namespace std;

// QUESTION 1:
char* duplicateVowels(const char* str);

// QUESTION 2:
int* filterAboveThreshold(const int* arr, int size, int threshold, int& newSize);
void printArray(const int* arr, int size);

// QUESION 3:
void readVector(vector<int>& vec);
void modifyVector(vector<int>& arr);

// QUESTION 4:
void reverseAndCapitalize(char* st);

#endif