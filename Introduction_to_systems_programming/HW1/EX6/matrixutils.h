#ifndef MATRIXUTILS_H
#define MATRIXUTILS_H

int** allocateMatrix(int n);

void freeMatrix(int** a, int n);

void fillSequential(int** a, int n);

void printMatrix(int** a, int n);

void swapDiagonalsInPlace(int** a, int n);

#endif