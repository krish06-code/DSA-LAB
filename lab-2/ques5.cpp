#include <iostream>
using namespace std;

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Diagonal elements: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;

    cout << "Lower triangular: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i > j) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;

    cout << "Upper triangular: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i < j) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;

    cout << "Tridiagonal: ";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j || i == j - 1 || i == j + 1) {
                cout << arr[i][j] << " ";
            }
        }
    }
    cout << endl;
 
    bool symmetric = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] != arr[j][i]) {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) break;
    }

    if (symmetric)
        cout << "Matrix is Symmetric" << endl;
    else
        cout << "Matrix is NOT Symmetric" << endl;

    return 0;
}
