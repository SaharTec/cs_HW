#include "matrixutils.h"
#include <iostream>
using namespace std;

int main() {
    int n;
    
    // קלט: גודל המטריצה (n x n)
    cout << "Enter matrix size (n for n x n matrix): ";
    cin >> n;
    
    // הקצאת זיכרון למטריצה
    int** matrix = allocateMatrix(n);
    
    // קלט: ערכי המטריצה
    cout << "Enter matrix elements (row by row):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // הדפסת המטריצה המקורית
    cout << "\nOriginal matrix:" << endl;
    printMatrix(matrix, n);
    
    // החלפת האלכסונים במקום
    swapDiagonalsInPlace(matrix, n);
    
    // הדפסת המטריצה לאחר החלפה
    cout << "\nAfter swapping diagonals (in-place):" << endl;
    printMatrix(matrix, n);
    
    // שחרור זיכרון
    freeMatrix(matrix, n);
    
    return 0;
}