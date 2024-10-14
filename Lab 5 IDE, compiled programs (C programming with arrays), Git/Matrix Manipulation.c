#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Function to add two matrices and store the result in a third matrix
int addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Error handling for invalid dimensions
    if (SIZE <= 0) {
        printf("Error: Invalid matrix dimensions for addition.\n");
        return -1;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return 0;
}

// Function to multiply two matrices and store the result in a third matrix
int multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Error handling for incompatible dimensions
    if (SIZE <= 0) {
        printf("Error: Invalid matrix dimensions for multiplication.\n");
        return -1;
    }
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return 0;
}

// Function to find the transpose of a matrix and store it in a result matrix
int transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Error handling for invalid dimensions
    if (SIZE <= 0) {
        printf("Error: Invalid matrix dimensions for transpose.\n");
        return -1;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return 0;
}

// Function to print a matrix in a user-friendly format
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define two matrices with sample values
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int result[SIZE][SIZE];

    // Add matrices
    printf("Sum of matrices:\n");
    if (addMatrices(m1, m2, result) == 0) {
        printMatrix(result);
    }

    // Multiply matrices
    printf("Product of matrices:\n");
    if (multiplyMatrices(m1, m2, result) == 0) {
        printMatrix(result);
    }

    // Transpose of m1
    printf("Transpose of first matrix:\n");
    if (transposeMatrix(m1, result) == 0) {
        printMatrix(result);
    }

    return 0;
}