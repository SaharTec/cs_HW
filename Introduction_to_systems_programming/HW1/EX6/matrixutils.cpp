#include "matrixutils.h"
#include <iostream>
using namespace std;

int** allocateMatrix(int rows){
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[rows];
    }return matrix;
}

void freeMatrix(int** matrix, int rows){
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
    }delete [] matrix;
}

void fillSequential(int** matrix, int row, int cul){
    int val = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < cul; j++){
            matrix[i][j] = val++;
        }
    }
}

void printMatrix(int** matrix, int row){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            cout << matrix[i][j];
            if(j < row  -1) cout << ",";
        }cout << endl;
    }
}

void swapDiagonalsInPlace(int** matrix, int n){
     for(int i = 0; i < n; i++){
        int swap = matrix[i][i];
        matrix[i][i] = matrix[i][n - i - 1];
        matrix[i][n - i - 1] = swap;
     }
}