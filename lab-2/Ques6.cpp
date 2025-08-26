#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, terms;
    Element data[100];  // store non-zero values as triplets
};

// Convert normal 2D matrix to sparse matrix
SparseMatrix createSparse(int mat[10][10], int rows, int cols) {
    SparseMatrix s;
    s.rows = rows;
    s.cols = cols;
    s.terms = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                s.data[s.terms].row = i;
                s.data[s.terms].col = j;
                s.data[s.terms].val = mat[i][j];
                s.terms++;
            }
        }
    }
    return s;
}

// Print sparse matrix triplets
void printMatrix(const SparseMatrix &m) {
    cout << "\nRow Col Val\n";
    for (int i = 0; i < m.terms; i++) {
        cout << m.data[i].row << "   " << m.data[i].col << "   " << m.data[i].val << endl;
    }
}

// Transpose of sparse matrix
SparseMatrix transpose(const SparseMatrix &m) {
    SparseMatrix t;
    t.rows = m.cols;
    t.cols = m.rows;
    t.terms = m.terms;

    int k = 0;
    for (int c = 0; c < m.cols; c++) {
        for (int i = 0; i < m.terms; i++) {
            if (m.data[i].col == c) {
                t.data[k].row = m.data[i].col;
                t.data[k].col = m.data[i].row;
                t.data[k].val = m.data[i].val;
                k++;
            }
        }
    }
    return t;
}

// Addition of two sparse matrices
SparseMatrix add(const SparseMatrix &a, const SparseMatrix &b) {
    SparseMatrix sum;
    if (a.rows != b.rows || a.cols != b.cols) {
        cout << "Matrices cannot be added!\n";
        sum.terms = 0;
        return sum;
    }

    sum.rows = a.rows;
    sum.cols = a.cols;
    int i = 0, j = 0, k = 0;

    while (i < a.terms && j < b.terms) {
        if (a.data[i].row < b.data[j].row ||
            (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[k++] = a.data[i++];
        }
        else if (b.data[j].row < a.data[i].row ||
                 (b.data[j].row == a.data[i].row && b.data[j].col < a.data[i].col)) {
            sum.data[k++] = b.data[j++];
        }
        else { // same row and col
            sum.data[k] = a.data[i];
            sum.data[k++].val = a.data[i++].val + b.data[j++].val;
        }
    }
    while (i < a.terms) sum.data[k++] = a.data[i++];
    while (j < b.terms) sum.data[k++] = b.data[j++];

    sum.terms = k;
    return sum;
}

// Multiplication of two sparse matrices
SparseMatrix multiply(const SparseMatrix &a, const SparseMatrix &b) {
    SparseMatrix prod;
    if (a.cols != b.rows) {
        cout << "Matrices cannot be multiplied!\n";
        prod.terms = 0;
        return prod;
    }

    prod.rows = a.rows;
    prod.cols = b.cols;
    prod.terms = 0;

    SparseMatrix bt = transpose(b); // easier multiplication

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < bt.rows; j++) {
            int sum = 0;
            for (int x = 0; x < a.terms; x++) {
                if (a.data[x].row == i) {
                    for (int y = 0; y < bt.terms; y++) {
                        if (bt.data[y].row == j && a.data[x].col == bt.data[y].col) {
                            sum += a.data[x].val * bt.data[y].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                prod.data[prod.terms].row = i;
                prod.data[prod.terms].col = j;
                prod.data[prod.terms].val = sum;
                prod.terms++;
            }
        }
    }
    return prod;
}

// Main driver
int main() {
    int mat1[10][10] = {
        {0, 0, 3},
        {4, 0, 0},
        {0, 5, 0}
    };

    int mat2[10][10] = {
        {0, 2, 0},
        {0, 0, 6},
        {7, 0, 0}
    };

    // Convert to sparse form
    SparseMatrix s1 = createSparse(mat1, 3, 3);
    SparseMatrix s2 = createSparse(mat2, 3, 3);

    cout << "\nFirst Matrix in Sparse form:";
    printMatrix(s1);

    cout << "\nSecond Matrix in Sparse form:";
    printMatrix(s2);

    // Transpose
    cout << "\nTranspose of First Matrix:";
    SparseMatrix t = transpose(s1);
    printMatrix(t);

    // Addition
    cout << "\nAddition of Matrices:";
    SparseMatrix s = add(s1, s2);
    printMatrix(s);

    // Multiplication
    cout << "\nMultiplication of Matrices:";
    SparseMatrix p = multiply(s1, s2);
    printMatrix(p);

    return 0;
}
