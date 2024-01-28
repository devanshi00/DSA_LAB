#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <iomanip>  // Include for setw
#include <cstdlib>
#include <ctime>
using namespace std;

int **matrix_allocate(int row, int column) {
    int **matrix = new int *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new int[column]();
    }
    return matrix;
}

void matrix_free(int **matrix, int row) {
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void matrix_print_to_file(const char *str, int **a, int row, ofstream &outputFile) {
    int min, max, w = 0, n1, n2, nw;
    min = max = a[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            if (min > a[i][j])
                min = a[i][j];
            if (max < a[i][j])
                max = a[i][j];
        }
    }
    n1 = snprintf(NULL, 0, "%d", min);
    n2 = snprintf(NULL, 0, "%d", max);
    nw = n1 > n2 ? n1 : n2;

    for (int i = 0; i < row; i++) {
        if (i == 0)
            outputFile << str << " = ";
        else
            outputFile << setw(w) << "";

        for (int j = 0; j < row; j++) {
            outputFile << " " << setw(nw) << a[i][j];
        }
        outputFile << endl;
    }
    outputFile << flush;
}


int **matrix_add(int **a, int **b, int row, int deallocate) {
    int **c = matrix_allocate(row, row);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    if (deallocate & 1)
        matrix_free(a, row);
    if (deallocate & 2)
        matrix_free(b, row);

    return c;
}

int **matrix_multiply(int **A, int **B, int row, int deallocate) {
    int **C = matrix_allocate(row, row);
    if (row == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int row2 = row / 2;
        int **a11 = matrix_allocate(row2, row2);
        int **a12 = matrix_allocate(row2, row2);
        int **a21 = matrix_allocate(row2, row2);
        int **a22 = matrix_allocate(row2, row2);
        int **b11 = matrix_allocate(row2, row2);
        int **b12 = matrix_allocate(row2, row2);
        int **b21 = matrix_allocate(row2, row2);
        int **b22 = matrix_allocate(row2, row2);

        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < row2; j++) {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + row2];
                a21[i][j] = A[i + row2][j];
                a22[i][j] = A[i + row2][j + row2];
                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + row2];
                b21[i][j] = B[i + row2][j];
                b22[i][j] = B[i + row2][j + row2];
            }
        }

        int **c11 = matrix_add(matrix_multiply(a11, b11, row2, 0),
                               matrix_multiply(a12, b21, row2, 0), row2, 1 + 2);
        int **c12 = matrix_add(matrix_multiply(a11, b12, row2, 1),
                               matrix_multiply(a12, b22, row2, 1), row2, 1 + 2);
        int **c21 = matrix_add(matrix_multiply(a21, b11, row2, 2),
                               matrix_multiply(a22, b21, row2, 2), row2, 1 + 2);
        int **c22 = matrix_add(matrix_multiply(a21, b12, row2, 1 + 2),
                               matrix_multiply(a22, b22, row2, 1 + 2), row2, 1 + 2);

        for (int i = 0; i < row2; i++) {
            for (int j = 0; j < row2; j++) {
                C[i][j] = c11[i][j];
                C[i][j + row2] = c12[i][j];
                C[i + row2][j] = c21[i][j];
                C[i + row2][j + row2] = c22[i][j];
            }
        }
        matrix_free(c11, row2);
        matrix_free(c12, row2);
        matrix_free(c21, row2);
        matrix_free(c22, row2);
    }
    if (deallocate & 1)
        matrix_free(A, row);
    if (deallocate & 2)
        matrix_free(B, row);

    return C;
}


int main() {
    freopen("test_cases_Q1_matrix.txt", "r", stdin); 
    ofstream outputFile("output_Q1_matrix.txt");  // Open the output file

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int **A = matrix_allocate(n, n);
        int **B = matrix_allocate(n, n);

        // Read matrix A
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> A[i][j];

        // Read matrix B
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> B[i][j];

        fclose(stdin);  // Close the file redirection

        matrix_print_to_file("A", A, n, outputFile);
        matrix_print_to_file("B", B, n, outputFile);

        if ((n & (n - 1)) == 0) {
            /* recursive method can be applied only to powers of 2 */
            clock_t ticks = -clock();
            int **C = matrix_multiply(A, B, n, 0);
            ticks += clock();
            matrix_print_to_file("C = A * B", C, n, outputFile);
            outputFile << ticks << " ticks" << endl;
            matrix_free(C, n);
        }

        matrix_free(A, n);
        matrix_free(B, n);
    }

    outputFile.close();  // Close the output file

    return 0;
}