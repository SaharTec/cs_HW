#include "assignutils.h"

int main(int argc, char* argv[]) {

    ////////////////////////// MAIN FOR QUESTION 1 //////////////////////////

    cout << "================== Question 1 ==================\n" << endl;

    const char* text1 = "hello";
    const char* text2 = "Beer Sheva";

    char* result1 = duplicateVowels(text1);
    char* result2 = duplicateVowels(text2);

    cout << "Original: " << text1 << " -> Modified: " << result1 << endl;
    cout << "Original: " << text2 << " -> Modified: " << result2 << endl;

    delete[] result1;
    delete[] result2;


    ////////////////////////// MAIN FOR QUESTION 2 //////////////////////////

    cout << "================== Question 2 ==================\n" << endl;

    int originalArr[] = {5, 12, 3, 20, 7, 1};
    int size = sizeof(originalArr) / sizeof(originalArr[0]);
    int threshold = 6;
    int newSize = 0;

    int* filtered = filterAboveThreshold(originalArr, size, threshold, newSize);
    printArray(originalArr, size);

    cout << "Filtered array (greater than " << threshold << "): ";
    printArray(filtered, newSize);
    cout << "newSize: " << newSize << endl;

    delete[] filtered;

}