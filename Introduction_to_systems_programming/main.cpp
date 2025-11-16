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

    ////////////////////////// MAIN FOR QUESTION 3 //////////////////////////

    cout << "================== Question 3 ==================\n" << endl;

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <n>" << endl;
        return 1;
    }

    int n = stoi(argv[1]);
    if (n <= 0) {
        cerr << "Error: n must be positive." << endl;
        return 1;
    }

    vector<int> arr(n);
    readVector(arr);
    modifyVector(arr);

    ////////////////////////// MAIN FOR QUESTION 4 //////////////////////////

    cout << "================== Question 4 ==================\n" << endl;

    const int MAX_LENGTH = 1000;
    char input[MAX_LENGTH];

    cout << "Enter a string: ";
    cin.ignore();
    cin.getline(input, MAX_LENGTH);

    reverseAndCapitalize(input);

    cout << "Modified string: " << input << endl;

    return 0;
}